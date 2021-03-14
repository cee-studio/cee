#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <pthread.h>

#include "websockets.h"
#include "orka-utils.h"


static void
cws_on_connect_cb(void *p_ws, CURL *ehandle, const char *ws_protocols)
{
  struct websockets_s *ws = p_ws;
  pthread_mutex_lock(&ws->lock);
  (*ws->cbs.on_connect)(ws->cbs.data, ws_protocols);
  pthread_mutex_unlock(&ws->lock);
}

static void
cws_on_close_cb(void *p_ws, CURL *ehandle, enum cws_close_reason cwscode, const char *reason, size_t len)
{
  struct websockets_s *ws = p_ws;
  pthread_mutex_lock(&ws->lock);
  (*ws->cbs.on_close)(ws->cbs.data, cwscode, reason, len);
  pthread_mutex_unlock(&ws->lock);
  (void)ehandle;
}

struct _event_cxt {
  struct websockets_s *ws; // the websockets client
  struct event_cbs *event; // callback associated with event
  struct worker_thread *wthread; // thread associated with event
};

static void*
event_run(void *p_cxt)
{
  struct _event_cxt *cxt = p_cxt;

  pthread_mutex_lock(&cxt->ws->lock); //@todo special lock for events ?
  (*cxt->event->cb)(cxt->ws->cbs.data);

  ++cxt->ws->num_notbusy;
  cxt->wthread->is_busy = 0;
  pthread_cond_signal(&cxt->ws->cond);

  pthread_mutex_unlock(&cxt->ws->lock);

  free(cxt);

  return NULL;
}

static void
cws_on_text_cb(void *p_ws, CURL *ehandle, const char *text, size_t len)
{
  struct websockets_s *ws = p_ws;

  pthread_mutex_lock(&ws->lock);

  int event_code = (*ws->cbs.on_text_event)(ws->cbs.data, text, len);
  for (size_t i=0; i < ws->cbs.num_events; ++i) {
    if (event_code != ws->cbs.on_event[i].code) 
      continue;

    (*ws->config.json_cb)(
      true,
      event_code, "ON_EVENT",
      &ws->config, 
      ws->base_url, 
      (char*)text);

    // wait until a thread is available before proceeding
    while (!ws->num_notbusy) {
      pthread_cond_wait(&ws->cond, &ws->lock);
    }

    struct _event_cxt *cxt = calloc(1, sizeof(struct _event_cxt));
    cxt->ws = ws;
    cxt->event = &ws->cbs.on_event[i];

    // get available thread
    for (size_t i=0; i < MAX_THREADS; ++i) {
      if (!ws->wthreads[i].is_busy) {
        cxt->wthread = &ws->wthreads[i];
        cxt->wthread->is_busy = 1;
        --ws->num_notbusy;
        break; /* EARLY BREAK */
      }
    }
    ASSERT_S(NULL != cxt->wthread, "Internal thread synchronization error (couldn't fetch thread)");

    if (pthread_create(&cxt->wthread->tid, NULL, &event_run, cxt))
      ERR("Couldn't create thread");
    if (pthread_detach(cxt->wthread->tid))
      ERR("Couldn't detach thread");

    pthread_mutex_unlock(&ws->lock);
    return; /* EARLY RETURN */
  }
  (*ws->config.json_cb)(
    false,
    0, "ON_TEXT",
    &ws->config, 
    ws->base_url, 
    (char*)text);

  (*ws->cbs.on_text)(ws->cbs.data, text, len);

  pthread_mutex_unlock(&ws->lock);
}

static void
cws_on_binary_cb(void *p_ws, CURL *ehandle, const void *mem, size_t len)
{
  struct websockets_s *ws = p_ws;
  pthread_mutex_lock(&ws->lock);
  (*ws->cbs.on_binary)(ws->cbs.data, mem, len);
  pthread_mutex_unlock(&ws->lock);
  (void)ehandle;
}

static void
cws_on_ping_cb(void *p_ws, CURL *ehandle, const char *reason, size_t len)
{
  struct websockets_s *ws = p_ws;
  pthread_mutex_lock(&ws->lock);
  (*ws->cbs.on_ping)(ws->cbs.data, reason, len);
  pthread_mutex_unlock(&ws->lock);
  (void)ehandle;
}

static void
cws_on_pong_cb(void *p_ws, CURL *ehandle, const char *reason, size_t len)
{
  struct websockets_s *ws = p_ws;
  pthread_mutex_lock(&ws->lock);
  (*ws->cbs.on_pong)(ws->cbs.data, reason, len);
  pthread_mutex_unlock(&ws->lock);
  (void)ehandle;
}

/* init easy handle with some default opt */
static CURL*
custom_cws_new(struct websockets_s *ws)
{
  struct cws_callbacks cws_cbs = {0};
  cws_cbs.on_connect = &cws_on_connect_cb;
  cws_cbs.on_text = &cws_on_text_cb;
  cws_cbs.on_binary = &cws_on_binary_cb;
  cws_cbs.on_ping = &cws_on_pong_cb;
  cws_cbs.on_pong = &cws_on_pong_cb;
  cws_cbs.on_close = &cws_on_close_cb;
  cws_cbs.data = ws;

  CURL *new_ehandle = cws_new(ws->base_url, NULL, &cws_cbs);
  ASSERT_S(NULL != new_ehandle, "Out of memory");

  CURLcode ecode;
  //enable follow redirections
  ecode = curl_easy_setopt(new_ehandle, CURLOPT_FOLLOWLOCATION, 2L);
  ASSERT_S(CURLE_OK == ecode, curl_easy_strerror(ecode));

/* @todo
  // execute user-defined curl_easy_setopts
  if (ws->setopt_cb) {
    (*ws->setopt_cb)(new_ehandle, ws->cbs.data);
  }
*/

  return new_ehandle;
}

static int noop_on_startup(void *a){return 1;}
static void noop_on_iter_end(void *a){return;}
static int noop_on_text_event(void *a, const char *b, size_t c)
{return INT_MIN;} // return unlikely event value as default

static void noop_on_connect(void *a, const char *b){return;}
static void noop_on_text(void *a, const char *b, size_t c){return;}
static void noop_on_binary(void *a, const void *b, size_t c){return;}
static void noop_on_ping(void *a, const char *b, size_t c){return;}
static void noop_on_pong(void *a, const char *b, size_t c){return;}
static void noop_on_close(void *a, enum cws_close_reason b, const char *c, size_t d){return;}

void
ws_init(
  struct websockets_s *ws, 
  const char base_url[], 
  struct ws_callbacks *cbs)
{
  memset(ws, 0, sizeof(struct websockets_s));
  ws->base_url = strdup(base_url);

  ws->status = WS_DISCONNECTED;
  ws->reconnect.threshold = 5;
  ws->wait_ms = 100;

  ws->ehandle = custom_cws_new(ws);
  ws->mhandle = curl_multi_init();

  orka_config_init(&ws->config, NULL, NULL);

  ws->num_notbusy = MAX_THREADS;

  memcpy(&ws->cbs, cbs, sizeof(struct ws_callbacks));
  if (!ws->cbs.on_startup) ws->cbs.on_startup = &noop_on_startup;
  if (!ws->cbs.on_iter_end) ws->cbs.on_iter_end = &noop_on_iter_end;
  if (!ws->cbs.on_text_event) ws->cbs.on_text_event = &noop_on_text_event;
  if (!ws->cbs.on_connect) ws->cbs.on_connect = &noop_on_connect;
  if (!ws->cbs.on_text) ws->cbs.on_text = &noop_on_text;
  if (!ws->cbs.on_binary) ws->cbs.on_binary = &noop_on_binary;
  if (!ws->cbs.on_ping) ws->cbs.on_ping = &noop_on_ping;
  if (!ws->cbs.on_pong) ws->cbs.on_pong = &noop_on_pong;
  if (!ws->cbs.on_close) ws->cbs.on_close = &noop_on_close;

  if (pthread_mutex_init(&ws->lock, NULL))
    ERR("Couldn't initialize pthread mutex");
  if (pthread_mutex_init(&ws->wthreads_lock, NULL))
    ERR("Couldn't initialize pthread mutex");
  if (pthread_cond_init(&ws->cond, NULL))
    ERR("Couldn't initialize pthread cond");
}

void
ws_config_init(
  struct websockets_s *ws, 
  const char base_url[], 
  struct ws_callbacks *cbs,
  const char tag[], 
  const char config_file[]) 
{
  ws_init(ws, base_url, cbs);
  orka_config_init(&ws->config, tag, config_file);
}

void
ws_cleanup(struct websockets_s *ws)
{
  if (ws->cbs.on_event)
    free(ws->cbs.on_event);
  free(ws->base_url);
  curl_multi_cleanup(ws->mhandle);
  cws_free(ws->ehandle);
  orka_config_cleanup(&ws->config);
  pthread_mutex_destroy(&ws->lock);
  pthread_mutex_destroy(&ws->wthreads_lock);
  pthread_cond_destroy(&ws->cond);
}

static void
event_loop(struct websockets_s *ws)
{
  curl_multi_add_handle(ws->mhandle, ws->ehandle);

  if ( !(*ws->cbs.on_startup)(ws->cbs.data) ) {
    ws_set_status(ws, WS_DISCONNECTED);
    return; /* EARLY RETURN */
  }

  // kickstart a connection then enter loop
  CURLMcode mcode;
  int is_running = 0;
  mcode = curl_multi_perform(ws->mhandle, &is_running);
  ASSERT_S(CURLM_OK == mcode, curl_multi_strerror(mcode));

  do {
    int numfds;

    pthread_mutex_lock(&ws->wthreads_lock);
    ws->now_tstamp = orka_timestamp_ms(); //update our concept of now
    pthread_mutex_unlock(&ws->wthreads_lock);

    mcode = curl_multi_perform(ws->mhandle, &is_running);
    ASSERT_S(CURLM_OK == mcode, curl_multi_strerror(mcode));

    // wait for activity or timeout
    mcode = curl_multi_wait(ws->mhandle, NULL, 0, ws->wait_ms, &numfds);
    ASSERT_S(CURLM_OK == mcode, curl_multi_strerror(mcode));

    if (ws_get_status(ws) == WS_CONNECTED) { // run if connection established
      pthread_mutex_lock(&ws->lock);
      (*ws->cbs.on_iter_end)(ws->cbs.data);
      pthread_mutex_unlock(&ws->lock);
    }
  } while(is_running);

  curl_multi_remove_handle(ws->mhandle, ws->ehandle);
}

void
ws_close(
  struct websockets_s *ws, 
  enum cws_close_reason cwscode, 
  const char reason[], 
  size_t len)
{
  //@todo add pthread_join() here
  cws_close(ws->ehandle, cwscode, reason, len);
}

void
ws_send_text(struct websockets_s *ws, char text[])
{
  pthread_mutex_lock(&ws->wthreads_lock);
  (*ws->config.json_cb)(
    false, 
    0, "SEND", 
    &ws->config, 
    ws->base_url, 
    text);

  bool ret = cws_send_text(ws->ehandle, text);
  if (false == ret) PRINT("Couldn't send websockets payload");
  pthread_mutex_unlock(&ws->wthreads_lock);
}

uint64_t
ws_timestamp(struct websockets_s *ws) 
{
  pthread_mutex_lock(&ws->wthreads_lock);
  uint64_t now_tstamp = ws->now_tstamp;
  pthread_mutex_unlock(&ws->wthreads_lock);
  return now_tstamp;
}

enum ws_status
ws_get_status(struct websockets_s *ws) 
{
  pthread_mutex_lock(&ws->wthreads_lock);
  enum ws_status status = ws->status;
  pthread_mutex_unlock(&ws->wthreads_lock);
  return status;
}

void
ws_set_status(struct websockets_s *ws, enum ws_status status) 
{
  pthread_mutex_lock(&ws->wthreads_lock);
  if (status == WS_CONNECTED) {
    ws->reconnect.attempt = 0;
  }
  ws->status = status;
  pthread_mutex_unlock(&ws->wthreads_lock);
}

void
ws_set_refresh_rate(struct websockets_s *ws, uint64_t wait_ms) 
{
  pthread_mutex_lock(&ws->wthreads_lock);
  ws->wait_ms = wait_ms;
  pthread_mutex_unlock(&ws->wthreads_lock);
}

void
ws_set_max_reconnect(struct websockets_s *ws, int max_attempts) 
{
  pthread_mutex_lock(&ws->wthreads_lock);
  ws->reconnect.threshold = max_attempts;
  pthread_mutex_unlock(&ws->wthreads_lock);
}

void
ws_set_event(
  struct websockets_s *ws, 
  int event_code, 
  void (*user_cb)(void *data))
{
  ASSERT_S(WS_DISCONNECTED == ws_get_status(ws), "Can't set event on a running client");

  ++ws->cbs.num_events;
  ws->cbs.on_event = realloc(ws->cbs.on_event, 
                      ws->cbs.num_events * sizeof(struct event_cbs));

  memset(&ws->cbs.on_event[ws->cbs.num_events-1], 0, sizeof(struct event_cbs));
  ws->cbs.on_event[ws->cbs.num_events-1].code = event_code;
  ws->cbs.on_event[ws->cbs.num_events-1].cb = user_cb;
}

static enum ws_status
attempt_reconnect(struct websockets_s *ws)
{
  switch (ws->status) {
  default:
      if (ws->reconnect.attempt < ws->reconnect.threshold)
        break;

      PRINT("Failed all reconnect attempts (%d)", ws->reconnect.attempt);
      ws->status = WS_DISCONNECTED;
  /* fall through */
  case WS_DISCONNECTED:
      return ws->status; /* WS_DISCONNECTED */
  }

  /* force reset */
  cws_free(ws->ehandle);
  ws->ehandle = custom_cws_new(ws);

  ++ws->reconnect.attempt;

  return ws->status; /* WS_CONNECTED || WS_RESUME || WS_FRESH */
}

/* connects to the websockets server */
void
ws_run(struct websockets_s *ws)
{
  ASSERT_S(WS_DISCONNECTED == ws_get_status(ws), 
      "Failed attempt to run websockets recursively");

  while (1) {
    event_loop(ws);
    if (WS_DISCONNECTED == attempt_reconnect(ws))
      break; /* EXIT LOOP */
  }
}
