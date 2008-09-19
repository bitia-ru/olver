#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "config.h"

#ifdef _WIN32
#  define FILE_SEPARATOR '\\'
#  define PATH_SEPARATOR ";"
#  define STRNICMP strnicmp
#else
#  define FILE_SEPARATOR '/'
#  define PATH_SEPARATOR ":"
#  define STRNICMP strncasecmp
#endif

/* Default config files suffix.  */
#define CONFIG_SUFFIX ".conf"

/* Current line number. */
int lineno;

static char* clone( const char* str )
{
  char* copy = (char *)malloc(strlen(str) + 1);
  strcpy(copy, str);
  return copy;
}

/* Substitute ${...} with a platform-dependent string. */
static char* replace( char* str )
{
  char* ret;
  char* p;
  int inside = 0;

  p = ret = (char *)malloc((strlen(str) + 1) * sizeof(char));
  while(*str != '\0') 
  {
    if(inside) 
    {
      if(*str == '}') 
      {
        inside = 0;
#ifdef _WIN32
        *p++ = '%';
#endif
        str++;
      } else {
        *p++ = *str++;
      }
    } else {
      if(*str == '$') 
      {
        str++;
        if(*str == '{') 
        {
          inside = 1;
#ifdef _WIN32
          *p++ = '%';
#else
          *p++ = '$';
#endif
          str++;
        } else {
          *p++ = '$';
          *p++ = *str++;
        }
      } else {
        *p++ = *str++;
      }
    }
  }

  if( inside )
  {
    fprintf(stderr, "Line %d: corresponding } is abscent\n", lineno );
    exit(3);
  }

  *p = '\0';
  ret = (char *)realloc(ret, strlen(ret) + 1);
  return ret;
}

static void append( char** str, char* append )
{
  int len = *str == NULL ? 0 : strlen(*str);
  *str = (char *)realloc(*str, (len + strlen(append) + 1) * sizeof(char));
  strcpy(*str + len, append);
}

static void usage( char* program_name )
{
  fprintf( stderr
         , "Usage: %s [--print-only] [PARAM]...\n"
           "Load configuration from file and launch Java VM with specified options.\n"
           "  --usage          print usage information\n"
           "  --print-only     don't make call actually, just print command to stdout\n"
           "  --config=FILE    load configuration from FILE\n"
           "\n"
           "By default, PARAMs are parameters for the application. But:\n"
           "PARAMs with -J prefix are attached to the VM (without -J suffix).\n"
           "PARAMs with -A prefix are attached to the application (without -A suffix).\n"
         , program_name
         );
  exit(1);
}


/* Section type. */
typedef enum 
{
  SECT_NONE = 0,
  SECT_MAIN,
  SECT_VM_PARAMS,
  SECT_APP_PARAMS,
  SECT_CLASSPATH
} section_t;

/* Get program name from argv[0]. Platform dependent. */
static char* get_program_name( char* argv0 )
{
  char* start = argv0 + strlen(argv0);

  /* Remove .exe suffix. */
  if( STRNICMP( start - 4, ".exe", 4 ) == 0 )
  {
    start -= 4;
    *start = '\0';
  }

  while( start != argv0 )
  {
    if( *(start - 1) == FILE_SEPARATOR ) break;
    start--;
  }

  if( strlen(start) == 0 )
  {
    fprintf( stderr, "Program name is empty.\n" );
    exit(1);
  }

  return start;
}

static char* get_program_path( char* argv0 )
{
  char* end;
  int empty = 1;

  argv0 = clone( argv0 );

  for( end = argv0 + strlen(argv0); argv0 <= end; end-- )
  {
    if( *end == FILE_SEPARATOR ) 
    {
        *end = '\0';
        empty = 0;
        break;
    }
  }

  if( empty || strlen(argv0) == 0 ) return clone( "." );

  return argv0;
}

/* Get line without newline character.  */
static char* getline( FILE * file )
{
  char * line = NULL;
  int c;
  size_t n = 0;

  while( (c = fgetc(file)) != EOF )
  {
    line = (char *)realloc(line, ++n * sizeof(char));
    if(c == '\n') break;
    line[n - 1] = (char)c;
  }

  if(line != NULL) line[n-1] = '\0';
  return line;
}

static char* shell_form( config_t* config )
{
  int i;
  char* shell = NULL;

  append( &shell, "java " );

  for( i = 0; i < config->vmparams_sz; i++ )
  {
#ifdef _WIN32
    append( &shell, "\"" );
#endif
    append( &shell, config->vmparams[i] );
#ifdef _WIN32
    append( &shell, "\" " );
#else
    append( &shell, " " );
#endif
  }

  if( config->classpath_sz != 0 )
  {
#ifdef _WIN32
    append( &shell, "-cp \"" );
#else
    append( &shell, "-cp " );
#endif

    for( i = 0; i < config->classpath_sz; i++ )
    {
      append( &shell, config->classpath[i] );
      if( i != config->classpath_sz - 1 ) append( &shell, PATH_SEPARATOR );
    }

#ifdef _WIN32
    append(&shell, "\" ");
#else
    append(&shell, " ");
#endif
  }

  append( &shell, config->mainclass );
  append( &shell, " " );

  for( i = 0; i < config->params_sz; i++ )
  {
    append( &shell, "\"" );
    append( &shell, config->params[i] );
    append( &shell, "\" " );
  }

  return shell;
}

int main( int argc, char** argv )
{
  int print_only = 0;
  int config_specified = 0;

  /* Current config file section.  */
  section_t section = SECT_NONE;

  /* Application's launch configuration.  */
  config_t config;

  /* Config file name. */
  char* config_name;

  /* Program name. */
  char* program_name;

  /* Application home. */
  char* apphome;

  /* Here-or-there-used variables:  */
  FILE* confile;
  char* line;
  char* lineptr;
  char* comment;
  int i;
  char* shell;
  char* end;
  char* apphomevar;

  /* Get program name.   */
  program_name = clone( get_program_name(argv[0]) );

  for( i = 1; i < argc; i++ )
  {
    if( !strcmp(argv[i], "--usage") ) usage( program_name );
    if(!strcmp(argv[i], "--print-only")) 
    {
      print_only = 1;
      argv[i] = NULL; /* Prevent from attaching to application.  */
    } else if( strstr(argv[i], "--config=") == argv[i] )
    {
      config_specified = 1;
      config_name = argv[i] + /* strlen("--config=") */ 9;
      argv[i] = NULL; /* Prevent from attaching to application.  */
    }
  }

  /* Generate config name if it was not specified.  */
  if( !config_specified )
  {
    config_name = malloc(strlen(argv[0]) + strlen(CONFIG_SUFFIX) + 1);
    strcpy(config_name, argv[0]);
    strcat(config_name, CONFIG_SUFFIX);
  }

  /* Open config file.  */
  if( (confile = fopen(config_name, "r")) == NULL )
  {
    fprintf(stderr, "Can not open config file '%s'\n", config_name);
    exit(1);
  }

  /* Initialize config struct.  */
  config_init( &config );

  /* Parse config file.  */
  while( (lineptr = line = getline(confile)) != NULL )
  {
    lineno++;

    /* Skip all whitespaces in the beginning of a line.  */
    while( *line == ' ' || *line == '\t' ) line++;

    /* Cut off comments. */
    if( (comment = strchr(line, '#')) != NULL ) *comment = '\0';

    /* Skip all trailing spaces. */
    for( end = line + strlen(line); line <= end; end-- )
    {
      if( *end == ' ' || *end == '\t' ) 
      {
        *end = '\0';
      } else {
        break;
      }
    }

    /* Skip empty lines. */
    if( strlen(line) == 0 ) continue;

    /* Parse section headers. */
    if( *line == '[' )
    {
      if(      !strcmp( line, "[mainclass]" ) ) section = SECT_MAIN;
      else if( !strcmp( line, "[vmparams]"  ) ) section = SECT_VM_PARAMS;
      else if( !strcmp( line, "[params]"    ) ) section = SECT_APP_PARAMS;
      else if( !strcmp( line, "[classpath]" ) )
      {
        section = SECT_CLASSPATH;
      } else {
        fprintf( stderr, "Line %d: unknown section %s\n", lineno, line );
        exit(3);
      }
      continue;
    }

    /* Parse section bodies.  */
    if( section == SECT_MAIN )
	{
      if( config.mainclass != NULL )
	  {
        fprintf( stderr, "Line %d: main class redefinition\n", lineno );
        exit(3);
      }
      config_set_mainclass(&config, clone(line));
    } else if( section == SECT_VM_PARAMS )
	{
      config_add_vmparam(&config, replace(line));
    } else if( section == SECT_APP_PARAMS )
	{
      config_add_param(&config, replace(line));
    } else if( section == SECT_CLASSPATH )
	{
      config_add_cp_entry(&config, replace(line));
    } else if( section == SECT_NONE )
	{
      fprintf( stderr, "Line %d: global section is not allowed\n", lineno );
      exit(3);
    }

    free( lineptr );
  }

  if( config.mainclass == NULL )
  {
    fprintf( stderr, "No main class specified\n" );
    exit(3);
  }

  /* Parse params from command line. */
  for( i = 1; i < argc; i++ )
  {
    if( argv[i] ) /* not [--print-only|--config=] */
    {
      if( (argv[i][0] == '-') && (argv[i][1] == 'J') )
      {
        config_add_vmparam( &config, clone(argv[i] + 2) );
      } else if( (argv[i][0] == '-') && (argv[i][1] == 'A') )
      {
        config_add_param( &config, clone(argv[i] + 2) );
      } else {
        config_add_param( &config, clone(argv[i]) );
      }
    }
  }

  shell = shell_form( &config );

  apphome = get_program_path( argv[0] );
  apphomevar = clone( "APPHOME=" );
  append( &apphomevar, apphome );

  if( print_only )
  {
    printf( "%s\n", apphomevar );
    printf( "%s\n", shell );
  } else {
    putenv( apphomevar );
    system( shell );
  }

  free( apphome );
  free( apphomevar );

  /* Free used memory. */
  config_free( &config );

  return 0;
}
