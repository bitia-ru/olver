#ifndef CMDLINEOPTIONS_H_
#define CMDLINEOPTIONS_H_

/*
 * CommandLineOptions
 */ 
class CommandLineOptions
{
public:
	CommandLineOptions();
public:
	bool makeDefaultConfiguration;
	bool checkConfiguration;
	bool generateHeaders;
    int verbose;
	char* configurationPath;
	char* defaultConfigurationPath;
	char* headerRootDir;
	char* testPlanPath;
	char* runScriptPath;
	char* missingFunctionsPath;
    char* olverTreeName;
    char* makeXML;
};

/*
 * CommandLineParaser
 */ 


class CommandLineParser
{
public:
	static bool parse(int argc, char** argv, CommandLineOptions& opts);
};

#endif /*CMDLINEOPTIONS_H_*/
