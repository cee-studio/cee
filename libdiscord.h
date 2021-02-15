#ifndef LIBDISCORD_H_
#define LIBDISCORD_H_

#include <inttypes.h>
#include "discord-common.h"

/* This is the version number of the package from which this header
 *  file originates */
#define LIBDISCORD_VERSION "0.0.0-DEV"

/* The numeric version number is also available "in parts" by using
 *  these defines: */
#define LIBDISCORD_VERSION_MAJOR 0
#define LIBDISCORD_VERSION_MINOR 0
#define LIBDISCORD_VERSION_PATCH 0

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
#define MAX_HEADER_LEN        512 + 1
#define MAX_REASON_LEN        512 + 1
#define MAX_MESSAGE_LEN       2000 + 1
#define MAX_PAYLOAD_LEN       4096 + 1

/* EMBED LIMITS
https://discord.com/developers/docs/resources/channel#embed-limits */
#define EMBED_TITLE_LEN       256 + 1
#define EMBED_DESCRIPTION_LEN 2048 + 1
#define EMBED_MAX_FIELDS      25 + 1
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

/* AUDIT LOG STRUCTURE
https://discord.com/developers/docs/resources/audit-log#audit-log-object-audit-log-structure */
namespace audit_log {
struct dati {
  webhook::dati **webhooks;
  user::dati **users;
  entry::dati **audit_log_entries;
  guild::integration::dati **integrations;
};

//@todo missing initialization functions

/* AUDIT LOG ENTRY STRUCTURE
https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-audit-log-entry-structure */
namespace entry {
struct dati {
  char *target_id; //@todo find fixed size limit
  change::dati **changes;
  uint64_t user_id;
  uint64_t id;
  events::code action_type;
  optional_info::dati *options;
  char reason[MAX_REASON_LEN];
};

//@todo missing initialization functions

/* AUDIT LOG EVENTS
https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-audit-log-events */
namespace events {
enum {
  GUILD_UPDATE             = 1,
  CHANNEL_CREATE           = 10,
  CHANNEL_UPDATE           = 11,
  CHANNEL_DELETE           = 12,
  CHANNEL_OVERWRITE_CREATE = 13,
  CHANNEL_OVERWRITE_UPDATE = 14,
  CHANNEL_OVERWRITE_DELETE = 15,
  MEMBER_KICK              = 20,
  MEMBER_PRUNE             = 21,
  MEMBER_BAN_ADD           = 22,
  MEMBER_BAN_REMOVE        = 23,
  MEMBER_UPDATE            = 24,
  MEMBER_ROLE_UPDATE       = 25,
  MEMBER_MOVE              = 26,
  MEMBER_DISCONNECT        = 27,
  BOT_ADD                  = 28,
  ROLE_CREATE              = 30,
  ROLE_UPDATE              = 31,
  ROLE_DELETE              = 32,
  INVITE_CREATE            = 40,
  INVITE_DELETE            = 42,
  WEBHOOK_CREATE           = 50,
  WEBHOOK_UPDATE           = 51,
  WEBHOOK_DELETE           = 52,
  EMOJI_CREATE             = 60,
  EMOJI_UPDATE             = 61,
  EMOJI_DELETE             = 62,
  MESSAGE_DELETE           = 72,
  MESSAGE_BULK_DELETE      = 73,
  MESSAGE_PIN              = 74,
  MESSAGE_UNPIN            = 75,
  INTEGRATION_CREATE       = 80,
  INTEGRATION_UPDATE       = 81,
  INTEGRATION_DELETE       = 82
};
} // namespace events

/* OPTIONAL AUDIT ENTRY INFO STRUCTURE
https://discord.com/developers/docs/resources/audit-log#audit-log-entry-object-optional-audit-entry-info */
namespace optional_info {
struct dati {
  char *delete_member_days; //@todo find fixed size limit
  char *members_removed; //@todo find fixed size limit
  uint64_t channel_id;
  uint64_t message_id;
  char *count; //@todo find fixed size limit
  uint64_t id;
  char *type; //@todo find fixed size limit
  char *role; //@todo find fixed size limit
};

//@todo missing initialization functions

} // namespace optional_entry

} // namespace entry

/* AUDIT LOG CHANGE STRUCTURE
https://discord.com/developers/docs/resources/audit-log#audit-log-change-object-audit-log-change-structure */
namespace change {
struct dati {
  void *new_value;
  void *old_value;
  char key[64];
};

//@todo missing initialization functions

/* AUDIT LOG CHANGE KEY
https://discord.com/developers/docs/resources/audit-log#audit-log-change-object-audit-log-change-key */
namespace key {
struct dati {
   char name[MAX_NAME_LEN];
   char description[MAX_DESCRIPTION_LEN];
   char hash[MAX_SHA256_LEN];
   char splash_hash[MAX_SHA256_LEN];
   char discovery_splash_hash[MAX_SHA256_LEN];
   uint64_t banner_hash;
   char region[MAX_REGION_LEN];
   char preferred_locale[MAX_LOCALE_LEN];
   uint64_t afk_channel_id;
   int afk_timeout;
   uint64_t rules_channel_id;
   uint64_t public_updates_channel_id;
   int mfa_level;
   int verification_level;
   int explicit_content_filter;
   int default_message_notifications;
   char vanity_url_code[MAX_URL_LEN];
  //@todo missing add
  //@todo missing remove
   int prune_delete_days;
   bool widget_enabled;
   uint64_t widget_channel_id;
   uint64_t system_channel_id;
   int position;
   char topic[MAX_TOPIC_LEN];
   int bitrate;
   channel::overwrite::dati **permission_overwrites;
   bool nsfw;
   uint64_t application_id;
   int ratelimit_per_user;
   char *permission; //@todo find fixed size limit
   int color;
   bool hoist;
   bool mentionable;
   char *allow; //@todo find fixed size limit
   char *deny; //@todo find fixed size limit
   char *code; //@todo find fixed size limit
   uint64_t channel_id;
   uint64_t inviter_id;
   int max_uses;
   int uses;
   int max_age;
   bool temporary;
   bool deaf;
   bool mute;
   char *nick; //@todo find fixed size limit
   char avatar_hash[MAX_SHA256_LEN];
   uint64_t id;
   bool enable_emoticons;
   int expire_behavior;
   int expire_grace_period;
   int user_limit;
};

//@todo missing initialization functions

} // namespace key

} // namespace change

} // namespace audit_log

/* CHANNEL STRUCTURE
https://discord.com/developers/docs/resources/channel#channel-object-channel-structure */
namespace channel {
struct dati {
  uint64_t id;
  types::code type;
  uint64_t guild_id;
  int position;
  overwrite::dati **permission_overwrites; //@todo add to from_json
  char name[MAX_NAME_LEN];
  char topic[MAX_TOPIC_LEN];
  bool nsfw;
  uint64_t last_message_id;
  int bitrate;
  int user_limit;
  int rate_limit_per_user;
  user::dati **recipients;
  char icon[MAX_SHA256_LEN];
  uint64_t owner_id;
  uint64_t application_id;
  uint64_t parent_id;
  uint64_t last_pin_timestamp;
  message::dati **messages;
};

void init_dati(void *p_channel);
dati* alloc_dati();
void cleanup_dati(void *p_channel);
void free_dati(dati *channel);
void free_list(dati **channels);
void from_json(char *str, size_t len, void *p_channel);
void list_from_json(char *str, size_t len, void *p_channels);

/* CHANNEL TYPES
https://discord.com/developers/docs/resources/channel#channel-object-channel-types */
namespace types {
enum {
  GUILD_TEXT      = 0,
  DM              = 1,
  GUILD_VOICE     = 2,
  GROUP_DM        = 3,
  GUILD_CATEGORY  = 4,
  GUILD_NEWS      = 5,
  GUILD_STORE     = 6
};
} // namespace types

/* MESSAGE STRUCTURE
https://discord.com/developers/docs/resources/channel#message-object */
namespace message {
struct dati {
  uint64_t id;
  uint64_t channel_id;
  uint64_t guild_id;
  user::dati *author;
  guild::member::dati *member;
  char *content;
  uint64_t timestamp;
  uint64_t edited_timestamp;
  bool tts;
  bool mention_everyone;
  user::dati **mentions;
  //@todo missing mention roles;
  mention::dati **mention_channels; //@todo add to from_json
  attachment::dati **attachments; //@todo add to from_json
  embed::dati **embeds; //@todo add to from_json
  reaction::dati **reactions; //@todo add to from_json
  char *nonce;
  bool pinned;
  uint64_t webhook_id;
  types::code type;
  activity::dati *activity; //@todo add to from_json
  application::dati **application; //@todo add to from_json
  reference::dati *message_reference; //@todo add to from_json
  flags::code flags;
  sticker::dati **stickers; //@todo add to from_json
  dati *referenced_message;
};

void init_dati(void *p_message);
dati* alloc_dati();
void cleanup_dati(void *p_message);
void free_dati(dati *message);
void free_list(dati **message);
void from_json(char *str, size_t len, void *p_message);
void list_from_json(char *str, size_t len, void *p_messages);

/* MESSAGE TYPES
https://discord.com/developers/docs/resources/channel#message-object-message-types */
namespace types {
enum {
  DEFAULT                                 = 0,
  RECIPIENT_ADD                           = 1,
  RECIPIENT_REMOVE                        = 2,
  CALL                                    = 3,
  CHANNEL_NAME_CHANGE                     = 4,
  CHANNEL_ICON_CHANGE                     = 5,
  CHANNEL_PINNED_MESSAGE                  = 6,
  GUILD_MEMBER_JOIN                       = 7,
  USER_PREMIUM_GUILD_SUBSCRIPTION         = 8,
  USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1  = 9,
  USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2  = 10,
  USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3  = 11,
  CHANNEL_FOLLOW_ADD                      = 12,
  GUILD_DISCOVERY_DISQUALIFIED            = 14,
  GUILD_DISCOVERY_REQUALIFIED             = 15,
  REPLY                                   = 19, // only in v8 (0 in v6)
  APPLICATION_COMMAND                     = 20  // only in v8 (0 in v6)
};
} // namespace types

/* MESSAGE ACTIVITY STRUCTURE
https://discord.com/developers/docs/resources/channel#message-object-message-activity-structure */
namespace activity {
struct dati {
  activity_types::code type;
  //@todo missing party_id;
};

//@todo missing initialization functions

} // namespace activity

/* MESSAGE APPLICATION STRUCTURE
https://discord.com/developers/docs/resources/channel#message-object-message-application-structure */
namespace application {
struct dati {
  uint64_t id;
  char *cover_image; //@todo find fixed size limit
  char *description; //@todo find fixed size limit
  char *icon; //@todo find fixed size limit
  char *name; //@todo find fixed size limit
};

//@todo missing initialization functions

} // namespace application

/* MESSAGE REFERENCE STRUCTURE
https://discord.com/developers/docs/resources/channel#message-object-message-reference-structure */
namespace reference {
struct dati {
  uint64_t message_id;
  uint64_t channel_id;
  uint64_t guild_id;
  bool fail_if_not_exists;
};

void init_dati(void *p_reference);
dati* alloc_dati();
void free_dati(dati *reference);
void from_json(char *str, size_t len, void *p_reference);

} // namespace reference

/* MESSAGE ACTIVITY TYPES
https://discord.com/developers/docs/resources/channel#message-object-message-activity-types */
namespace activity_types {
enum {
  JOIN          = 1,
  SPECTATE      = 2,
  LISTEN        = 3,
  JOIN_REQUEST  = 5
};
} // namespace activity_types

/* MESSAGE FLAGS
https://discord.com/developers/docs/resources/channel#message-object-message-flags */
namespace flags {
enum {
  CROSSPOSTED             = 1 << 0,
  IS_CROSSPOST            = 1 << 1,
  SUPRESS_EMBEDS          = 1 << 2,
  SOURCE_MESSAGE_DELETED  = 1 << 3,
  URGENT                  = 1 << 4
};    
} // namespace flags

/* MESSAGE STICKER STRUCTURE
https://discord.com/developers/docs/resources/channel#message-object-message-sticker-structure */
namespace sticker {
struct dati {
  uint64_t id;
  uint64_t pack_id;
  char *name; //@todo find fixed size limit
  char *description; //@todo find fixed size limit
  char *tags; //@todo find fixed size limit
  char asset[MAX_SHA256_LEN];
  char preview_asset[MAX_SHA256_LEN];
  format_types::code type;
};

/* MESSAGE STICKER FORMAT TYPES
https://discord.com/developers/docs/resources/channel#message-object-message-sticker-format-types */
namespace format_types {
enum {
  PNG     = 1,
  APNG    = 2,
  LOTTIE  = 3
};
} // namespace format_types

} // namespace sticker

} // namespace message

/* FOLLOWED CHANNEL STRUCTURE
https://discord.com/developers/docs/resources/channel#followed-channel-object-followed-channel-structure */
namespace followed_channel {
struct dati {
  uint64_t channel_id;
  uint64_t webhook_id;
};

//@todo missing initialization functions

} // namespace followed_channel

/* REACTION STRUCTURE
https://discord.com/developers/docs/resources/channel#reaction-object-reaction-structure */
namespace reaction {
struct dati {
  int count;
  bool me;
  emoji::dati *emoji;
};

//@todo missing initialization functions

} // namespace reaction

/* OVERWRITE STRUCTURE
https://discord.com/developers/docs/resources/channel#overwrite-object-overwrite-structure */
namespace overwrite {
struct dati {
  uint64_t id;
  int type; //either 0 (role) or 1 (member)
  uint64_t allow; //@todo convert via orka_strtoull
  uint64_t deny; //@todo convert via orka_strtoull
};

//@todo missing initialization functions

} // namespace overwrite

/* EMBED STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-structure */
namespace embed {
struct dati {
  char title[EMBED_TITLE_LEN];
  char type[32];
  char description[EMBED_DESCRIPTION_LEN];
  char url[MAX_URL_LEN];
  uint64_t timestamp; //@todo convert via orka_iso8601_to_unix_ms
  int color;
  footer::dati *footer;
  image::dati *image;
  thumbnail::dati *thumbnail;
  video::dati *video;
  provider::dati *provider;
  author::dati *author;
  field::dati *fields[EMBED_MAX_FIELDS];
};

void init_dati(void *p_embed);
dati* alloc_dati();
void cleanup_dati(void *p_embed);
void free_dati(dati *embed);
void from_json(char *str, size_t len, void *p_embed);
int to_json(char *str, size_t len, void *p_embed);

/* EMBED THUMBNAIL STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-thumbnail-structure */
namespace thumbnail {
struct dati {
  char url[MAX_URL_LEN];
  char proxy_url[MAX_URL_LEN];
  int height;
  int width;
};

//@todo missing initialization functions

void init_dati(void *p_thumbnail);
dati* alloc_dati();
void cleanup_dati(void *p_thumbnail);
void free_dati(dati *thumbnail);
void from_json(char *str, size_t len, void *p_thumbnail);
int to_json(char *str, size_t len, void *p_thumbnail);

} // namespace thumbnail

/* EMBED VIDEO STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-video-structure */
// using alias namespace video = thumbnail;

/* EMBED IMAGE STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-image-structure */
// using alias namespace image = thumbnail;

/* EMBED PROVIDER STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-provider-structure */
namespace provider {
struct dati {
  char name[EMBED_AUTHOR_NAME_LEN];
  char url[MAX_URL_LEN];
};

void init_dati(void *p_provider);
dati* alloc_dati();
void cleanup_dati(void *p_provider);
void free_dati(dati *provider);
void from_json(char *str, size_t len, void *p_provider);
int to_json(char *str, size_t len, void *p_provider);

} // namespace provider

/* EMBED AUTHOR STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-author-structure */
namespace author {
struct dati {
  char name[EMBED_AUTHOR_NAME_LEN];
  char url[MAX_URL_LEN];
  char icon_url[MAX_URL_LEN];
  char proxy_icon_url[MAX_URL_LEN];
};

void init_dati(void *p_author);
dati* alloc_dati();
void cleanup_dati(void *p_author);
void free_dati(dati *author);
void from_json(char *str, size_t len, void *p_author);
int to_json(char *str, size_t len, void *p_author);

} // namespace author

/* EMBED FOOTER STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-footer-structure */
namespace footer {
struct dati {
  char text[EMBED_FOOTER_TEXT_LEN];
  char icon_url[MAX_URL_LEN];
  char proxy_icon_url[MAX_URL_LEN];
};

void init_dati(void *p_footer);
dati* alloc_dati();
void cleanup_dati(void *p_footer);
void free_dati(dati *footer);
void from_json(char *str, size_t len, void *p_footer);
int to_json(char *str, size_t len, void *p_footer);

} // namespace footer

/* EMBED FIELD STRUCTURE
https://discord.com/developers/docs/resources/channel#embed-object-embed-field-structure */
namespace field {
struct dati {
  char name[EMBED_FIELD_NAME_LEN];
  char value[EMBED_FIELD_VALUE_LEN];
  bool Inline; //inline is a reserved keyword
};

void init_dati(void *p_field);
dati* alloc_dati();
void cleanup_dati(void *p_field);
void free_dati(dati *field);
void from_json(char *str, size_t len, void *p_field);
void list_from_json(char *str, size_t len, void *p_fields);
int to_json(char *str, size_t len, void *p_field);
int list_to_json(char *str, size_t len, void *p_fields);

} // namespace field

} // namespace embed

/* ATTACHMENT STRUCTURE
https://discord.com/developers/docs/resources/channel#attachment-object */
namespace attachment {
struct dati {
  uint64_t id;
  char filename[256]; //@todo check if is enough
  int size; //@todo check if should use different type
  char url[MAX_URL_LEN]; 
  char proxy_url[MAX_URL_LEN];
  int height;
  int width;
};

//@todo missing initialization functions

} // namespace attachment

/* CHANNEL MENTION STRUCTURE
https://discord.com/developers/docs/resources/channel#channel-mention-object-channel-mention-structure */
namespace mention {
struct dati {
  uint64_t id;
  uint64_t guild_id;
  types::code type;
  char *name; //@todo find fixed size limit
};

//@todo missing initialization functions

} // namespace mention

/* ALLOWED MENTIONS STRUCTURE
https://discord.com/developers/docs/resources/channel#allowed-mentions-object-allowed-mentions-structure */
namespace allowed_mentions {
struct dati {
  char **parse;
  uint64_t roles[100];
  uint64_t users[100];
  bool replied_user;
};

//@todo missing initialization functions

} // namespace allowed_mentions

} // namespace channel

/* EMOJI STRUCTURE
https://discord.com/developers/docs/resources/emoji#emoji-object-emoji-structure */
namespace emoji {
struct dati {
  uint64_t id;
  char *name; //@todo find fixed size limit
  //@todo missing roles;
  user::dati *user;
  bool require_colons;
  bool managed;
  bool animated;
  bool available;
};

//@todo missing initialization functions

} // namespace emoji

/* GUILD STRUCTURE
https://discord.com/developers/docs/resources/guild#guild-object-guild-structure */
namespace guild {
struct dati {
  uint64_t id;
  char name[MAX_NAME_LEN];
  char icon[MAX_SHA256_LEN];
  char icon_hash[MAX_SHA256_LEN];
  char splash[MAX_SHA256_LEN];
  char discovery_splash[MAX_SHA256_LEN];
  bool owner;
  uint64_t owner_id;
  int permissions;
  char region[MAX_REGION_LEN];
  uint64_t afk_channel_id;
  int afk_timeout;
  bool widget_enabled;
  uint64_t widget_channel_id;
  verification_level::code verification_level;
  int default_message_notifications;
  explicit_content_filter_level::code explicit_content_filter;
  //@todo missing roles;
  emoji::dati **emojis; //@todo add to from_json
  char **features; //@todo add to from_json
  mfa_level::code mfa_level;
  uint64_t application_id;
  uint64_t system_channel_id;
  system_channel_flags::code system_channel_flags; 
  uint64_t rules_channel_id;
  int64_t joined_at;
  bool large;
  bool unavailable;
  int member_count;
  //@todo missing voice_states;
  member::dati **members;
  channel::dati **channels; //@todo add to from_json
  //@todo missing presences;
  int max_presences;
  int max_members;
  char vanity_url_code[MAX_URL_LEN];
  char description[MAX_DESCRIPTION_LEN];
  char banner[MAX_SHA256_LEN];
  premium_tier::code premium_tier;
  int premium_subscription_count;
  char preferred_locale[MAX_LOCALE_LEN];
  uint64_t public_updates_channel_id;
  int max_video_channel_users;
  int approximate_member_count;
  int approximate_presence_count;
  welcome_screen::dati *welcome_screen;
};

void init_dati(void *p_guild);
dati* alloc_dati();
void cleanup_dati(void *p_guild);
void free_dati(dati *guild);
void free_list(dati **guild);
void from_json(char *str, size_t len, void *p_guild);
void list_from_json(char *str, size_t len, void *p_guilds);

/* DEFAULT MESSAGE NOTIFICATION LEVEL
https://discord.com/developers/docs/resources/guild#guild-object-default-message-notification-level */
namespace default_message_notification_level {
enum {
  ALL_MESSAGES  = 0,
  ONLY_MENTIONS = 1
};
} // namespace default_message_notification_level

/* EXPLICIT CONTENT FILTER LEVEL
https://discord.com/developers/docs/resources/guild#guild-object-explicit-content-filter-level */
namespace explicit_content_filter_level {
enum {
  DISABLED              = 0,
  MEMBERS_WITHOUT_ROLES = 1,
  ALL_MEMBERS           = 2
};
} // namespace explicit content_filter_level

/* MFA LEVEL
https://discord.com/developers/docs/resources/guild#guild-object-mfa-level */
namespace mfa_level {
enum {
  NONE     = 0,
  ELEVATED = 1
};
} // namespace mfa_level

/* VERIFICATION LEVEL
https://discord.com/developers/docs/resources/guild#guild-object-verification-level */
namespace verification_level {
enum {
  NONE      = 0, // unrestricted
  LOW       = 1, // must have verified email on account
  MEDIUM    = 2, // must be registered on Discord for longer than 5 minutes
  HIGH      = 3, // must be a member of the server for longer than 10 minutes
  VERY_HIGH = 4  // must have a verified phone number
};
} // namespace verification_level

/* PREMIUM TIER
https://discord.com/developers/docs/resources/guild#guild-object-premium-tier */
namespace premium_tier {
enum {
  NONE   = 0,
  TIER_1 = 1,
  TIER_2 = 2,
  TIER_3 = 3
};
} // namespace premium_tier

/* SYSTEM CHANNEL FLAGS
https://discord.com/developers/docs/resources/guild#guild-object-system-channel-flags */
namespace system_channel_flags {
enum {
  SUPRESS_JOIN_NOTIFICATIONS     = 1 << 0, // Suppress member join notifications
  SUPPRESS_PREMIUM_SUBSCRIPTIONS = 1 << 1  // Suppress server boost notifications
};
} // namespace system_channel_flags

/* GUILD FEATURES
https://discord.com/developers/docs/resources/guild#guild-object-guild-features */
namespace guild_features {
enum {
  INVITE_SPLASH,                      // guild has access to set an invite splash background
  VIP_REGIONS,                        // guild has access to set 384kbps bitrate in voice (previously VIP voice servers)
  VANITY_URL,                         // guild has access to set a vanity URL
  VERIFIED,                           // guild is verified
  PARTNERED,                          // guild is partnered
  COMMUNITY,                          // guild can enable welcome screen, Membership Screening, and discovery, and receives community updates
  COMMERCE,                           // guild has access to use commerce features (i.e. create store channels)
  NEWS,                               // guild has access to create news channels
  DISCOVERABLE,                       // guild is able to be discovered in the directory
  FEATURABLE,                         // guild is able to be featured in the directory
  ANIMATED_ICON,                      // guild has access to set an animated guild icon
  BANNER,                             // guild has access to set a guild banner image
  WELCOME_SCREEN_ENABLED,             // guild has enabled the welcome screen
  MEMBER_VERIFICATION_GATE_ENABLED,   // guild has enabled Membership Screening
  PREVIEW_ENABLED                     // guild can be previewed before joining via Membership Screening or the directory
};
} // namespace guild_features

/* UNAVAILABLE GUILD STRUCTURE
https://discord.com/developers/docs/resources/guild#unavailable-guild-object */
namespace unavailable_guild {
struct dati {
  uint64_t id;
  bool unavailable;
};
} // namespace unavailable_guild

/* GUILD PREVIEW STRUCTURE
https://discord.com/developers/docs/resources/guild#guild-preview-object-guild-preview-structure */
namespace preview {
struct dati {
  uint64_t id;
  char name[MAX_NAME_LEN];
  char icon[MAX_SHA256_LEN];
  char splash[MAX_SHA256_LEN];
  char discovery_splash[MAX_SHA256_LEN];
  emoji::dati **emojis;
  char **features;
  int approximate_member_count;
  int approximate_presence_count;
  char description[MAX_DESCRIPTION_LEN];
};

//@todo missing initialization functions

} // namespace preview

/* GUILD WIDGET STRUCTURE
https://discord.com/developers/docs/resources/guild#guild-widget-object-guild-widget-structure */
namespace widget {
struct dati {
  bool enabled;
  uint64_t channel_id;
};

//@todo missing initialization functions

} // namespace widget

/* GUILD MEMBER STRUCTURE
https://discord.com/developers/docs/resources/guild#guild-member-object */
namespace member {
struct dati {
  user::dati *user;
  char nick[MAX_NAME_LEN];
  uint64_t **roles; //@todo add to from_json
  uint64_t joined_at;
  uint64_t premium_since;
  bool deaf;
  bool mute;
  bool pending;
  char *permissions; //@todo find fixed size limit
};

void init_dati(void *p_member);
dati* alloc_dati();
void cleanup_dati(void *p_member);
void free_dati(dati *member);
void free_list(dati **members);
void from_json(char *str, size_t len, void *p_member);
void list_from_json(char *str, size_t len, void *p_members);

} // namespace member

/* INTEGRATION STRUCTURE
https://discord.com/developers/docs/resources/guild#integration-object-integration-structure */
namespace integration {
struct dati {
  uint64_t id;
  char *name; //@todo find fixed size limit
  char *type; //@todo find fixed size limit
  bool enabled;
  bool syncing;
  uint64_t role_id;
  bool enable_emoticons;
  expire_behaviors::code expire_behavior;
  int expire_grace_period;
  user::dati *user;
  account::dati *account;
  uint64_t synced_at;
  int subscriber_count;
  bool revoked;
  application::dati *application;
};

//@todo missing initialization functions

/* INTEGRATION EXPIRE BEHAVIORS
https://discord.com/developers/docs/resources/guild#integration-object-integration-expire-behaviors */
namespace expire_behaviors {
enum {
  REMOVE_ROLE = 0,
  KICK        = 1,
};
} // namespace expire_behaviors

/* INTEGRATION ACCOUNT STRUCTURE
https://discord.com/developers/docs/resources/guild#integration-account-object-integration-account-structure */
namespace account {
struct dati {
  uint64_t id;
  char *name; //@todo find fixed size limit
};

//@todo missing initialization functions

} // namespace account

/* INTEGRATION APPLICATION STRUCTURE
https://discord.com/developers/docs/resources/guild#integration-application-object-integration-application-structure */
namespace application {
struct dati {
  uint64_t id;
  char *name; //@todo find fixed size limit
  char icon[MAX_SHA256_LEN];
  char *description; //@todo find fixed size limit
  char *summary; //@todo find fixed size limit
  user::dati *bot;
};

//@todo missing initialization functions

} // namespace application

} // namespace integration

/* GUILD BAN STRUCTURE
https://discord.com/developers/docs/resources/guild#ban-object */
namespace ban {
struct dati {
  char reason[MAX_REASON_LEN];
  user::dati *user;
};

void init_dati(void *p_ban);
dati* alloc_dati();
void cleanup_dati(void *p_ban);
void free_dati(dati *ban);
void free_list(dati **bans);
void from_json(char *str, size_t len, void *p_ban);
void list_from_json(char *str, size_t len, void *p_ban);

} // namespace ban

/* WELCOME SCREEN STRUCTURE
https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-structure */
namespace welcome_screen {
struct dati {
  char *description; //@todo find fixed size limit
  screen_channel::dati **welcome_channels;
};

/* WELCOME SCREEN CHANNEL STRUCTURE
https://discord.com/developers/docs/resources/guild#welcome-screen-object-welcome-screen-channel-structure */
namespace screen_channel {
struct dati {
  uint64_t channel_id;
  char *description; //@todo find fixed size limit
  uint64_t emoji_id;
  char *emoji_name; //@todo find fixed size limit
};
} // namespace screen_channel
} // namespace welcome_screen

/* MEMBERSHIP SCREENING STRUCTURE
https://discord.com/developers/docs/resources/guild#membership-screening-object */
namespace membership_screening {
struct dati {
  uint64_t version;
  field::dati **fields;
  char *description; //@todo find fixed size limit
};

/* MEMBERSHIP SCREENING FIELD STRUCTURE
https://discord.com/developers/docs/resources/guild#membership-screening-object-membership-screening-field-structure */
namespace field {
struct dati {
  field_type::code field_type;   
  char *label; //@todo find fixed size limit
  char **values; //@todo find fixed size limit
  bool required;
};

//@todo missing initialization functions

/* MEMBERSHIP SCREENING FIELD TYPES
https://discord.com/developers/docs/resources/guild#membership-screening-object-membership-screening-field-types */
namespace field_type {
enum { TERMS }; //currently the only type
} // namespace field_type

} // namespace field

} // namespace membership_screening


} // namespace guild

/* INVITE STRUCTURE
https://discord.com/developers/docs/resources/invite#invite-object-invite-structure */
namespace invite {
struct dati {
  char *code; //@todo find fixed size limit
  guild::dati *guild;
  channel::dati *channel;
  user::dati *target_user;
  target_user_types::code target_user_type;
  int approximate_presence_count;
  int approximate_member_count;
};

//@todo missing initialization functions

/* TARGET USER TYPES
https://discord.com/developers/docs/resources/invite#invite-object-target-user-types */
namespace target_user_types {
enum { STREAM = 1 };
} // namespace target_user_types

/* INVITE METADATA STRUCTURE
https://discord.com/developers/docs/resources/invite#invite-metadata-object-invite-metadata-structure */
namespace metadata {
struct dati {
  int user;
  int max_uses;
  int max_age;
  bool temporary;
  uint64_t created_at;
};

//@todo missing initialization functions

} // namespace metadata

} // namespace invite

/* TEMPLATE STRUCTURE
https://discord.com/developers/docs/resources/template#template-object-template-structure */
namespace Template { // template is a reserved keyword
struct dati {
  char *code; //@todo find fixed size limit
  char *name; //@todo find fixed size limit
  char *description; //@todo find fixed size limit
  int usage_count;
  uint64_t creator_id;
  user::dati *creator;
  uint64_t created_at;
  uint64_t updated_at;
  uint64_t source_guild_id;
  guild::dati *serialized_source_guild;
  bool is_dirty;
};

//@todo missing initialization functions

} // namespace Template

/* USER STRUCTURE
https://discord.com/developers/docs/resources/user#user-object-user-structure */
namespace user {
struct dati {
  uint64_t id;
  char username[MAX_USERNAME_LEN];
  char discriminator[MAX_DISCRIMINATOR_LEN];
  char avatar[MAX_SHA256_LEN];
  bool bot;
  bool System; //system is a reserved keyword
  bool mfa_enabled;
  char locale[MAX_LOCALE_LEN];
  bool verified;
  char email[MAX_EMAIL_LEN];
  flags::code flags;
  premium_types::code premium_type;
  flags::code public_flags;
};

void init_dati(void *p_user);
dati* alloc_dati();
void cleanup_dati(void *p_user);
void free_dati(dati *user);
void free_list(dati **users);
void from_json(char *str, size_t len, void *p_user);
void list_from_json(char *str, size_t len, void *p_users);

/* USER FLAGS
https://discord.com/developers/docs/resources/user#user-object-user-flags */
namespace flags {
enum {
  NONE                         = 0,
  DISCORD_EMPLOYEE             = 1 << 0,
  PARTNERED_SERVER_OWNER       = 1 << 1,
  HYPESQUAD_EVENTS             = 1 << 2,
  BUG_HUNTER_LEVEL_1           = 1 << 3,
  HOUSE_BRAVERY                = 1 << 6,
  HOUSE_BRILLIANCE             = 1 << 7,
  HOUSE_BALANCE                = 1 << 8,
  EARLY_SUPPORTER              = 1 << 9,
  TEAM_USER                    = 1 << 10,
  SYSTEM                       = 1 << 12,
  BUG_HUNTER_LEVEL_2           = 1 << 14,
  VERIFIED_BOT                 = 1 << 16,
  EARLY_VERIFIED_BOT_DEVELOPER = 1 << 17
};
} // namespace flags

/* PREMIUM TYPES 
https://discord.com/developers/docs/resources/user#user-object-premium-types */
namespace premium_types {
enum {
  NONE          = 0,
  NITRO_CLASSIC = 1,
  NITRO         = 2
};
} // namespace premium_types

/* CONNECTION STRUCTURE
https://discord.com/developers/docs/resources/user#connection-object-connection-structure */
namespace connection {
struct dati {
  char *id; //@todo find fixed size limit
  char *name; //@todo find fixed size limit
  char *type; //@todo find fixed size limit
  bool revoked;
  guild::integration::dati **integrations;
  bool verified;
  bool friend_sync;
  bool show_activity;
  visibility_types::code visibility;
};

//@todo missing initialization functions

/* VISIBILITY TYPES
https://discord.com/developers/docs/resources/user#connection-object-visibility-types */
namespace visibility_types {
enum {
  NONE     = 0,
  EVERYONE = 1
};
} // namespace visibility_types

} // namespace connection

} // namespace user

/* VOICE STRUCTURE
https://discord.com/developers/docs/resources/voice#voice-state-object-voice-state-structure */
namespace voice {
struct dati {
  uint64_t guild_id;
  uint64_t channel_id;
  uint64_t user_id;
  guild::member::dati *member;
  char *session_id; //@todo find fixed size limit
  bool deaf;
  bool mute;
  bool self_deaf;
  bool self_mute;
  bool self_stream;
  bool self_video;
  bool suppress;
};

//@todo missing initialization functions

/* VOICE REGION STRUCTURE
https://discord.com/developers/docs/resources/voice#voice-region-object-voice-region-structure */
namespace region {
struct dati {
  char *id; //@todo find fixed size limit
  char *name; //@todo find fixed size limit
  bool vip;
  bool optimal;
  bool deprecated;
  bool custom;
};

//@todo missing initialization functions

} // namespace region

} // namespace voice

namespace webhook {
struct dati {
  uint64_t id;
  types::code type;
  uint64_t guild_id;
  uint64_t channel_id;
  user::dati *user;
  char name[WEBHOOK_NAME_LEN];
  char *avatar; //@todo find fixed size limit
  char *token; //@todo find fixed size limit
  uint64_t application_id;
};

//@todo missing initialization functions


namespace types {
enum {
  INCOMING         = 1,
  CHANNEL_FOLLOWER = 2
};
} // namespace types
} // namespace webhook

} // namespace discord


/* * * * * * * * * * * * * * * * * * */
/* * * * FUNCTION DECLARATIONS * * * */

namespace discord { /* discord-public.c */

void global_init();
void global_cleanup();

client* init(char token[]);
client* fast_init(const char config_file[]);
void cleanup(discord::client *client);

void add_intents(client *client, websockets::intents::code code);

void setcb_idle(client *client, idle_cb *user_cb);
void setcb_ready(client *client, idle_cb *user_cb);
void setcb_message_command(client *client, char prefix[], message_cb *user_cb);
void setcb_message_create(client *client, message_cb *user_cb);
void setcb_message_update(client *client, message_cb *user_cb);
void setcb_message_delete(client *client, message_delete_cb *user_cb);
void setcb_message_delete_bulk(client *client, message_delete_bulk_cb *user_cb);
void setcb_guild_member_add(client *client, guild_member_cb *user_cb);
void setcb_guild_member_update(client *client, guild_member_cb *user_cb);
void setcb_guild_member_remove(client *client, guild_member_remove_cb *user_cb);

void run(client *client);

void dump_json(client *client, char file[]);
void dump_curl(client *client, char file[]);
void* set_data(client *client, void *data);
void* get_data(client *client);

user_agent::error get_json_error(client *client);

namespace channel { /* discord-public-channel.c */

void get(client *client, const uint64_t channel_id, dati *p_channel);
void pin_message(client *client, const uint64_t channel_id, const uint64_t message_id);
void unpin_message(client *client, const uint64_t channel_id, const uint64_t message_id);

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
  message::reference::dati message_reference;
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

void del(client *client, const uint64_t channel_id, const uint64_t message_id);

} // namespace message

} // namespace channel

namespace guild { /* discord-public-guild.cpp */

void get(client *client, const uint64_t guild_id, dati *p_guild);
channel::dati** get_channels(client *client, const uint64_t guild_id);

namespace member {

namespace get_list {

struct params {
  int limit; // the number of members to return (1-1000)
  uint64_t after; // the highest user id in the previous page
};

dati** run(client *client, const uint64_t guild_id, struct params *params);

} // namespace get_list
void remove(client *client, const uint64_t guild_id, const uint64_t user_id);

} // namespace member

namespace ban {

void get(client *client, const uint64_t guild_id, const uint64_t user_id, dati *p_ban);
dati** get_list(client *client, const uint64_t guild_id);
void create(client *client, const uint64_t guild_id, const uint64_t user_id, int delete_message_days, const char reason[]);
void remove(client *client, const uint64_t guild_id, const uint64_t user_id, const char reason[]);

} // namespace ban

} // namespace guild

namespace user { /* discord-public-user.cpp */

void get(client *client, const uint64_t user_id, dati *p_user);

namespace me { // current user centered functions

void get(client *client, dati *p_user);
guild::dati** get_guilds(client *client);

} // namespace me

} // namespace user

} // namespace discord

#endif
