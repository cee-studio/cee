#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libdiscord.h"
#include "discord-common.h"
#include "orka-utils.h"

void
discord_message_from_json(char *str, size_t len, struct discord_message *message)
{
  if (message->nonce) {
    free(message->nonce);
    message->nonce = NULL;
  }
  if (message->content) {
    free(message->content);
    message->content = NULL;
  }

  message->referenced_message = discord_message_alloc();

  json_scanf(str, len,
     "[id]%F"
     "[channel_id]%F"
     "[guild_id]%F"
     "[author]%F"
     "[member]%F"
     "[content]%?s"
     "[timestamp]%F"
     "[edited_timestamp]%F"
     "[tts]%b"
     "[mention_everyone]%b"
     //"[mentions]%F"
     "[nonce]%?s"
     "[pinned]%b"
     "[webhook_id]%F"
     "[type]%d"
     "[flags]%d"
     "[referenced_message]%F",
      &orka_strtoull, &message->id,
      &orka_strtoull, &message->channel_id,
      &orka_strtoull, &message->guild_id,
      &discord_user_from_json, message->author,
      &discord_guild_member_from_json, message->member,
      &message->content,
      &orka_iso8601_to_unix_ms, &message->timestamp,
      &orka_iso8601_to_unix_ms, &message->edited_timestamp,
      &message->tts,
      &message->mention_everyone,
      &message->nonce,
      &message->pinned,
      &orka_strtoull, &message->webhook_id,
      &message->type,
      &message->flags,
      &discord_message_from_json, message->referenced_message);

  if(!message->referenced_message->id) {
    discord_message_free(message->referenced_message);
    message->referenced_message = NULL;
  }

  DS_NOTOP_PUTS("Message object loaded with API response"); 
}

void discord_channel_overwrite_from_json(char *json, size_t len, struct discord_channel_overwrite *p)
{
  static size_t ret=0; //used for debugging
  size_t r=0;

  r=json_extract(json, len,
                 "(id):F,"
                 //"(type):s," @todo
                 //"(allow_new):s," @todo
                 "(allow):lld,"
                 //"(deny_new):s," @todo
                 "(deny):lld,"
                 "@arg_switches:b"
                 "@record_defined"
                 "@record_null",
                 orka_strtoull, &p->id,
                 //&p->type,
                 &p->allow,
                 &p->deny,
                 p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                 p->__M.record_defined, sizeof(p->__M.record_defined),
                 p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

size_t 
discord_channel_overwrite_to_json(char *json, size_t len, struct discord_channel_overwrite *p)
{
  size_t r;
  r=json_inject(json, len,
                "(id):|F|,"
                "(type):d,"
                "(allow):s_as_u64,"
                "(deny):s_as_u64,"
                "@arg_switches:b",
                orka_ulltostr, &p->id,
                &p->type,
                &p->allow,
                &p->deny,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}

void
discord_embed_set_footer(
  struct discord_channel_embed *embed, 
  char text[], 
  char icon_url[], 
  char proxy_icon_url[])
{
  if (IS_EMPTY_STRING(text)) {
    D_PUTS("Missing 'text'");
    return;
  }

  if (embed->footer) {
    free(embed->footer);
  }

  struct discord_channel_embed_footer *new_footer = discord_channel_embed_footer_alloc();
  strncpy(new_footer->text, text, EMBED_FOOTER_TEXT_LEN);
  if (!IS_EMPTY_STRING(icon_url))
    strncpy(new_footer->icon_url, icon_url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_icon_url))
    strncpy(new_footer->proxy_icon_url, proxy_icon_url, MAX_URL_LEN);

  embed->footer = new_footer;
}

void
discord_embed_set_thumbnail(
  struct discord_channel_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->thumbnail) {
    free(embed->thumbnail);
  }

  struct discord_channel_embed_thumbnail *new_thumbnail = discord_channel_embed_thumbnail_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_thumbnail->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_thumbnail->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_thumbnail->height = height;
  if (width)
    new_thumbnail->width = width;

  embed->thumbnail = new_thumbnail;
}

void
discord_embed_set_image(
  struct discord_channel_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->image) {
    free(embed->image);
  }

  struct discord_channel_embed_image *new_image = discord_channel_embed_image_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_image->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_image->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_image->height = height;
  if (width)
    new_image->width = width;

  embed->image = new_image;
}

void
discord_embed_set_video(
  struct discord_channel_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->video) {
    free(embed->video);
  }

  struct discord_channel_embed_video *new_video = discord_channel_embed_video_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_video->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_video->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_video->height = height;
  if (width)
    new_video->width = width;

  embed->video = new_video;
}

void
discord_embed_set_provider(struct discord_channel_embed *embed, char name[], char url[])
{
  if (embed->provider) {
    free(embed->provider);
  }

  struct discord_channel_embed_provider *new_provider = discord_channel_embed_provider_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_provider->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(name))
    strncpy(new_provider->name, name, EMBED_AUTHOR_NAME_LEN);

  embed->provider = new_provider;
}

void
discord_embed_set_author(
  struct discord_channel_embed *embed, 
  char name[], 
  char url[], 
  char icon_url[], 
  char proxy_icon_url[])
{
  if (embed->author) {
    free(embed->author);
  }

  struct discord_channel_embed_author *new_author = discord_channel_embed_author_alloc();
  if (!IS_EMPTY_STRING(name))
    strncpy(new_author->name, name, EMBED_AUTHOR_NAME_LEN);
  if (!IS_EMPTY_STRING(url))
    strncpy(new_author->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(icon_url))
    strncpy(new_author->icon_url, icon_url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_icon_url))
    strncpy(new_author->proxy_icon_url, proxy_icon_url, MAX_URL_LEN);

  embed->author = new_author;
}

void
discord_embed_add_field(struct discord_channel_embed *embed, char name[], char value[], bool Inline)
{
  if (IS_EMPTY_STRING(name)) {
    D_PUTS("Missing 'name'");
    return;
  }
  if (IS_EMPTY_STRING(value)) {
    D_PUTS("Missing 'value'");
    return;
  }
  if (embed->fields 
      && ntl_length((NTL_T(void))embed->fields) >= EMBED_MAX_FIELDS)
  {
    D_PRINT("Reach embed fields threshold (max %d)", EMBED_MAX_FIELDS);
    return;
  }

  struct discord_channel_embed_field new_field;
  discord_channel_embed_field_init(&new_field);
  strncpy(new_field.name, name, EMBED_FIELD_NAME_LEN);
  strncpy(new_field.value, value, EMBED_FIELD_VALUE_LEN);
  new_field.Inline = Inline;

  embed->fields = (NTL_T(struct discord_channel_embed_field))ntl_append(
                        (NTL_T(void))embed->fields, 
                        sizeof(struct discord_channel_embed_field), &new_field);
}

void
discord_overwrite_append(
  NTL_T(struct discord_channel_overwrite) *permission_overwrites, 
  u64_snowflake_t id, 
  int type, 
  enum discord_permissions_bitwise_flags allow, 
  enum discord_permissions_bitwise_flags deny)
{
  if (!id) {
    D_PUTS("Missing 'id'");
    return;
  }
  if ( !(0 == type || 1 == type) ) {
    D_PUTS("'type' should be 0 (role) or 1 (member)");
    return;
  }

  struct discord_channel_overwrite new_overwrite;
  discord_channel_overwrite_init(&new_overwrite);
  new_overwrite.id = id;
  new_overwrite.type = type;
  new_overwrite.allow = allow;
  new_overwrite.deny = deny;

  *permission_overwrites = (NTL_T(struct discord_channel_overwrite))ntl_append(
                            (NTL_T(void))*permission_overwrites, 
                            sizeof(struct discord_channel_overwrite), &new_overwrite);
}

void
discord_get_channel(struct discord *client, const u64_snowflake_t channel_id, struct discord_channel *p_channel)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id");
    return;
  }

  struct resp_handle resp_handle =
    { .ok_cb = &discord_channel_from_json_v, .ok_obj = (void*)p_channel};

  discord_adapter_run(
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET,
    "/channels/%llu", channel_id);
}

void
discord_delete_channel(struct discord *client, const u64_snowflake_t channel_id, struct discord_channel *p_channel)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id");
    return;
  }

  struct resp_handle resp_handle = {
    .ok_cb = p_channel ? discord_channel_from_json_v : NULL,
    .ok_obj = p_channel,
  };

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_DELETE,
    "/channels/%llu", channel_id);
}

void
discord_add_pinned_channel_message(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  const u64_snowflake_t message_id)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!message_id) {
    D_PUTS("Missing 'message_id'");
    return;
  }

  discord_adapter_run( 
    &client->adapter,
    NULL,
    NULL,
    HTTP_PUT, 
    "/channels/%llu/pins/%llu", channel_id, message_id);
}

void
discord_delete_pinned_channel_message(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  const u64_snowflake_t message_id)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!message_id) {
    D_PUTS("Missing 'message_id'");
    return;
  }

  discord_adapter_run( 
    &client->adapter,
    NULL,
    NULL,
    HTTP_DELETE,
    "/channels/%llu/pins/%llu", channel_id, message_id);
}

void
discord_get_channel_messages(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  struct discord_channel_get_channel_messages_params *params, 
  NTL_T(struct discord_message) *p_messages)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!params) {
    D_PUTS("Missing 'params'");
    return;
  }
  if (params->limit < 1 || params->limit > 100) {
    D_PUTS("'limit' value should be in an interval of (1-100)");
    return;
  }

  char limit_query[64];
  snprintf(limit_query, sizeof(limit_query),
      "?limit=%d", params->limit);

  char around_query[64] = "";
  if (params->around) {
    snprintf(around_query, sizeof(around_query),
        "&around=%" PRIu64 , params->around);
  }

  char before_query[64] = "";
  if (params->before) {
    snprintf(before_query, sizeof(before_query),
        "&before=%" PRIu64 , params->before);
  }

  char after_query[64] = "";
  if (params->after) {
    snprintf(after_query, sizeof(after_query),
        "&after=%" PRIu64 , params->after);
  }

  struct resp_handle resp_handle = 
    { .ok_cb = &discord_message_list_from_json_v, .ok_obj = (void*)p_messages};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/channels/%llu/messages%s%s%s", 
    channel_id, limit_query, around_query, before_query, after_query);
}

void
discord_delete_message(
  struct discord *client, 
  u64_snowflake_t channel_id, 
  u64_snowflake_t message_id)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!message_id) {
    D_PUTS("Missing 'message_id'");
    return;
  }
  discord_adapter_run(
    &client->adapter,
    NULL,
    NULL,
    HTTP_DELETE,
    "/channels/%llu/messages/%llu", channel_id, message_id);
}

//@todo this is a temporary solution
static curl_mime*
curl_mime_cb(CURL *ehandle, void *data) 
{
  struct discord_channel_create_message_params *params = (struct discord_channel_create_message_params*)data;

  curl_mime *mime = curl_mime_init(ehandle);
  curl_mimepart *part = curl_mime_addpart(mime);

  if (params->file.content) {
    if (!params->file.name) { // set a default name
      params->file.name = "a.out";
    }
    curl_mime_data(part, params->file.content, params->file.size);
    curl_mime_filename(part, params->file.name);
    curl_mime_type(part, "application/octet-stream");
  }
  else { //params->filename exists 
    curl_mime_filedata(part, params->file.name);
  }

  curl_mime_name(part, "file");

  return mime;
}

void
discord_create_message(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  struct discord_channel_create_message_params *params, 
  struct discord_message *p_message)
{
  if (ws_get_status(client->gw.ws) != WS_CONNECTED) {
    D_PUTS("Can't perform action unless client has an active"
           " websockets connection");
    return;
  }
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!params) {
    D_PUTS("Missing 'params'");
    return;
  }

  struct resp_handle resp_handle = {
    .ok_cb = p_message ? &discord_message_from_json_v : NULL,
    .ok_obj = p_message,
  };

  if (!params->file.name && !params->file.content)
  {  // content-type is application/json
    if (!params->embed) {
      if (IS_EMPTY_STRING(params->content)) {
        D_PUTS("Missing 'content'");
        return;
      }
      if (strlen(params->content) >= MAX_MESSAGE_LEN) {
        D_PRINT("Content length exceeds %d characters threshold (%zu)",
            MAX_MESSAGE_LEN, strlen(params->content));
        return;
      }
    }

    void *A[6] = {0}; // pointer availability array
    if (params->content)
      A[0] = (void *)params->content;
    if (params->nonce)
      A[1] = (void *)params->nonce;
    if (true == params->tts)
      A[2] = (void *)&params->tts;
    if (params->embed)
      A[3] = (void *)params->embed;
    /* @todo change current A[4] to A[5]
    if (params->allowed_mentions)
      A[4] = (void *)params->allowed_mentions;
    */
    if (params->message_reference)
      A[4] = (void *)params->message_reference;

    char payload[MAX_PAYLOAD_LEN];
    json_inject(payload, sizeof(payload),
        "(content):s"
        "(nonce):s"
        "(tts):b"
        "(embed):F"
        /* @todo
        "(allowed_mentions):F"
        */
        "(message_reference):F"
        "@arg_switches",
        params->content,
        params->nonce,
        &params->tts,
        &discord_channel_embed_to_json, params->embed,
        /* @todo
        params->allowed_mentions,
        */
        &discord_message_reference_to_json, params->message_reference,
        A, sizeof(A));

    struct sized_buffer req_body = {payload, strlen(payload)};

    discord_adapter_run( 
      &client->adapter,
      &resp_handle,
      &req_body,
      HTTP_POST, 
      "/channels/%llu/messages", channel_id);
  }
  else 
  { // content-type is multipart/form-data
    ua_reqheader_add(&client->adapter.ua, "Content-Type", "multipart/form-data");

    ua_mime_setopt(&client->adapter.ua, params, &curl_mime_cb);

    discord_adapter_run( 
      &client->adapter,
      &resp_handle,
      NULL,
      HTTP_MIMEPOST, "/channels/%llu/messages", channel_id);

    //set back to default
    ua_reqheader_add(&client->adapter.ua, "Content-Type", "application/json");
  }
}

void
discord_edit_message(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  const u64_snowflake_t message_id, 
  struct discord_channel_edit_message_params *params, 
  struct discord_message *p_message)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!message_id) {
    D_PUTS("Missing 'message_id'");
    return;
  }
  if (!params) {
    D_PUTS("Missing 'params'");
    return;
  }

  struct resp_handle resp_handle = {
    .ok_cb = p_message ? &discord_message_from_json_v : NULL,
    .ok_obj = p_message,
  };

  char payload[MAX_PAYLOAD_LEN];

  void *A[4] = {0}; // pointer availability array

  A[0] = params->content;
  A[1] = params->embed;
  A[2] = params->flags;
  // A[3] = params->allowed_mentions;

  json_inject(payload, sizeof(payload),
    "(content):s"
    "(embed):F"
    "(flags):d"
    //"(allowed_mentions):F"
    "@arg_switches",
    params->content,
    &discord_channel_embed_to_json, params->embed,
    params->flags,
    A, sizeof(A));
    //&allowed_mentions_to_json, params->allowed_mentions);

  struct sized_buffer req_body = { payload, strlen(payload) };

  discord_adapter_run(&client->adapter,
    &resp_handle,
    &req_body,
    HTTP_PATCH,
    "/channels/%llu/messages/%llu", channel_id, message_id);
}

void 
discord_create_reaction(
  struct discord *client, 
  const u64_snowflake_t channel_id, 
  const u64_snowflake_t message_id, 
  const u64_snowflake_t emoji_id, 
  const char emoji_name[])
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id'");
    return;
  }
  if (!message_id) {
    D_PUTS("Missing 'message_id'");
    return;
  }

  char *pct_emoji_name = (emoji_name) 
                  ? url_encode((char*)emoji_name)
                  : NULL;

  char emoji_endpoint[256];
  if (emoji_id)
    snprintf(emoji_endpoint, sizeof(emoji_endpoint), "%s:%" PRIu64, pct_emoji_name, emoji_id);
  else
    snprintf(emoji_endpoint, sizeof(emoji_endpoint), "%s", pct_emoji_name);

  discord_adapter_run(
    &client->adapter,
    NULL,
    NULL,
    HTTP_PUT,
    "/channels/%llu/messages/%llu/reactions/%s/@me", 
    channel_id, message_id, emoji_endpoint);

  free(pct_emoji_name);
}

void
discord_trigger_typing_indicator(struct discord* client, u64_snowflake_t channel_id)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id");
    return;
  }

  discord_adapter_run( 
    &client->adapter,
    NULL,
    NULL,
    HTTP_POST, 
    "/channels/%llu/typing", channel_id);
}
