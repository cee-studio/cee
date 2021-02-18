#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <libdiscord.h>
#include "orka-utils.h" // for orka_timestamp_ms()

using namespace discord;

#define JSON_FILE "bot-presence.json"

void on_ready(client *client, const user::dati *me)
{
  fprintf(stderr, "\n\nPresence-Bot succesfully connected to Discord as %s#%s!\n\n",
      me->username, me->discriminator);

  (void)client;
}

void
load_presence_from_json(client *client, char filename[])
{
  using namespace presence;
  
  FILE *fp = fopen(filename, "r");
  ASSERT_S(NULL != fp,
      "Couldn't find " JSON_FILE " at working directory");

  /* get file size */
  fseek(fp, 0L, SEEK_END);
  size_t fsize = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  /* get contents of file to string */
  char *json_payload = (char*)malloc(fsize+1);
  fread(json_payload, sizeof(char), fsize, fp);

  dati *new_presence = alloc_dati();
  from_json(json_payload, fsize, (void*)new_presence);

  replace_presence(client, new_presence);

  free(json_payload);
  fclose(fp);
}

int main(int argc, char *argv[])
{
  const char *config_file;
  if (argc > 1)
    config_file = argv[1];
  else
    config_file = "bot.config";

  global_init();

  client *client = fast_init(config_file);
  assert(NULL != client);

  printf("\n\nThis bot demonstrates how easy it is to change presence"
         " from a json file.\n"
         "1. Edit 'bot-presence.json' to change how presence is"
         " displayed.\n"
         "\nTYPE ANY KEY TO START BOT\n");
  fgetc(stdin); // wait for input

  load_presence_from_json(client, JSON_FILE);
  run(client);

  cleanup(client);

  global_cleanup();
}
