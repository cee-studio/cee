#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libdiscord.h"


void on_ready(struct discord *client, const struct discord_user *me) {
  fprintf(stderr, "\n\nPingPong-Bot succesfully connected to Discord as %s#%s!\n\n",
      me->username, me->discriminator);
}

void on_ping(
  struct discord *client,
  const struct discord_user *me,
  const struct discord_message *msg)
{
  // make sure bot doesn't echoes other bots
  if (msg->author->bot)
    return;

  struct discord_channel_create_message_params params = {.content = "pong"};
  discord_create_message(client, msg->channel_id, &params, NULL);
}

void on_pong(
    struct discord *client,
    const struct discord_user *me,
    const struct discord_message *msg)
{
  // make sure bot doesn't echoes other bots
  if (msg->author->bot)
    return;

  struct discord_channel_create_message_params params = {.content = "ping"};
  discord_create_message(client, msg->channel_id, &params, NULL);
}

int main(int argc, char *argv[])
{
  const char *config_file;
  if (argc > 1)
    config_file = argv[1];
  else
    config_file = "bot.config";

  discord_global_init();

  struct discord *client = discord_config_init(config_file);
  assert(NULL != client);

  discord_setcb(client, READY, &on_ready);
  discord_setcb_command(client, "ping", &on_ping);
  discord_setcb_command(client, "pong", &on_pong);

  discord_run(client);

  discord_cleanup(client);

  discord_global_cleanup();
}
