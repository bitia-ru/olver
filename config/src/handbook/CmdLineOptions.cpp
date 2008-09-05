#include <stdio.h>

#include "handbook/CmdLineOptions.h"


#include <string.h>

char	*optarg;		// global argument pointer
int		optind = 0; 	// global argv index
int     optopt = 0;

int getopt(int argc, char *argv[], char *optstring)
{
	static char *next = NULL;
	if (optind == 0)
		next = NULL;

	optarg = NULL;

	if (next == NULL || *next == '\0' )
	{
		if (optind == 0)
			optind++;

		if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0')
		{
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		if (strcmp(argv[optind], "--") == 0)
		{
			optind++;
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		next = argv[optind];
		next++;		// skip past -
		optind++;
	}

	char c = *next++;
	char *cp = strchr(optstring, c);

	if (cp == NULL || c == ':')
		return '?';

	cp++;
	if (*cp == ':')
	{
		if (*next != '\0')
		{
			optarg = next;
			next = NULL;
		}
		else if (optind < argc)
		{
			optarg = argv[optind];
			optind++;
		}
		else
		{
			return '?';
		}
	}

	return c;
}

/*

 * CommandLineOptions

 */

CommandLineOptions::CommandLineOptions()

{

	makeDefaultConfiguration = false;

	checkConfiguration = false;

	generateHeaders = false;

	configurationPath = 0;

	defaultConfigurationPath = 0;

	headerRootDir = 0;

	testPlanPath = 0;

	runScriptPath = 0;

	missingFunctionsPath = 0;

    olverTreeName = 0;

    verbose = 0;
}



bool CommandLineParser::parse(int argc, char** argv, CommandLineOptions& opts)

{

    int c;

    int errflg = 0;

    extern char *optarg;

    extern int optind, optopt;

    

    while ((c = getopt(argc, argv, ":d:c:gh:t:r:m:o:x:v")) != -1) {

        switch(c) {

        case 'd':

    		opts.makeDefaultConfiguration = true;

    		opts.defaultConfigurationPath = optarg;

            break;

        case 'c':

    		opts.checkConfiguration = true;

    		opts.configurationPath = optarg;

            break;

        case 'g':

        	opts.generateHeaders = true;

        	break;

        case 'h':

    		opts.headerRootDir = optarg;

            break;        	

        case 't':

    		opts.testPlanPath = optarg;

            break;        	

        case 'r':

    		opts.runScriptPath = optarg;

            break;        	

        case 'm':

    		opts.missingFunctionsPath = optarg;

            break;        	            

        case 'o':

    		opts.olverTreeName = optarg;

            break;        	            

        case 'x':

    		opts.makeXML = optarg;

            break;        	            

        case 'v':

    		opts.verbose = 1;

            break;        	            

        case ':':       /* -d or -c without operand */

                    fprintf(stdout,

                            "Option -%c requires an operand\n", optopt);

                    errflg++;

                    break;

        case '?':

                    fprintf(stdout,

                            "Unrecognized option: -%c\n", optopt);

            		errflg++;

        }

    }

    if (errflg) {

        fprintf(stderr, "usage: . . . ");

        return false;

    }

    /*

    for ( ; optind < argc; optind++) {

        if (access(argv[optind], R_OK)) {

        }

    }*/

    

    return true;

}

