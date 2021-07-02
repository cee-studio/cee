/* This file is generated from specs/reddit/links_n_comments.json, Please don't edit it. */
/**
 * @file specs-code/reddit/links_n_comments.c
 * @author cee-studio
 * @date 01 Jul 2021
 * @brief Specs generated file
 * @see 
 */

#include "specs.h"

void reddit_comment_params_from_json(char *json, size_t len, struct reddit_comment_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
                "(api_type):?s,"
  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
                "(return_rtjson):b,"
  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
                "(richtext_json):?s,"
  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
                "(text):?s,"
  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
                "(thing_id):?s,"
  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
                "(uh):?s,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
                &p->api_type,
  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
                &p->return_rtjson,
  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
                &p->richtext_json,
  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
                &p->text,
  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
                &p->thing_id,
  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
                &p->uh,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void reddit_comment_params_use_default_inject_settings(struct reddit_comment_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
  p->__M.arg_switches[0] = p->api_type;

  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
  p->__M.arg_switches[1] = &p->return_rtjson;

  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
  p->__M.arg_switches[2] = p->richtext_json;

  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
  p->__M.arg_switches[3] = p->text;

  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
  p->__M.arg_switches[4] = p->thing_id;

  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
  p->__M.arg_switches[5] = p->uh;

}

size_t reddit_comment_params_to_json(char *json, size_t len, struct reddit_comment_params *p)
{
  size_t r;
  reddit_comment_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
                "(api_type):s,"
  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
                "(return_rtjson):b,"
  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
                "(richtext_json):s,"
  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
                "(text):s,"
  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
                "(thing_id):s,"
  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
                "(uh):s,"
                "@arg_switches:b",
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
                p->api_type,
  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
                &p->return_rtjson,
  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
                p->richtext_json,
  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
                p->text,
  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
                p->thing_id,
  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
                p->uh,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void reddit_comment_params_cleanup_v(void *p) {
  reddit_comment_params_cleanup((struct reddit_comment_params *)p);
}

void reddit_comment_params_init_v(void *p) {
  reddit_comment_params_init((struct reddit_comment_params *)p);
}

void reddit_comment_params_free_v(void *p) {
 reddit_comment_params_free((struct reddit_comment_params *)p);
};

void reddit_comment_params_from_json_v(char *json, size_t len, void *p) {
 reddit_comment_params_from_json(json, len, (struct reddit_comment_params*)p);
}

size_t reddit_comment_params_to_json_v(char *json, size_t len, void *p) {
  return reddit_comment_params_to_json(json, len, (struct reddit_comment_params*)p);
}

void reddit_comment_params_list_free_v(void **p) {
  reddit_comment_params_list_free((struct reddit_comment_params**)p);
}

void reddit_comment_params_list_from_json_v(char *str, size_t len, void *p) {
  reddit_comment_params_list_from_json(str, len, (struct reddit_comment_params ***)p);
}

size_t reddit_comment_params_list_to_json_v(char *str, size_t len, void *p){
  return reddit_comment_params_list_to_json(str, len, (struct reddit_comment_params **)p);
}


void reddit_comment_params_cleanup(struct reddit_comment_params *d) {
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */
  if (d->api_type)
    free(d->api_type);
  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */
  // p->return_rtjson is a scalar
  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */
  if (d->richtext_json)
    free(d->richtext_json);
  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */
  if (d->text)
    free(d->text);
  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */
  if (d->thing_id)
    free(d->thing_id);
  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */
  if (d->uh)
    free(d->uh);
}

void reddit_comment_params_init(struct reddit_comment_params *p) {
  memset(p, 0, sizeof(struct reddit_comment_params));
  /* specs/reddit/links_n_comments.json:13:20
     '{ "name": "api_type", "type":{ "base":"char", "dec":"*" }, "comment":"the string json" }' */

  /* specs/reddit/links_n_comments.json:14:20
     '{ "name": "return_rtjson", "type":{ "base":"bool" }, "comment":"boolean value" }' */

  /* specs/reddit/links_n_comments.json:15:20
     '{ "name": "richtext_json", "type":{ "base":"char", "dec":"*" }, "comment":"JSON data" }' */

  /* specs/reddit/links_n_comments.json:16:20
     '{ "name": "text", "type":{ "base":"char", "dec":"*" }, "comment":"raw markdown text" }' */

  /* specs/reddit/links_n_comments.json:17:20
     '{ "name": "thing_id", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of parent thing" }' */

  /* specs/reddit/links_n_comments.json:18:20
     '{ "name": "uh", "type":{ "base":"char", "dec":"*" }, "comment":"a modhash" }' */

}
struct reddit_comment_params* reddit_comment_params_alloc() {
  struct reddit_comment_params *p= malloc(sizeof(struct reddit_comment_params));
  reddit_comment_params_init(p);
  return p;
}

void reddit_comment_params_free(struct reddit_comment_params *p) {
  reddit_comment_params_cleanup(p);
  free(p);
}

void reddit_comment_params_list_free(struct reddit_comment_params **p) {
  ntl_free((void**)p, (vfvp)reddit_comment_params_cleanup);
}

void reddit_comment_params_list_from_json(char *str, size_t len, struct reddit_comment_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct reddit_comment_params);
  d.init_elem = reddit_comment_params_init_v;
  d.elem_from_buf = reddit_comment_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t reddit_comment_params_list_to_json(char *str, size_t len, struct reddit_comment_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, reddit_comment_params_to_json_v);
}

