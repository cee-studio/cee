#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "libdiscord.h"
#include "orka-utils.h" // for orka_timestamp_ms()

#define JSON_FILE "bot-presence.json"

void on_ready(struct discord_client *client, const struct discord_user_dati *me) {
  fprintf(stderr, "\n\nPresence-Bot succesfully connected to Discord as %s#%s!\n\n",
      me->username, me->discriminator);
}

void
load_presence_from_json(struct discord_client *client, char filename[])
{
  /* get contents of file to string */
  size_t len;
  char *json_payload = orka_load_whole_file(filename, &len);

  struct discord_presence_dati *new_presence = discord_presence_dati_alloc();
  discord_presence_dati_from_json(json_payload, len, new_presence);

  discord_replace_presence(client, new_presence);

  free(json_payload);
}

int main(int argc, char *argv[])
{
  const char *config_file;
  if (argc > 1)
    config_file = argv[1];
  else
    config_file = "bot.config";

  discord_global_init();

  struct discord_client *client = discord_config_init(config_file);
  assert(NULL != client);

  printf("\n\nThis bot demonstrates how easy it is to change presence"
         " from a json file.\n"
         "1. Edit 'bot-presence.json' to change how presence is"
         " displayed.\n"
         "\nTYPE ANY KEY TO START BOT\n");
  fgetc(stdin); // wait for input

  load_presence_from_json(client, JSON_FILE);
  discord_run(client);

  discord_cleanup(client);

  discord_global_cleanup();
}

