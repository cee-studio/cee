#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libdiscord.h>
#include <orka-utils.h>

#if 1
namespace discord {
namespace user_defined {
namespace bulk_delete_messages {

struct msg {
  u64_snowflake_t id;
  bool matched;
};

void msg_from_json(char *json, size_t size, void *msg)
{

}

void
run(client *client, u64_snowflake_t channel_id, u64_snowflake_t author_id)
{
  if (!channel_id) {
    D_PUTS("Missing 'channel_id");
    return;
  }

  channel::get_channel_messages::params params = {
    .limit = 100
  };

  channel::message::dati ** messages =
    channel::get_channel_messages::run(client, channel_id, &params);

  ja_u64 **list = NULL;
  int count = 0;
  for (int i = 0; messages[i]; i++) {
    if (messages[i]->author->id == author_id)
      count ++;
  }
  list = (NTL_T(ja_u64))ntl_calloc(count, sizeof(ja_u64));

  for (int i = 0, j = 0; messages[i] && j < count; i++) {
    if (messages[i]->author->id == author_id) {
      list[j]->value = messages[i]->id;
      j++;
    }
  }
  ntl_free((ntl_t)messages, channel::message::dati_cleanup_v);

  if (count == 1)
    channel::delete_message::run(client, channel_id, list[0]->value);
  else {
    char *json = NULL;
    json_ainject(&json,
                 "(messages):F",
                 ja_u64_list_to_json, list);

    struct sized_buffer req_body = {
      .size = strlen(json),
      .start = json
    };

    user_agent::run(
      &client->ua,
      NULL,
      &req_body,
      HTTP_POST,
      "/channels/%llu/messages/bulk-delete", channel_id);
  }
}


} // bulk_delete_messages

} // user_defined
}
#endif
