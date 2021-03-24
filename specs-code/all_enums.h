/* This file is generated from specs/guild.membership_screening.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#membership-screening-object
*/


enum discord_guild_membership_screening_field_type {
  DISCORD_GUILD_MEMBERSHIP_SCREENING_TERMS = 0,
};
/* This file is generated from specs/channel.edit-channel-permissions.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/channel.modify-channel.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/channel.message.json, Please don't edit it. */
/*

*/


enum discord_message_sticker_format_types {
  DISCORD_MESSAGE_STICKER_PNG = 1,
  DISCORD_MESSAGE_STICKER_APNG = 2,
  DISCORD_MESSAGE_STICKER_LOTTIE = 3,
};


enum discord_message_flags {
  DISCORD_MESSAGE_CROSSPOSTED = 1, // 1<<0
  DISCORD_MESSAGE_IS_CROSSPOST = 2, // 1<<1
  DISCORD_MESSAGE_SUPRESS_EMBEDS = 4, // 1<<2
  DISCORD_MESSAGE_SOURCE_MESSAGE_DELETED = 8, // 1<<3
  DISCORD_MESSAGE_URGENT = 16, // 1<<4
};


enum discord_message_activity_types {
  DISCORD_MESSAGE_ACTIVITY_JOIN = 1,
  DISCORD_MESSAGE_ACTIVITY_SPECTATE = 2,
  DISCORD_MESSAGE_ACTIVITY_LISTEN = 3,
  DISCORD_MESSAGE_ACTIVITY_JOIN_REQUEST = 5,
};


enum discord_message_types {
  DISCORD_MESSAGE_DEFAULT = 0,
  DISCORD_MESSAGE_RECIPIENT_ADD = 1,
  DISCORD_MESSAGE_RECIPIENT_REMOVE = 3,
  DISCORD_MESSAGE_CALL = 5,
  DISCORD_MESSAGE_CHANNEL_NAME_CHANGE = 5,
  DISCORD_MESSAGE_CHANNEL_ICON_CHANGE = 5,
  DISCORD_MESSAGE_CHANNEL_PINNED_MESSAGE = 5,
  DISCORD_MESSAGE_GUILD_MEMBER_JOIN = 5,
  DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION = 5,
  DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9,
  DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10,
  DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11,
  DISCORD_MESSAGE_CHANNEL_FOLLOW_ADD = 12,
  DISCORD_MESSAGE_GUILD_DISCOVERY_DISQUALIFIED = 14,
  DISCORD_MESSAGE_GUILD_DISCOVERY_REQUALIFIED = 15,
  DISCORD_MESSAGE_REPLY = 19,
  DISCORD_MESSAGE_APPLICATION_COMMAND = 20,
};
/* This file is generated from specs/template.create-guild-template.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/audit_log.json, Please don't edit it. */
/*
(null)
*/


enum discord_audit_log_events {
  DISCORD_AUDIT_LOG_GUILD_UPDATE = 1,
  DISCORD_AUDIT_LOG_CHANNEL_CREATE = 10,
  DISCORD_AUDIT_LOG_CHANNEL_UPDATE = 11,
  DISCORD_AUDIT_LOG_CHANNEL_DELETE = 12,
  DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_CREATE = 13,
  DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_UPDATE = 14,
  DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_DELETE = 15,
  DISCORD_AUDIT_LOG_MEMBER_KICK = 20,
  DISCORD_AUDIT_LOG_MEMBER_PRUNE = 21,
  DISCORD_AUDIT_LOG_MEMBER_BAN_ADD = 22,
  DISCORD_AUDIT_LOG_MEMBER_BAN_REMOVE = 23,
  DISCORD_AUDIT_LOG_MEMBER_UPDATE = 24,
  DISCORD_AUDIT_LOG_MEMBER_ROLE_UPDATE = 25,
  DISCORD_AUDIT_LOG_MEMBER_MOVE = 26,
  DISCORD_AUDIT_LOG_MEMBER_DISCONNECT = 27,
  DISCORD_AUDIT_LOG_BOT_ADD = 28,
  DISCORD_AUDIT_LOG_ROLE_CREATE = 30,
  DISCORD_AUDIT_LOG_ROLE_UPDATE = 31,
  DISCORD_AUDIT_LOG_ROLE_DELETE = 32,
  DISCORD_AUDIT_LOG_INVITE_CREATE = 40,
  DISCORD_AUDIT_LOG_INVITE_DELETE = 42,
  DISCORD_AUDIT_LOG_WEBHOOK_CREATE = 50,
  DISCORD_AUDIT_LOG_WEBHOOK_UPDATE = 51,
  DISCORD_AUDIT_LOG_WEBHOOK_DELETE = 52,
  DISCORD_AUDIT_LOG_EMOJI_CREATE = 60,
  DISCORD_AUDIT_LOG_EMOJI_UPDATE = 61,
  DISCORD_AUDIT_LOG_EMOJI_DELETE = 62,
  DISCORD_AUDIT_LOG_MESSAGE_DELETE = 72,
  DISCORD_AUDIT_LOG_MESSAGE_BULK_DELETE = 73,
  DISCORD_AUDIT_LOG_MESSAGE_PIN = 74,
  DISCORD_AUDIT_LOG_MESSAGE_UNPIN = 75,
  DISCORD_AUDIT_LOG_INTEGRATION_CREATE = 80,
  DISCORD_AUDIT_LOG_INTEGRATION_UPDATE = 81,
  DISCORD_AUDIT_LOG_INTEGRATION_DELETE = 82,
};
/* This file is generated from specs/guild.create-channel.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/voice.json, Please don't edit it. */
/*
(null)
*/
/* This file is generated from specs/emoji.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/emoji#emoji-object-emoji-structure
*/
/* This file is generated from specs/channel.get-reactions.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.enum.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#integration-object-integration-structure
*/


enum discord_guild_default_message_notification_level {
  DISCORD_GUILD_ALL_MESSAGES = 0,
  DISCORD_GUILD_ONLY_MENTIONS = 1,
};


enum discord_guild_explicit_content_filter_level {
  DISCORD_GUILD_DISABLED = 0,
  DISCORD_GUILD_MEMBERS_WITHOUT_ROLES = 1,
  DISCORD_GUILD_ALL_MEMBERS = 2,
};


enum discord_guild_mfa_level {
  DISCORD_GUILD_DISCORD_MFA_NONE = 0,
  DISCORD_GUILD_ELEVATED = 1,
};


enum discord_guild_verification_level {
  DISCORD_GUILD_DISCORD_VL_NONE = 0,
  DISCORD_GUILD_LOW = 1,
  DISCORD_GUILD_MEDIUM = 2,
  DISCORD_GUILD_HIGH = 3,
  DISCORD_GUILD_VERY_HIGH = 4,
};


enum discord_guild_premium_tier {
  DISCORD_GUILD_DISCORD_PREMIUM_NONE = 0,
  DISCORD_GUILD_TIER_1 = 1,
  DISCORD_GUILD_TIER_2 = 2,
  DISCORD_GUILD_TIER_3 = 3,
};


enum discord_guild_system_channel_flags {
  DISCORD_GUILD_SUPRESS_JOIN_NOTIFICATIONS = 1, // 1<<0
  DISCORD_GUILD_SUPRESS_PREMIUM_SUBSCRIPTIONS = 2, // 1<<1
};


enum discord_guild_guild_features {
  DISCORD_GUILD_INVITE_SPLASH = 0,
  DISCORD_GUILD_VIP_REGIONS = 1,
  DISCORD_GUILD_VANITY_URL = 2,
  DISCORD_GUILD_VERIFIED = 3,
  DISCORD_GUILD_PARTNERED = 4,
  DISCORD_GUILD_COMMUNITY = 5,
  DISCORD_GUILD_COMMERCE = 6,
  DISCORD_GUILD_NEWS = 7,
  DISCORD_GUILD_DISCOVERABLE = 8,
  DISCORD_GUILD_FEATURABLE = 9,
  DISCORD_GUILD_ANIMATED_ICON = 10,
  DISCORD_GUILD_BANNER = 11,
  DISCORD_GUILD_WELCOME_SCREEN_ENABLED = 12,
  DISCORD_GUILD_MEMBER_VERIFICATION_GATE_ENABLED = 13,
  DISCORD_GUILD_PREVIEW_ENABLED = 14,
};
/* This file is generated from specs/guild.ban.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#ban-object
*/
/* This file is generated from specs/guild.modify-guild-member.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.integration.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#integration-object-integration-structure
*/


enum discord_guild_integration_expire_behaviors {
  DISCORD_GUILD_INTEGRATION_REMOVE_ROLE = 0,
  DISCORD_GUILD_INTEGRATION_KICK = 1,
};
/* This file is generated from specs/invite.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/invite#invite-object
*/


enum discord_invite_target_user_types {
  DISCORD_INVITE_STREAM = 1,
};
/* This file is generated from specs/webhook.edit-webhook-message.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/template.create-guild-from-template.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/webhook.modify-webhook.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/channel.objects.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/channel#overwrite-object-overwrite-structure
*/
/* This file is generated from specs/channel.group-dm-add-recipient.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/webhook.create-webhook.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.welcome_screen.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#welcome-screen-object
*/
/* This file is generated from specs/guild.create-guild.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/channel.bulk-delete-messages.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/webhook.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/webhook#webhook-object-webhook-structure
*/


enum discord_webhook_types {
  DISCORD_WEBHOOK_INCOMING = 1,
  DISCORD_WEBHOOK_CHANNEL_FOLLOWER = 2,
};
/* This file is generated from specs/user.create-group-dm.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#guild-object-guild-structure
*/
/* This file is generated from specs/webhook.execute-webhook.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.role.create.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/emoji.modify-guild-emoji.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/permissions.json, Please don't edit it. */
/*
https://discord.com/developers/docs/topics/permissions
*/


enum discord_permissions_bitwise_flags {
  DISCORD_PERMISSIONS_ZERO = 0, // No permission bits
  DISCORD_PERMISSIONS_CREATE_INSTANT_INVITE = 1, // Allows creation of instant invites  T, V
  DISCORD_PERMISSIONS_KICK_MEMBERS = 2, // Allows kicking members
  DISCORD_PERMISSIONS_BAN_MEMBERS = 4, // Allows banning members
  DISCORD_PERMISSIONS_ADMINISTRATOR = 8, // Allows all permissions and bypasses channel permission overwrites   
  DISCORD_PERMISSIONS_MANAGE_CHANNELS = 16, // Allows management and editing of channels   T, V
  DISCORD_PERMISSIONS_MANAGE_GUILD = 32, // Allows management and editing of the guild  
  DISCORD_PERMISSIONS_ADD_REACTIONS = 64, // Allows for the addition of reactions to messages    T
  DISCORD_PERMISSIONS_VIEW_AUDIT_LOG = 128, // Allows for viewing of audit logs    
  DISCORD_PERMISSIONS_PRIORITY_SPEAKER = 256, // Allows for using priority speaker in a voice channel    V
  DISCORD_PERMISSIONS_STREAM = 512, // Allows the user to go live  V
  DISCORD_PERMISSIONS_VIEW_CHANNEL = 1024, // Allows guild members to view a channel, which includes reading messages in text channels    T, V
  DISCORD_PERMISSIONS_SEND_MESSAGES = 2048, // Allows for sending messages in a channel    T
  DISCORD_PERMISSIONS_SEND_TTS_MESSAGES = 4096, // Allows for sending of /tts messages T
  DISCORD_PERMISSIONS_MANAGE_MESSAGES = 8192, // Allows for deletion of other users messages T
  DISCORD_PERMISSIONS_EMBED_LINKS = 16384, // Links sent by users with this permission will be auto-embedded  T
  DISCORD_PERMISSIONS_ATTACH_FILES = 32768, // Allows for uploading images and files   T
  DISCORD_PERMISSIONS_READ_MESSAGE_HISTORY = 65536, // Allows for reading of message history   T
  DISCORD_PERMISSIONS_MENTION_EVERYONE = 131072, // Allows for using the @everyone tag to notify all users in a channel, and the @here tag to notify all online users in a channel  T
  DISCORD_PERMISSIONS_USE_EXTERNAL_EMOJIS = 262144, // Allows the usage of custom emojis from other servers    T
  DISCORD_PERMISSIONS_VIEW_GUILD_INSIGHTS = 524288, // Allows for viewing guild insights   
  DISCORD_PERMISSIONS_CONNECT = 1048576, // Allows for joining of a voice channel   V
  DISCORD_PERMISSIONS_SPEAK = 2097152, // Allows for speaking in a voice channel  V
  DISCORD_PERMISSIONS_MUTE_MEMBERS = 4194304, // Allows for muting members in a voice channel    V
  DISCORD_PERMISSIONS_DEAFEN_MEMBERS = 8388608, // Allows for deafening of members in a voice channel  V
  DISCORD_PERMISSIONS_MOVE_MEMBERS = 16777216, // Allows for moving of members between voice channels V
  DISCORD_PERMISSIONS_USE_VAD = 33554432, // Allows for using voice-activity-detection in a voice channel    V
  DISCORD_PERMISSIONS_CHANGE_NICKNAME = 67108864, // Allows for modification of own nickname 
  DISCORD_PERMISSIONS_MANAGE_NICKNAMES = 134217728, // Allows for modification of other users nicknames    
  DISCORD_PERMISSIONS_MANAGE_ROLES = 268435456, // Allows management and editing of roles  T, V
  DISCORD_PERMISSIONS_MANAGE_WEBHOOKS = 536870912, // Allows management and editing of webhooks   T, V
  DISCORD_PERMISSIONS_MANAGE_EMOJIS = 1073741824, // Allows management and editing of emojis
};
/* This file is generated from specs/channel.create-channel-invite.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/guild.role.json, Please don't edit it. */
/*
https://discord.com/developers/docs/topics/permissions#role-object-role-structure
*/
/* This file is generated from specs/emoji.create-guild-emoji.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/template.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/template#template-object-template-structure
*/
/* This file is generated from specs/channel.follow-news-channel.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/gateway.json, Please don't edit it. */
/*
(null)
*/


enum discord_gateway_close_opcodes {
  DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_ERROR = 4000,
  DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_OPCODE = 4001,
  DISCORD_GATEWAY_CLOSE_REASON_DECODE_ERROR = 4002,
  DISCORD_GATEWAY_CLOSE_REASON_NOT_AUTHENTICATED = 4003,
  DISCORD_GATEWAY_CLOSE_REASON_AUTHENTICATION_FAILED = 4004,
  DISCORD_GATEWAY_CLOSE_REASON_ALREADY_AUTHENTICATED = 4005,
  DISCORD_GATEWAY_CLOSE_REASON_INVALID_SEQUENCE = 4007,
  DISCORD_GATEWAY_CLOSE_REASON_RATE_LIMITED = 4008,
  DISCORD_GATEWAY_CLOSE_REASON_SESSION_TIMED_OUT = 4009,
  DISCORD_GATEWAY_CLOSE_REASON_INVALID_SHARD = 4010,
  DISCORD_GATEWAY_CLOSE_REASON_SHARDING_REQUIRED = 4011,
  DISCORD_GATEWAY_CLOSE_REASON_INVALID_API_VERSION = 4012,
  DISCORD_GATEWAY_CLOSE_REASON_INVALID_INTENTS = 4013,
  DISCORD_GATEWAY_CLOSE_REASON_DISALLOWED_INTENTS = 4014,
};


enum discord_gateway_intents {
  DISCORD_GATEWAY_GUILDS = 1, // 1 << 0
  DISCORD_GATEWAY_GUILD_MEMBERS = 2, // 1 << 1
  DISCORD_GATEWAY_GUILD_BANS = 4, // 1 << 2
  DISCORD_GATEWAY_GUILD_EMOJIS = 8, // 1 << 3
  DISCORD_GATEWAY_GUILD_INTEGRATIONS = 16, // 1 << 4
  DISCORD_GATEWAY_GUILD_WEBHOOKS = 32, // 1 << 5
  DISCORD_GATEWAY_GUILD_INVITES = 64, // 1 << 6
  DISCORD_GATEWAY_GUILD_VOICE_STATES = 128, // 1 << 7
  DISCORD_GATEWAY_GUILD_PRESENCES = 256, // 1 << 8
  DISCORD_GATEWAY_GUILD_MESSAGES = 512, // 1 << 9
  DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS = 1024, // 1 << 10
  DISCORD_GATEWAY_GUILD_MESSAGE_TYPING = 2048, // 1 << 11
  DISCORD_GATEWAY_DIRECT_MESSAGES = 4096, // 1 << 12
  DISCORD_GATEWAY_DIRECT_MESSAGE_REACTIONS = 8192, // 1 << 13
  DISCORD_GATEWAY_DIRECT_MESSAGE_TYPING = 16384, // 1 << 14
};


enum discord_gateway_opcodes {
  DISCORD_GATEWAY_DISPATCH = 0,
  DISCORD_GATEWAY_HEARTBEAT = 1,
  DISCORD_GATEWAY_IDENTIFY = 2,
  DISCORD_GATEWAY_PRESENCE_UPDATE = 3,
  DISCORD_GATEWAY_VOICE_STATE_UPDATE = 4,
  DISCORD_GATEWAY_RESUME = 6,
  DISCORD_GATEWAY_RECONNECT = 7,
  DISCORD_GATEWAY_REQUEST_GUILD_MEMBERS = 8,
  DISCORD_GATEWAY_INVALID_SESSION = 9,
  DISCORD_GATEWAY_HELLO = 10,
  DISCORD_GATEWAY_HEARTBEAT_ACK = 11,
};


enum discord_gateway_identify_status_update_activity_types {
  DISCORD_GATEWAY_IDENTIFY_STATUS_UPDATE_ACTIVITY_GAME = 0,
  DISCORD_GATEWAY_IDENTIFY_STATUS_UPDATE_ACTIVITY_STREAMING = 1,
  DISCORD_GATEWAY_IDENTIFY_STATUS_UPDATE_ACTIVITY_LISTENING = 2,
  DISCORD_GATEWAY_IDENTIFY_STATUS_UPDATE_ACTIVITY_CUSTOM = 4,
  DISCORD_GATEWAY_IDENTIFY_STATUS_UPDATE_ACTIVITY_COMPETING = 5,
};
/* This file is generated from specs/template.modify-guild-template.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/channel.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/channel#channel-object-channel-types
*/


enum discord_channel_types {
  DISCORD_CHANNEL_GUILD_TEXT = 0,
  DISCORD_CHANNEL_DM = 1,
  DISCORD_CHANNEL_GUILD_VOICE = 2,
  DISCORD_CHANNEL_GROUP_DM = 3,
  DISCORD_CHANNEL_GUILD_CATEGORY = 4,
  DISCORD_CHANNEL_GUILD_NEWS = 5,
  DISCORD_CHANNEL_GUILD_STORE = 6,
};
/* This file is generated from specs/guild.member.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#guild-member-object
*/
/* This file is generated from specs/user.modify-curent-user.json, Please don't edit it. */
/*

*/
/* This file is generated from specs/user.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/user#user-object
*/


enum discord_user_flags {
  DISCORD_USER_DISCORD_EMPLOYEE = 1, // 1 << 0
  DISCORD_USER_PARTNERED_SERVER_OWNER = 2, // 1 << 2
  DISCORD_USER_HYPESQUAD_EVENTS = 4, // 1 << 3
  DISCORD_USER_BUG_HUNTER_LEVEL_1 = 8, // 1 << 4
  DISCORD_USER_HOUSE_BRAVERY = 32, // 1 << 6
  DISCORD_USER_HOUSE_BRILLIANCE = 64, // 1 << 7
  DISCORD_USER_HOUSE_BALANCE = 128, // 1 << 8
  DISCORD_USER_EARLY_SUPPORTER = 256, // 1 << 9
  DISCORD_USER_TEAM_USER = 512, // 1 << 10
  DISCORD_USER_SYSTEM = 4096, // 1 << 12
  DISCORD_USER_BUG_HUNTER_LEVEL_2 = 16384, // 1 << 14
  DISCORD_USER_VERIFIED_BOT = 65536, // 1 << 16
  DISCORD_USER_EARLY_VERIFIED_BOT_DEVELOPER = 131072, // 1 << 17
};


enum discord_user_premium_types {
  DISCORD_USER_NITRO_CLASSIC = 0,
  DISCORD_USER_NITRO = 1,
};


enum discord_user_connection_visibility_types {
  DISCORD_USER_CONNECTION_NONE = 0,
  DISCORD_USER_CONNECTION_EVERYONE = 1,
};
