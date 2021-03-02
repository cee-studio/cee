#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "github-v3.hpp"
#include "orka-utils.h"


namespace git = github::v3::git_op;

static
void print_usage (char * prog)
{
  fprintf(stderr, "Usage: %s [-c config] [-m <commit-message>] file file ...\n",
          prog);
  exit(EXIT_FAILURE);
}

int main (int argc, char ** argv)
{
  int opt;
  char * commit_msg = NULL, * config_file = NULL;

  while ((opt = getopt(argc, argv, "c:m:")) != -1) {
    switch (opt) {
      case 'c':
        config_file = strdup(optarg);
        break;
      case 'm':
        commit_msg = strdup(optarg);
        break;
      default: /* '?' */
        print_usage(argv[0]);
    }
  }

  if (NULL == config_file) {
    fprintf(stderr, "Using .cee-contributor as the user config\n");
    config_file = ".cee-contributor";
  }
  else if (NULL == commit_msg) {
    fprintf(stderr, "Please specify: -m \"commit message\"\n");
    exit(EXIT_FAILURE);
  }
  else if (optind >= argc) {
    fprintf(stderr, "Expected files\n");
    exit(EXIT_FAILURE);
  }


  git::file ** files = NULL;
  files = (git::file **) ntl_calloc(argc - optind, sizeof(git::file));
  for (int i = 0; files[i]; ++i)
    files[i]->path = argv[optind + i];

  curl_global_init(CURL_GLOBAL_ALL);

  struct orka_config config;
  memset(&config, 0, sizeof(config));
  orka_config_init(&config, "GIT HTTP", config_file);
  char *username = orka_config_get_field(&config, "github.username");
  char *token = orka_config_get_field(&config, "github.token");

  git::dati *data = git::init(username, token, ".cee-repo");

  git::update_my_fork(data);
  git::create_blobs(data, files);
  char * head_commit_sha = git::get_head_commit(data);
  char * base_tree_sha = git::get_tree_sha(data, head_commit_sha);
  char * tree_sha = git::create_tree(data, base_tree_sha, files);
  char * commit_sha =
    git::create_a_commit(data, tree_sha, head_commit_sha, commit_msg);

  char new_branch[256];
  snprintf(new_branch, sizeof(new_branch), "n%ld", time(NULL));
  git::create_a_branch(data, head_commit_sha, new_branch);
  git::update_a_commit(data, new_branch, commit_sha);
  git::create_a_pull_request(data, new_branch, commit_msg);
  return 0;
}
