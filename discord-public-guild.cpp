#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libdiscord.h>

namespace discord {
namespace guild {

void
json_load(char *str, size_t len, void *p_guild)
{
  dati *guild = (dati*)p_guild;

  json_scanf(str, len,
     "[id]%s"
     "[name]%s"
     "[icon]%s"
     "[owner]%b"
     "[permissions]%d"
     "[permissions_new]%s",
      guild->id,
      guild->name,
      guild->icon,
      &guild->owner,
      &guild->permissions,
      guild->permissions_new);

  D_NOTOP_PUTS("Guild object loaded with API response"); 
}

void
json_list_load(char *str, size_t len, void *p_guilds)
{
  struct sized_buffer **buf = NULL;
  json_scanf(str, len, "[]%A", &buf);

  size_t n = ntl_length((void**)buf);
  dati **new_guilds = (dati**)ntl_calloc(n, sizeof(dati*));
  for (size_t i=0; buf[i]; ++i) {
    new_guilds[i] = init();
    json_load(buf[i]->start, buf[i]->size, new_guilds[i]);
  }
  
  free(buf);

  *(dati ***)p_guilds = new_guilds;
}

dati*
init()
{
  dati *new_guild = (dati*)calloc(1, sizeof *new_guild);
  return new_guild;
}

void
cleanup(dati *guild) {
  free(guild);
}

void
list_cleanup(dati **guilds) {
  for(int i = 0; guilds[i]; i++) {
    cleanup(guilds[i]);
  }
  free(guilds);
}

void
get(client *client, const char guild_id[], dati *p_guild)
{
  if (IS_EMPTY_STRING(guild_id)) {
    D_PUTS("Missing 'guild_id'");
    return;
  }

  struct resp_handle resp_handle = {&json_load, (void*)p_guild};
  struct sized_buffer body = {NULL, 0};

  user_agent::run( 
    &client->ua,
    &resp_handle,
    &body,
    HTTP_GET, GUILD, guild_id);
}

namespace member {

void
json_load(char *str, size_t len, void *p_member)
{
  dati *member = (dati*)p_member;

  json_scanf(str, len,
     "[user]%F"
     "[nick]%s"
     "[joined_at]%s"
     "[premium_since]%s"
     "[deaf]%b"
     "[mute]%b"
     "[pending]%b",
      &user::json_load, member->user,
      member->nick,
      member->joined_at,
      member->premium_since,
      &member->deaf,
      &member->mute,
      &member->pending);

  D_NOTOP_PUTS("Member object loaded with API response"); 
}

void
json_list_load(char *str, size_t len, void *p_members)
{
  struct sized_buffer **buf = NULL;
  json_scanf(str, len, "[]%A", &buf);

  size_t n = ntl_length((void**)buf);
  dati **new_members = (dati**)ntl_calloc(n, sizeof(dati*));
  for (size_t i=0; buf[i]; ++i) {
    new_members[i] = init();
    json_load(buf[i]->start, buf[i]->size, new_members[i]);
  }
  
  free(buf);

  *(dati ***)p_members = new_members;
}

dati*
init()
{
  dati *new_member = (dati*)calloc(1, sizeof *new_member);
  new_member->user = user::init();
  return new_member;
}

void
cleanup(dati *member) {
  user::cleanup(member->user);
  free(member);
}

void
list_cleanup(dati **members) {
  for (int i=0; members[i]; ++i) {
    cleanup(members[i]);
  }
  free(members);
}


//@todo modifiable query string parameters
dati**
get_list(client *client, const char guild_id[])
{
  if (IS_EMPTY_STRING(guild_id)) {
    D_PUTS("Missing 'guild_id'");
    return NULL;
  }

  dati **new_members = NULL;

  struct resp_handle resp_handle =
    {&json_list_load, (void*)&new_members};
  struct sized_buffer body = {NULL, 0};
  
  user_agent::run( 
    &client->ua,
    &resp_handle,
    &body,
    HTTP_GET, GUILD MEMBERS "?limit=100", guild_id);

  return new_members;
}

void remove(client *client, const char guild_id[], const char user_id[])
{
  if (IS_EMPTY_STRING(guild_id)) {
    D_PUTS("Can't delete message: missing 'guild_id'");
    return;
  }
  if (IS_EMPTY_STRING(user_id)) {
    D_PUTS("Can't delete message: missing 'user_id'");
    return;
  }

  struct resp_handle resp_handle = {NULL, NULL, NULL, NULL};
  struct sized_buffer body = {NULL, 0};

  user_agent::run(
    &client->ua,
    &resp_handle,
    &body,
    HTTP_DELETE, GUILD MEMBER, guild_id, user_id);
}

} // namespace member

namespace ban {

void
json_load(char *str, size_t len, void *p_ban)
{
  dati *ban = (dati*)p_ban;

  json_scanf(str, len,
     "[reason]%s"
     "[user]%F",
      ban->reason,
      &user::json_load, ban->user);

  D_NOTOP_PUTS("Member object loaded with API response"); 
}

void
json_list_load(char *str, size_t len, void *p_bans)
{
  struct sized_buffer **buf = NULL;
  json_scanf(str, len, "[]%A", &buf);

  size_t n = ntl_length((void**)buf);
  dati **new_bans = (dati**)ntl_calloc(n, sizeof(dati*));
  for (size_t i=0; buf[i]; ++i) {
    new_bans[i] = init();
    json_load(buf[i]->start, buf[i]->size, new_bans[i]);
  }
  
  free(buf);

  *(dati ***)p_bans = new_bans;
}

dati*
init()
{
  dati *new_ban = (dati*)calloc(1, sizeof *new_ban);
  new_ban->user = user::init();
  return new_ban;
}

void
cleanup(dati *ban) {
  user::cleanup(ban->user);
  free(ban);
}

void
list_cleanup(dati **bans) {
  for (int i=0; bans[i]; ++i) {
    cleanup(bans[i]);
  }
  free(bans);
}

void
get(client *client, const char guild_id[], const char user_id[], dati *p_ban)
{
  if (IS_EMPTY_STRING(guild_id)) {
    D_PUTS("Missing 'guild_id'");
    return;
  }
  if (IS_EMPTY_STRING(user_id)) {
    D_PUTS("Missing 'user_id'");
    return;
  }

  struct resp_handle resp_handle = {&json_load, (void*)p_ban};
  struct sized_buffer body = {NULL, 0};

  user_agent::run( 
    &client->ua,
    &resp_handle,
    &body,
    HTTP_GET, GUILD BAN, guild_id, user_id);
}

//@todo modifiable query string parameters
dati**
get_list(client *client, const char guild_id[])
{
  if (IS_EMPTY_STRING(guild_id)) {
    D_PUTS("Missing 'guild_id'");
    return NULL;
  }

  dati **new_bans = NULL;

  struct resp_handle resp_handle =
    {&json_list_load, (void*)&new_bans};
  struct sized_buffer body = {NULL, 0};
  
  user_agent::run( 
    &client->ua,
    &resp_handle,
    &body,
    HTTP_GET, GUILD BANS, guild_id);

  return new_bans;
}

} // namespace member

} // namespace guild
} // namespace discord
