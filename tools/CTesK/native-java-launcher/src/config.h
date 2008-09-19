#ifndef CONFIG_H
#define CONFIG_H

/* Application's configuration.  */
typedef struct {
  /* Java class to execute.  */
  char * mainclass;

  /* Array of classpath entries.  */
  char ** classpath;
  int classpath_sz;

  /* Array of VM parameters.  */
  char ** vmparams;
  int vmparams_sz;

  /* Array of application parameters.  */
  char ** params;
  int params_sz;
} config_t;

void config_init(config_t * config);
void config_set_mainclass(config_t * config, char * name);
void config_add_cp_entry(config_t * config, char * entry);
void config_add_vmparam(config_t * config, char * param);
void config_add_param(config_t * config, char * param);
void config_free(config_t * config);

#endif /* CONFIG_H */
