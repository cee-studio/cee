/* This file is generated from specs/guild.create-channel.json, Please don't edit it. */
#include "specs.h"
/*

*/
namespace discord {
namespace guild {
namespace create_channel {

void params_from_json(char *json, size_t len, struct params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
                "(name):?s,"
  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
                "(type):d,"
  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
                "(topic):?s,"
  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(bitrate):d,"
  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(user_limit):d,"
  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(rate_limit_per_user):d,"
  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
                "(position):d,"
  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
                "(permission_overwrites):F,"
  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                "(parent_id):F,"
  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
                "(nsfw):b,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
                &p->name,
  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
                &p->type,
  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
                &p->topic,
  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->bitrate,
  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->user_limit,
  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->rate_limit_per_user,
  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
                &p->position,
  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
                discord::channel::overwrite::dati_list_from_json, &p->permission_overwrites,
  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                orka_strtoull, &p->parent_id,
  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
                &p->nsfw,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void params_use_default_inject_settings(struct params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
  p->__M.arg_switches[0] = p->name;

  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
  p->__M.arg_switches[1] = &p->type;

  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
  p->__M.arg_switches[2] = p->topic;

  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  if (p->bitrate != 0)
    p->__M.arg_switches[3] = &p->bitrate;

  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  if (p->user_limit != 0)
    p->__M.arg_switches[4] = &p->user_limit;

  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  if (p->rate_limit_per_user != 0)
    p->__M.arg_switches[5] = &p->rate_limit_per_user;

  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
  p->__M.arg_switches[6] = &p->position;

  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
  if (p->permission_overwrites != NULL)
    p->__M.arg_switches[7] = p->permission_overwrites;

  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
  if (p->parent_id != 0)
    p->__M.arg_switches[8] = &p->parent_id;

  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
  p->__M.arg_switches[9] = &p->nsfw;

}

size_t params_to_json(char *json, size_t len, struct params *p)
{
  size_t r;
  params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
                "(name):s,"
  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
                "(type):d,"
  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
                "(topic):s,"
  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(bitrate):d,"
  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(user_limit):d,"
  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                "(rate_limit_per_user):d,"
  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
                "(position):d,"
  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
                "(permission_overwrites):F,"
  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                "(parent_id):|F|,"
  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
                "(nsfw):b,"
                "@arg_switches:b",
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
                p->name,
  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
                &p->type,
  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
                p->topic,
  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->bitrate,
  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->user_limit,
  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
                &p->rate_limit_per_user,
  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
                &p->position,
  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
                discord::channel::overwrite::dati_list_to_json, p->permission_overwrites,
  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                orka_ulltostr, &p->parent_id,
  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
                &p->nsfw,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void params_cleanup_v(void *p) {
  params_cleanup((struct params *)p);
}

void params_init_v(void *p) {
  params_init((struct params *)p);
}

void params_free_v(void *p) {
 params_free((struct params *)p);
};

void params_from_json_v(char *json, size_t len, void *p) {
 params_from_json(json, len, (struct params*)p);
}

size_t params_to_json_v(char *json, size_t len, void *p) {
  return params_to_json(json, len, (struct params*)p);
}

void params_list_free_v(void **p) {
  params_list_free((struct params**)p);
}

void params_list_from_json_v(char *str, size_t len, void *p) {
  params_list_from_json(str, len, (struct params ***)p);
}

size_t params_list_to_json_v(char *str, size_t len, void *p){
  return params_list_to_json(str, len, (struct params **)p);
}


void params_cleanup(struct params *d) {
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */
  if (d->name)
    free(d->name);
  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */
  //p->type is a scalar
  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */
  if (d->topic)
    free(d->topic);
  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  //p->bitrate is a scalar
  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  //p->user_limit is a scalar
  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */
  //p->rate_limit_per_user is a scalar
  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */
  //p->position is a scalar
  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */
  if (d->permission_overwrites)
    discord::channel::overwrite::dati_list_free(d->permission_overwrites);
  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
  //p->parent_id is a scalar
  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */
  //p->nsfw is a scalar
}

void params_init(struct params *p) {
  memset(p, 0, sizeof(struct params));
  /* specs/guild.create-channel.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*" }}'
  */

  /* specs/guild.create-channel.json:12:20
     '{ "name": "type", "type":{ "base":"int" }}'
  */

  /* specs/guild.create-channel.json:13:20
     '{ "name": "topic", "type":{ "base":"char", "dec":"*" }}'
  */

  /* specs/guild.create-channel.json:14:20
     '{ "name": "bitrate", "type":{ "base":"int" }, "inject_if_not":0}'
  */

  /* specs/guild.create-channel.json:15:20
     '{ "name": "user_limit", "type":{ "base":"int" }, "inject_if_not":0}'
  */

  /* specs/guild.create-channel.json:16:20
     '{ "name": "rate_limit_per_user", "type":{ "base":"int" }, "inject_if_not":0}'
  */

  /* specs/guild.create-channel.json:17:20
     '{ "name": "position", "type":{ "base":"int" } }'
  */

  /* specs/guild.create-channel.json:18:20
     '{ "name": "permission_overwrites", "type":{ "base":"discord::channel::overwrite::dati", "dec":"ntl" }, "inject_if_not":null}'
  */

  /* specs/guild.create-channel.json:19:20
     '{ "name": "parent_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */

  /* specs/guild.create-channel.json:20:20
     '{ "name": "nsfw", "type":{ "base":"bool" }}'
  */

}
struct params* params_alloc() {
  struct params *p= (struct params*)malloc(sizeof(struct params));
  params_init(p);
  return p;
}

void params_free(struct params *p) {
  params_cleanup(p);
  free(p);
}

void params_list_free(struct params **p) {
  ntl_free((void**)p, (vfvp)params_cleanup);
}

void params_list_from_json(char *str, size_t len, struct params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct params);
  d.init_elem = params_init_v;
  d.elem_from_buf = params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t params_list_to_json(char *str, size_t len, struct params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, params_to_json_v);
}

} // namespace create_channel
} // namespace guild
} // namespace discord
