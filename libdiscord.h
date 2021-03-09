#ifndef LIBDISCORD_H_
#define LIBDISCORD_H_

#include "json-actor-boxed.h"
#include "discord-common.h"

typedef uint64_t u64_unix_ms_t;
typedef uint64_t u64_snowflake_t;

/* Size limits encountered in the Docs and searching the web */
#define MAX_NAME_LEN          100 + 1
#define MAX_TOPIC_LEN         1024 + 1
#define MAX_DESCRIPTION_LEN   2048 + 1
#define MAX_USERNAME_LEN      32 + 1
#define MAX_DISCRIMINATOR_LEN 4 + 1
#define MAX_SHA256_LEN        1024 + 1
#define MAX_LOCALE_LEN        16 + 1
#define MAX_EMAIL_LEN         254 + 1
#define MAX_REGION_LEN        16 + 1
#define MAX_REASON_LEN        512 + 1
#define MAX_MESSAGE_LEN       2000 + 1
#define MAX_PAYLOAD_LEN       4096 + 1

/* EMBED LIMITS
https://discord.com/developers/docs/resources/channel#embed-limits */
#define EMBED_TITLE_LEN       256 + 1
#define EMBED_DESCRIPTION_LEN 2048 + 1
#define EMBED_MAX_FIELDS      25
#define EMBED_FIELD_NAME_LEN  256 + 1
#define EMBED_FIELD_VALUE_LEN 1024 + 1
#define EMBED_FOOTER_TEXT_LEN 2048 + 1
#define EMBED_AUTHOR_NAME_LEN 256 + 1

/* WEBHOOK LIMITS
https://discord.com/developers/docs/resources/webhook#create-webhook */
#define WEBHOOK_NAME_LEN 80 + 1

/* SNOWFLAKES
https://discord.com/developers/docs/reference#snowflakes */
#define SNOWFLAKE_INCREMENT           12
#define SNOWFLAKE_PROCESS_ID          17
#define SNOWFLAKE_INTERNAL_WORKER_ID  22
#define SNOWFLAKE_TIMESTAMP           64

/* * * * * * * * * * * * * * * * * * * */
/* * * * STRUCTURES DECLARATIONS * * * */

namespace discord {

enum callback_opt {
  IDLE,
  READY,
  MESSAGE_CREATE,
  MESSAGE_UPDATE,
  MESSAGE_DELETE,
  MESSAGE_DELETE_BULK,
  REACTION_ADD,
  REACTION_REMOVE,
  REACTION_REMOVE_ALL,
  REACTION_REMOVE_EMOJI,
  GUILD_MEMBER_ADD,
  GUILD_MEMBER_UPDATE,
  GUILD_MEMBER_REMOVE
};

/* START OF SHORTCUT ALIASES */

namespace presence = websockets::identify::status_update;
}

#include "./specs-code/all_enums.hh"
#include "./specs-code/all_structs.hh"

/* * * * * * * * * * * * * * * * * * */
/* * * * FUNCTION DECLARATIONS * * * */

namespace discord { /* discord-public.c */

void global_init();
void global_cleanup();

client* init(const char token[]);
client* config_init(const char config_file[]);
void cleanup(discord::client *client);

void add_intents(client *client, websockets::intents::code code);
void set_prefix(client *client, char *prefix);
void setcb_command(client *client, char *command, message_cb *user_cb);
void setcb(client *client, enum callback_opt opt, ...);
void run(client *client);

void dump_json(client *client, char file[]);
void dump_curl(client *client, char file[]);
void* set_data(client *client, void *data);
void* get_data(client *client);

user_agent::error get_json_error(client *client);

void replace_presence(client *client, presence::dati *presence);
void set_presence(
  client *client, 
  presence::activity::dati *activity, 
  char status[], 
  bool afk);

namespace channel { /* discord-public-channel.c */

void get(client *client, const uint64_t channel_id, dati *p_channel);
void del(client *client, const uint64_t channel_id, dati *p_channel);
void pin_message(client *client, const uint64_t channel_id, const uint64_t message_id);
void unpin_message(client *client, const uint64_t channel_id, const uint64_t message_id);
void trigger_typing(client *client, const uint64_t channel_id);

namespace modify {
}

namespace get_reactions {
}

namespace bulk_delete_messages {
}

namespace edit_channel_permissions {
}

namespace create_channel_invite {
}

namespace follow_news_channel {
}

namespace group_dm_add_recipient {
}

namespace message {

/* https://discord.com/developers/docs/resources/channel#get-channel-messages */
namespace get_list { // function wrapper

struct params {
  uint64_t around;
  uint64_t before;
  uint64_t after;
  int limit; // max number of messages (1-100)
};

message::dati** run(client *client, const uint64_t channel_id, params *params);

} // namespace get_list

/* https://discord.com/developers/docs/resources/channel#create-message */
namespace create { // function wrapper

/* default is application/json unless any 
 *  multipart/form-data parameter is set */
struct params {
  // common parameters
  char *content;
  char *nonce;
  bool tts;
  // parameters for application/json
  embed::dati *embed;
  allowed_mentions::dati *allowed_mentions;
  message::reference::dati *message_reference;
  // parameters for multipart/form-data
  struct { // FILE STRUCT @todo better explanation
    char *name; //if only name is set, will search in working directory
    char *content; //the file contents
    size_t size; //the size must accompany the content
  } file;
  char *payload_json;
};

void run(client *client, const uint64_t channel_id, params *params, dati *p_message);

} // namespace create

/* https://discord.com/developers/docs/resources/channel#edit-message */
namespace edit { // function wrapper

struct params {
  char *content;
  embed::dati *embed; //must be initialized
  message::flags::code *flags;
  allowed_mentions::dati *allowed_mentions; //must be initialized
};

void run(client *client, const uint64_t channel_id, const uint64_t message_id, params *params, dati *p_message);

} // namespace edit

void del(client *client, const uint64_t channel_id, const uint64_t message_id);

} // namespace message

namespace reaction {

void create(
  client *client, 
  const uint64_t channel_id, 
  const uint64_t message_id, 
  const uint64_t emoji_id, 
  const char emoji_name[]);

} // namespace reaction

namespace embed {

void change_thumbnail(dati *embed, char url[], char proxy_url[], int height, int width);
void change_image(dati *embed, char url[], char proxy_url[], int height, int width);
void change_video(dati *embed, char url[], char proxy_url[], int height, int width);
void change_footer(dati *embed, char text[], char icon_url[], char proxy_icon_url[]);
void change_provider(dati *embed, char name[], char url[]);
void change_author(dati *embed, char name[], char url[], char icon_url[], char proxy_icon_url[]);
void add_field(dati *embed, char name[], char value[], bool Inline);

} // namespace embed

namespace overwrite {

void append(
  dati ***permission_overwrites, 
  uint64_t id, 
  int type, 
  uint64_t allow, uint64_t deny);

} // namespace overwrite

} // namespace channel

namespace emoji { /* discord-public-emoji.cpp */

dati** get_list(client *client, const uint64_t guild_id);

namespace create_guild_emoji {
}

namespace modify_guild_emoji {
}
} // namespace emoji

namespace guild { /* discord-public-guild.cpp */

//size_t dati_to_json(char *, size_t, void *p);

void get(client *client, const uint64_t guild_id, dati *p_guild);
channel::dati** get_channels(client *client, const uint64_t guild_id);

namespace create_channel {

void run(client *client, const uint64_t guild_id, params *params, channel::dati *p_channel);

} // namespace create_channel

namespace member {

namespace get_list {

struct params {
  int limit; // the number of members to return (1-1000)
  uint64_t after; // the highest user id in the previous page
};

dati** run(client *client, const uint64_t guild_id, struct params *params);

} // namespace get_list
void remove(client *client, const uint64_t guild_id, const uint64_t user_id);

namespace modify {
void run(client *client, const uint64_t guild_id, const uint64_t user_id, params *params, member::dati *p_member);
} // namespace modify

} // namespace member

namespace ban {

void get(client *client, const uint64_t guild_id, const uint64_t user_id, dati *p_ban);
dati** get_list(client *client, const uint64_t guild_id);
void create(client *client, const uint64_t guild_id, const uint64_t user_id, int delete_message_days, const char reason[]);
void remove(client *client, const uint64_t guild_id, const uint64_t user_id, const char reason[]);

} // namespace ban

namespace role {

dati** get_list(client *client, const uint64_t guild_id);

namespace create {

void run(client *client, const uint64_t guild_id, params *params, role::dati *p_role);

} // namespace create

void del(client *client, const uint64_t guild_id, const uint64_t role_id);

} // namespace role

} // namespace guild

namespace user { /* discord-public-user.cpp */

void get(client *client, const uint64_t user_id, dati *p_user);

namespace me { // current user centered functions

void get(client *client, dati *p_user);
guild::dati** get_guilds(client *client);
void leave_guild(client *client, const u64_snowflake_t guild_id);

} // namespace me

} // namespace user

} // namespace discord

#include "./specs-code/all_fun.hh"
#endif
