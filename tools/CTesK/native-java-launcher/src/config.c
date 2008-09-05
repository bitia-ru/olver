#include <stdlib.h>
#include "config.h"

void config_init(config_t * config)
{
  config->mainclass = NULL;

  config->classpath = NULL;
  config->classpath_sz = 0;

  config->vmparams = NULL;
  config->vmparams_sz = 0;

  config->params = NULL;
  config->params_sz = 0;
}

void config_set_mainclass(config_t * config, char * str)
{
  config->mainclass = str;
}

void config_add_cp_entry(config_t * config, char * str)
{
  config->classpath_sz++;
  config->classpath = (char **)realloc(config->classpath,
    config->classpath_sz * sizeof(char *));
  config->classpath[config->classpath_sz - 1] = str;
}

void config_add_vmparam(config_t * config, char * str)
{
  config->vmparams_sz++;
  config->vmparams = (char **)realloc(config->vmparams,
    config->vmparams_sz * sizeof(char *));
  config->vmparams[config->vmparams_sz - 1] = str;
}

void config_add_param(config_t * config, char * str)
{
  config->params_sz++;
  config->params = (char **)realloc(config->params,
    config->params_sz * sizeof(char *));
  config->params[config->params_sz - 1] = str;
}

void config_free(config_t * config)
{
  int i;

  for(i = 0; i < config->classpath_sz; i++)
    free(config->classpath[i]);
  free(config->classpath);
  for(i = 0; i < config->vmparams_sz; i++)
    free(config->vmparams[i]);
  free(config->vmparams);
  free(config->mainclass);
  for(i = 0; i < config->params_sz; i++)
    free(config->params[i]);
  free(config->params);
}
