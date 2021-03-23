/* This file is generated from specs/webhook.execute-webhook.json, Please don't edit it. */
#include "specs.h"
/*

*/

void discord_webhook_execute_webhook_params_from_json(char *json, size_t len, struct discord_webhook_execute_webhook_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
                "(wait):b,"
  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
                "(content):s,"
  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
                "(username):?s,"
  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
                "(avatar_url):?s,"
  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
                "(tts):b,"
  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
                "(file):?s,"
  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
                "(embeds):F,"
  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
                "(payload_json):?s,"
  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
                "(allowed_mentions):F,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
                &p->wait,
  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
                p->content,
  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
                &p->username,
  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
                &p->avatar_url,
  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
                &p->tts,
  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
                &p->file,
  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
                discord_channel_embed_dati_from_json, p->embeds,
  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
                &p->payload_json,
  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
                discord_channel_allowed_mentions_dati_from_json, p->allowed_mentions,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_webhook_execute_webhook_params_use_default_inject_settings(struct discord_webhook_execute_webhook_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
  p->__M.arg_switches[0] = &p->wait;

  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
  p->__M.arg_switches[1] = p->content;

  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
  p->__M.arg_switches[2] = p->username;

  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
  p->__M.arg_switches[3] = p->avatar_url;

  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
  p->__M.arg_switches[4] = &p->tts;

  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
  p->__M.arg_switches[5] = p->file;

  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
  p->__M.arg_switches[6] = p->embeds;

  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
  p->__M.arg_switches[7] = p->payload_json;

  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
  p->__M.arg_switches[8] = p->allowed_mentions;

}

size_t discord_webhook_execute_webhook_params_to_json(char *json, size_t len, struct discord_webhook_execute_webhook_params *p)
{
  size_t r;
  discord_webhook_execute_webhook_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
                "(wait):b,"
  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
                "(content):s,"
  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
                "(username):s,"
  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
                "(avatar_url):s,"
  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
                "(tts):b,"
  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
                "(file):s,"
  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
                "(embeds):F,"
  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
                "(payload_json):s,"
  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
                "(allowed_mentions):F,"
                "@arg_switches:b",
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
                &p->wait,
  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
                p->content,
  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
                p->username,
  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
                p->avatar_url,
  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
                &p->tts,
  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
                p->file,
  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
                discord_channel_embed_dati_to_json, p->embeds,
  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
                p->payload_json,
  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
                discord_channel_allowed_mentions_dati_to_json, p->allowed_mentions,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_webhook_execute_webhook_params_cleanup_v(void *p) {
  discord_webhook_execute_webhook_params_cleanup((struct discord_webhook_execute_webhook_params *)p);
}

void discord_webhook_execute_webhook_params_init_v(void *p) {
  discord_webhook_execute_webhook_params_init((struct discord_webhook_execute_webhook_params *)p);
}

void discord_webhook_execute_webhook_params_free_v(void *p) {
 discord_webhook_execute_webhook_params_free((struct discord_webhook_execute_webhook_params *)p);
};

void discord_webhook_execute_webhook_params_from_json_v(char *json, size_t len, void *p) {
 discord_webhook_execute_webhook_params_from_json(json, len, (struct discord_webhook_execute_webhook_params*)p);
}

size_t discord_webhook_execute_webhook_params_to_json_v(char *json, size_t len, void *p) {
  return discord_webhook_execute_webhook_params_to_json(json, len, (struct discord_webhook_execute_webhook_params*)p);
}

void discord_webhook_execute_webhook_params_list_free_v(void **p) {
  discord_webhook_execute_webhook_params_list_free((struct discord_webhook_execute_webhook_params**)p);
}

void discord_webhook_execute_webhook_params_list_from_json_v(char *str, size_t len, void *p) {
  discord_webhook_execute_webhook_params_list_from_json(str, len, (struct discord_webhook_execute_webhook_params ***)p);
}

size_t discord_webhook_execute_webhook_params_list_to_json_v(char *str, size_t len, void *p){
  return discord_webhook_execute_webhook_params_list_to_json(str, len, (struct discord_webhook_execute_webhook_params **)p);
}


void discord_webhook_execute_webhook_params_cleanup(struct discord_webhook_execute_webhook_params *d) {
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */
  //p->wait is a scalar
  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */
  //p->content is a scalar
  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */
  if (d->username)
    free(d->username);
  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */
  if (d->avatar_url)
    free(d->avatar_url);
  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */
  //p->tts is a scalar
  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */
  if (d->file)
    free(d->file);
  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
  if (d->embeds)
    discord_channel_embed_dati_free(d->embeds);
  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */
  if (d->payload_json)
    free(d->payload_json);
  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
  if (d->allowed_mentions)
    discord_channel_allowed_mentions_dati_free(d->allowed_mentions);
}

void discord_webhook_execute_webhook_params_init(struct discord_webhook_execute_webhook_params *p) {
  memset(p, 0, sizeof(struct discord_webhook_execute_webhook_params));
  /* specs/webhook.execute-webhook.json:12:20
     '{ "name": "wait", "type":{ "base":"bool"}, "loc":"query",
          "comment":"name of the webhook(1-80) chars",
          "required":"one of content, file, embeds"
        }'
  */

  /* specs/webhook.execute-webhook.json:16:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"the message contents (up to 2000 characters",
          "required":false
        }'
  */

  /* specs/webhook.execute-webhook.json:20:20
     '{ "name": "username", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default username of the webhook",
          "required":false
        }'
  */

  /* specs/webhook.execute-webhook.json:24:20
     '{ "name": "avatar_url", "type":{ "base":"char", "dec":"*" }, 
          "comment":"override the default avatar of the webhook" }'
  */

  /* specs/webhook.execute-webhook.json:26:20
     '{ "name": "tts", "type":{ "base":"bool" }, 
          "comment":"true if this is a TTS message",
          "required":false
        }'
  */

  /* specs/webhook.execute-webhook.json:30:20
     '{ "name": "file", "type":{ "base":"char", "dec":"*" }, 
          "comment":"the contents of the file being sent",
          "required":"one of content, file, embeds"
        }'
  */

  /* specs/webhook.execute-webhook.json:34:20
     '{ "name": "embeds", "type":{ "base":"discord::channel::embed::dati", "dec":"*" }, 
          "comment":"embedded rich content",
          "required":"one of content, file, embeds"
        }'
  */
  p->embeds = discord_channel_embed_dati_alloc();

  /* specs/webhook.execute-webhook.json:38:20
     '{ "name": "payload_json", "type":{ "base":"char", "dec":"*" }, 
          "comment":"See message create",
          "required":"multipart/form-data only"
        }'
  */

  /* specs/webhook.execute-webhook.json:42:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"discord::channel::allowed_mentions::dati", "dec":"*" },
          "comment":"allowed mentions for the message",
          "required":"false"
        }'
  */
  p->allowed_mentions = discord_channel_allowed_mentions_dati_alloc();

}
struct discord_webhook_execute_webhook_params* discord_webhook_execute_webhook_params_alloc() {
  struct discord_webhook_execute_webhook_params *p= (struct discord_webhook_execute_webhook_params*)malloc(sizeof(struct discord_webhook_execute_webhook_params));
  discord_webhook_execute_webhook_params_init(p);
  return p;
}

void discord_webhook_execute_webhook_params_free(struct discord_webhook_execute_webhook_params *p) {
  discord_webhook_execute_webhook_params_cleanup(p);
  free(p);
}

void discord_webhook_execute_webhook_params_list_free(struct discord_webhook_execute_webhook_params **p) {
  ntl_free((void**)p, (vfvp)discord_webhook_execute_webhook_params_cleanup);
}

void discord_webhook_execute_webhook_params_list_from_json(char *str, size_t len, struct discord_webhook_execute_webhook_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_webhook_execute_webhook_params);
  d.init_elem = discord_webhook_execute_webhook_params_init_v;
  d.elem_from_buf = discord_webhook_execute_webhook_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_webhook_execute_webhook_params_list_to_json(char *str, size_t len, struct discord_webhook_execute_webhook_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_webhook_execute_webhook_params_to_json_v);
}

