#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "libdiscord.h"
#include "orka-utils.h"

#define BASE_API_URL "https://discord.com/api"


struct _ratelimit {
  struct discord_adapter *adapter;
  struct discord_bucket *bucket;
  char *endpoint;
};

void
discord_adapter_init(struct discord_adapter *adapter, const char token[], const char config_file[])
{
  if (config_file) {
    ua_config_init(&adapter->ua, BASE_API_URL, "DISCORD HTTP", config_file);
    token = orka_config_get_field(&adapter->ua.config, "discord.token");
  }
  else {
    ua_init(&adapter->ua, BASE_API_URL);
    orka_config_init(&adapter->ua.config, "DISCORD HTTP", NULL);
  }
  if (!token) ERR("Missing bot token");

  char auth[128];
  int ret = snprintf(auth, sizeof(auth), "Bot %s", token);
  ASSERT_S(ret < (int)sizeof(auth), "Out of bounds write attempt");

  ua_reqheader_add(&adapter->ua, "Authorization", auth);
  ua_reqheader_add(&adapter->ua, "X-RateLimit-Precision", "millisecond");

  if (pthread_mutex_init(&adapter->lock, NULL))
    ERR("Couldn't initialize pthread mutex");
}

void
discord_adapter_cleanup(struct discord_adapter *adapter)
{
  discord_bucket_cleanup(adapter);
  ua_cleanup(&adapter->ua);
  pthread_mutex_destroy(&adapter->lock);
}

static int
bucket_tryget_cb(void *p_ratelimit)
{
  struct _ratelimit *rl = (struct _ratelimit*)p_ratelimit;
  pthread_mutex_lock(&rl->adapter->lock);
  rl->bucket = discord_bucket_try_get(rl->adapter, rl->endpoint);
  pthread_mutex_unlock(&rl->adapter->lock);
  return 1;
}

static void
bucket_trycooldown_cb(void *p_ratelimit)
{
  struct _ratelimit *rl = (struct _ratelimit*)p_ratelimit;
  discord_bucket_try_cooldown(rl->bucket);
}

static void
bucket_trybuild_cb(void *p_ratelimit, struct ua_conn_s *conn)
{
  struct _ratelimit *rl = (struct _ratelimit*)p_ratelimit;
  pthread_mutex_lock(&rl->adapter->lock);
  discord_bucket_build(rl->adapter, rl->bucket, rl->endpoint, conn);
  pthread_mutex_unlock(&rl->adapter->lock);
}

static ua_status_t
on_success_cb(
  void *p_ratelimit,
  int httpcode,
  struct ua_conn_s *conn)
{
  DS_NOTOP_PRINT("(%d)%s - %s", 
      httpcode,
      http_code_print(httpcode),
      http_reason_print(httpcode));

  return UA_SUCCESS;
}

static ua_status_t
on_failure_cb(
  void *p_ratelimit,
  int httpcode,
  struct ua_conn_s *conn)
{
  struct _ratelimit *rl = (struct _ratelimit*)p_ratelimit;

  if (httpcode >= 500) { // server related error, retry
    NOTOP_PRINT("(%d)%s - %s", 
        httpcode,
        http_code_print(httpcode),
        http_reason_print(httpcode));

    ua_block_ms(&rl->adapter->ua, 5000); // wait for 5 seconds

    return UA_RETRY;
  }

  switch (httpcode) {
  case HTTP_FORBIDDEN:
  case HTTP_NOT_FOUND:
  case HTTP_BAD_REQUEST:
      NOTOP_PRINT("(%d)%s - %s",  //print error and continue
          httpcode,
          http_code_print(httpcode),
          http_reason_print(httpcode));

      return UA_FAILURE;
  case HTTP_UNAUTHORIZED:
  case HTTP_METHOD_NOT_ALLOWED:
  default:
      NOTOP_PRINT("(%d)%s - %s",  //print error and abort
          httpcode,
          http_code_print(httpcode),
          http_reason_print(httpcode));

      return UA_ABORT;
  case HTTP_TOO_MANY_REQUESTS:
   {
      NOTOP_PRINT("(%d)%s - %s", 
          httpcode,
          http_code_print(httpcode),
          http_reason_print(httpcode));

      char message[256];
      long long retry_after_ms = 0;

      json_scanf(conn->resp_body.start, conn->resp_body.size,
                  "[message]%s [retry_after]%lld",
                  message, &retry_after_ms);

      if (retry_after_ms) { // retry after attribute received
        NOTOP_PRINT("RATELIMIT MESSAGE:\n\t%s (wait: %lld ms)", message, retry_after_ms);

        ua_block_ms(&rl->adapter->ua, retry_after_ms);

        return UA_RETRY;
      }
      
      // no retry after included, we should abort

      NOTOP_PRINT("RATELIMIT MESSAGE:\n\t%s", message);
      return UA_ABORT;
   }
  }
}

static void
json_error_cb(char *str, size_t len, void *p_err)
{
  /* JSON ERROR CODES
  https://discord.com/developers/docs/topics/opcodes-and-status-codes#json-json-error-codes */
  int code = 0; //last error code received
  char message[256] = {0}; //meaning of the error received

  json_scanf(str, len, "[message]%s [code]%d", message, &code);

  NOTOP_PRINT("Error Description:\n\t\t%s (code %d)"
      "- See Discord's JSON Error Codes", message, code);
}

/* template function for performing requests */
void
discord_adapter_run(
  struct discord_adapter *adapter, 
  struct resp_handle *resp_handle,
  struct sized_buffer *req_body,
  enum http_method http_method,
  char endpoint[],
  ...)
{
  va_list args;
  va_start(args, endpoint);

  struct _ratelimit ratelimit = {
    .adapter = adapter, 
    .endpoint = endpoint
  };

  struct ua_callbacks cbs = {
    .data = (void*)&ratelimit,
    .on_startup = &bucket_tryget_cb,
    .on_iter_start = &bucket_trycooldown_cb,
    .on_iter_end = &bucket_trybuild_cb,
    .on_1xx = NULL,
    .on_2xx = &on_success_cb,
    .on_3xx = &on_success_cb,
    .on_4xx = &on_failure_cb,
    .on_5xx = &on_failure_cb,
  };

  /* IF UNSET, SET TO DEFAULT ERROR HANDLING CALLBACKS */
  if (resp_handle && !resp_handle->err_cb) {
    resp_handle->err_cb = &json_error_cb;
    resp_handle->err_obj = NULL;
  }

  ua_vrun(
    &adapter->ua,
    resp_handle,
    req_body,
    &cbs,
    http_method, endpoint, args);

  va_end(args);
}
