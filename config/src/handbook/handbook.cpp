#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// configuration
#include "configuration/configcommon.h"
#include "configuration/ConfigFile.h"
#include "configuration/ConfigReader.h"
#include "configuration/ConfigWriter.h"

// test plan
#include "testplan/testplancommon.h"
#include "testplan/TestPlan.h"
#include "testplan/TestPlanReader.h"

// deptree
#include "deptree/deptreelib.h"
#include "deptree/DepTree.h"
#include "deptree/DepTreeReader.h"
#include "deptree/DepTreeXMLWriter.h"

// command line
#include "handbook/CmdLineOptions.h"

// configuration
bool checkConfiguration(ConfigFile& configFile);
bool checkConfigurationForward(ConfigFile &configFile);
bool checkConfigurationBackward(ConfigFile &configFile);
bool makeDefaultConfiguration(ConfigFile &configFile);

// headers
bool generateHeaders(ConfigFile &configFile);
bool generateHeaderEntry(ConfigValue &cv, OptDefinition* od);
bool deleteOldHeaders();

// test plan
bool checkTestPlan(TestPlan& testPlan);
bool checkScenarios(TestPlan& testPlan);
bool checkMissingFunctions(TestPlan& testPlan);
bool generateRunScript(TestPlan& testPlan);
void addAllNestedScenarios(DepDefinition* depDefinition, TestPlan& testPlan);
void addAllNestedFunctions(DepDefinition* depDefinition, TestPlan& testPlan, string scenario);

// init
bool initialize();
bool finalize();

// print
void printDepTree();


DepTreeReader reader;
DepTree* depTree = 0;
CommandLineOptions opts;

set<string> TmpFiles;
#define CMPBUF_SIZE 256
static char cmpbuf1[CMPBUF_SIZE];
static char cmpbuf2[CMPBUF_SIZE];

int main(int argc, char** argv)
{
    bool result = false;
	if (CommandLineParser::parse(argc, argv, opts))
	{
        if (!opts.olverTreeName)
        {
            printf("Use -o <..path..olver.tree>\n");
            return 0;
        }
		if (!initialize())
		{
			finalize();
			return -1;
		}

		if (opts.checkConfiguration)
		{
			ConfigFile configFile;
			
			if (checkConfiguration(configFile))
			{
				if (opts.generateHeaders)
				{
					result = generateHeaders(configFile);
				}
			}
		}

		if (opts.makeDefaultConfiguration)
		{
			ConfigFile defaultConfigFile;
			
			if (makeDefaultConfiguration(defaultConfigFile))
			{
				if (opts.generateHeaders)
				{
					result = generateHeaders(defaultConfigFile);
				}			
			}
		}
		
		if (opts.testPlanPath)
		{
			TestPlan testPlan;
			
			//printDepTree();
			
			if (checkTestPlan(testPlan))
			{
				result = generateRunScript(testPlan);			
			}
		}
        
        if (opts.makeXML)
        {
            DepTreeXMLWriter writer;
            result = writer.write(opts.makeXML, depTree);
        }

		finalize();
		
		printf("Done\n");
	}
	else
	{
		return -1;
	}

    if(!result)
        return -1;

    return 0;
}

string ChangeFileExt(string filename, string newExt)
{
    int p = filename.find_last_of(".");

    return filename.substr(0, p)+(string)"."+newExt;
}

bool deleteOldHeaders()
{
	typedef map<string, int, less<string> > FileMap;
	
	FileMap fileNames;
	
	int optionCount = depTree->getOptionCount();
	
	for(int i = 0; i < optionCount; i++)
	{
		OptDefinition* od = depTree->getOptionAt(i);
		fileNames[od->getDestinationFile()] = 1;
	}
	
	for (FileMap::iterator it = fileNames.begin(); it != fileNames.end(); it++)
	{
		//string fileName = (string)opts.headerRootDir + "/" + (*it).first;
        //string fileNameC = (string)opts.headerRootDir + "/" + ChangeFileExt((*it).first,"c");

		string fileNameTmp = (string)opts.headerRootDir + "/" + (*it).first + ".tmp";
        string fileNameCTmp = (string)opts.headerRootDir + "/" + ChangeFileExt((*it).first,"c") + ".tmp";

        /*
		printf("Removing %s...", fileName.c_str());
		if (remove(fileName.c_str()))
			printf("Fail\n");
		else
			printf("Ok\n");

        printf("Removing %s...", fileNameC.c_str());
		if (remove(fileNameC.c_str()))
			printf("Fail\n");
		else
			printf("Ok\n"); 
        */

		if(opts.verbose) printf("Removing '%s'... ", fileNameTmp.c_str());
		if (remove(fileNameTmp.c_str()))
        {
            if(opts.verbose) printf("Fail\n");
        }
		else
        {
			if(opts.verbose) printf("Ok\n");
        }

        if(opts.verbose) printf("Removing '%s'... ", fileNameCTmp.c_str());
		if (remove(fileNameCTmp.c_str()))
        {
			if(opts.verbose) printf("Fail\n");
        }
		else
        {
			if(opts.verbose) printf("Ok\n");
        }
    }
	
	string fileNameLoader =  (string)opts.headerRootDir + "/config/config_loader_gen.h.tmp";
    if(opts.verbose) printf("Removing '%s'... ", fileNameLoader.c_str());
    if (remove(fileNameLoader.c_str()))
    {
		if(opts.verbose) printf("Fail\n");
    }
	else
    {
		if(opts.verbose) printf("Ok\n");
    }

	return true;
}

bool generateHeaderEntry(ConfigValue &cv, OptDefinition *od)
{
	FILE *f = NULL;
    FILE *fc = NULL;
    FILE *fld = NULL;

    if(opts.verbose) printf("Generating header entry: %s.%s\n", cv.getScopeName().c_str(), cv.getOptionName().c_str());

	string fileName  = (string)opts.headerRootDir + "/" + od->getDestinationFile();
	//string fileNameC = (string)opts.headerRootDir + "/" + ChangeFileExt(od->getDestinationFile(), "c");

	string fileNameTmp  = (string)opts.headerRootDir + "/" + od->getDestinationFile() +".tmp";
	string fileNameCTmp = (string)opts.headerRootDir + "/" + ChangeFileExt(od->getDestinationFile(), "c") +".tmp";
 
    string fileNameLoader = (string)opts.headerRootDir + "/config/config_loader_gen.h.tmp";

    if(od->getKind() == KindVariable)
    {
        if(opts.verbose) printf("Files: %s; %s\n", fileNameTmp.c_str(), fileNameCTmp.c_str() );

        f = fopen(fileNameTmp.c_str(), "at");
        fc = fopen(fileNameCTmp.c_str(), "at");
        fld = fopen(fileNameLoader.c_str(), "at");
    
        if(f && fc && fld)
        {
            if( !fseek(fc, 0, SEEK_END) )
            {
                size_t fileSize = ftell(fc);

                if(fileSize == 0)
                {
                    fprintf(fc, "#include \"%s\"\n\n", od->getDestinationFile().c_str());
                }
            }
            else
            {
                printf("generateHeaderEntry: can't fseek(fc, 0, SEEK_END).");
                return false;
            }
		    
            fprintf(f, "// %s\n", od->getDescription().c_str());
		    
            if (od->getType() == OptBool)
		    {
                OptValue * opt_value = od->getValueByName(cv.getValue());
                if(opt_value == NULL)
                    return false;
                fprintf(fc, "int %s = %d;\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->value);
			    fprintf(f, "extern int %s;\n\n", cv.getOptionName().c_str() );
                fprintf(fld,"{extern int %s;\nGET_BOOL_VALUE(%s);}\n", cv.getOptionName().c_str(), cv.getOptionName().c_str());
		    }
		    else
		    if (od->getType() == OptInt)
		    {
        	    fprintf(fc, "int %s = %d;\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->value);
                fprintf(f, "extern int %s;\n\n", cv.getOptionName().c_str() );
                fprintf(fld,"{extern int %s;\nGET_INT_VALUE(%s);}\n", cv.getOptionName().c_str(), cv.getOptionName().c_str());
		    }
		    else
		    if (od->getType() == OptSet)
		    {
			    // generate enumeration first
			    fprintf(f, "%s\n\n", od->generateEnumeration().c_str());	
			    
                //OptValue * opt_value = od->getValueByEnumeration(cv.getValue());
                //if(opt_value == NULL) return false;

                fprintf(fc, "int %s = %s;\n\n", cv.getOptionName().c_str(), cv.getValue().c_str());
                fprintf(f, "extern int %s;\n\n", cv.getOptionName().c_str() );			
                fprintf(fld,"{extern int %s;\nGET_INT_VALUE(%s);}\n", cv.getOptionName().c_str(), cv.getOptionName().c_str());
		    }
		    if (od->getType() == OptString)
		    {
                if (od->getValueByName(cv.getValue())->value == 0)
                {
                    fprintf(fc, "const char * %s = %s;\n\n", cv.getOptionName().c_str(), "NULL");			
                }
                else
                {
                    fprintf(fc, "const char * %s = \"%s\";\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->name.c_str());			
                }

                fprintf(f, "extern const char * %s;\n\n", cv.getOptionName().c_str() );
                fprintf(fld,"{extern const char * %s;\nGET_STR_VALUE(%s);}\n", cv.getOptionName().c_str(), cv.getOptionName().c_str());
		    }	
        }
        else
        {
            if(!f)
                printf("Can't open file: %s\n", fileNameTmp.c_str() );
            if(!fc)
                printf("Can't open file: %s\n", fileNameCTmp.c_str() );
            return false;
        }
    }
    else 
    {
        f = fopen(fileNameTmp.c_str(), "at");
        
        if(f)
        {
            if(opts.verbose) printf("File: %s\n", fileNameTmp.c_str() );
            
            fprintf(f, "// %s\n", od->getDescription().c_str());

		    if (od->getType() == OptBool)
		    {
			    fprintf(f, "#define %s %d\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->value);
		    }
		    else
		    if (od->getType() == OptInt)
		    {
			    fprintf(f, "#define %s %d\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->value);
		    }
		    else
		    if (od->getType() == OptSet)
		    {
			    // generate enumeration first
			    fprintf(f, "%s\n\n", od->generateEnumeration().c_str());	
			    
			    fprintf(f, "#define %s %s\n\n", cv.getOptionName().c_str(), od->getValueByValue(cv.getValue())->enumeration.c_str());			
		    }
		    if (od->getType() == OptString)
		    {
			    fprintf(f, "#define %s \"%s\"\n\n", cv.getOptionName().c_str(), od->getValueByName(cv.getValue())->name.c_str());			
		    }	
        }
        else
        {
            printf("Can't open file: %s\n", fileNameTmp.c_str() );
            return false;
        }
    }

    if(f)
    {
        TmpFiles.insert(fileNameTmp);
        fclose(f);
    }
    if(fc)
    {
        TmpFiles.insert(fileNameCTmp);
        fclose(fc);
    }
    if(fld)
    {
        TmpFiles.insert(fileNameLoader);
        fclose(fld);
    }

	return true;
}

bool generateHeaders(ConfigFile &configFile)
{
	printf("Generating headers...\n");
	
	bool result = true;	
	
	for (int i = 0; i < depTree->getOptionCount(); i++)
	{
		depTree->getOptionAt(i)->setAlreadyGenerated(false);
	}
	
	if (deleteOldHeaders())
	{
		int configValueCount = configFile.getConfigValueCount();
        for (int i = 0; i < configValueCount; i++)
		{
			ConfigValue& cv = configFile.getConfigValueAt(i);
            OptDefinition* od = depTree->findOption(cv.getScopeName(), cv.getOptionName());
			if (od)
			{
                if (od->isAlreadyGenerated() == false)
				{
					if (!generateHeaderEntry(cv, od))
					{
						result = false;
                        break;
					}
					od->setAlreadyGenerated(true);
				}
			}
			else
			{
				printf("Unknown option: %s.%s\n", cv.getScopeName().c_str(), cv.getOptionName().c_str());
				result = false;	
                break;
			}
		}
	}
	else
	{
		result = false;
	}

    // replace modified files
    if(result)
    {
        set<string>::iterator it;
        for(it = TmpFiles.begin(); it != TmpFiles.end(); it++)
        {
            bool identical = true;
            string fnametmp = *it;
            string fname = fnametmp.substr(0,fnametmp.find_last_of("."));
            
            if(opts.verbose) printf("Comparing %s -?- %s\n", fnametmp.c_str(), fname.c_str() );

            FILE * ft = fopen(fnametmp.c_str(), "rt");
            FILE * fe = fopen(fname.c_str(), "rt");
            
            if(ft && fe)
            {
                fseek(ft, 0, SEEK_END);
                size_t ftSize = ftell(ft);

                fseek(fe, 0, SEEK_END);
                size_t feSize = ftell(fe);
            
                if(ftSize != feSize)
                {
                    if(opts.verbose) printf("Sizes differ. %d != %d\n", ftSize, feSize);
                    identical = false;
                }
                else
                {
                    fseek(ft, 0, SEEK_SET);
                    fseek(fe, 0, SEEK_SET);
                
                    while(!feof(ft) && !feof(fe))   
                    {
                        size_t rsz1 = fread(cmpbuf1, 1, CMPBUF_SIZE, ft);
                        size_t rsz2 = fread(cmpbuf2, 1, CMPBUF_SIZE, fe);

                        if(rsz1 != rsz2)
                        {
                            if(opts.verbose) printf("Read failure.\n");
                            identical = false;
                            break;
                        }

                        if(memcmp(cmpbuf1, cmpbuf2, rsz1))
                        {
                            if(opts.verbose) printf("Binary difference at %d.\n", ftell(fe));
                            identical = false;
                            break;
                        }
                    }
                    if(!feof(ft) || !feof(fe))
                    {
                        if(opts.verbose) printf("Read failure at the end of file.\n");
                        identical = false;
                    }
                }
            }
            else
            {
                if(!fe)
                {
                    if(opts.verbose) printf("File %s does not exists.\n", fname.c_str());
                }

                identical = false;
            }

            if(ft)
                fclose(ft);
            if(fe)
                fclose(fe);

            if(!identical)
            {
                if(opts.verbose) printf("Non-identical.\n");
                if(opts.verbose) printf("Removing %s... ", fname.c_str());
                if( remove(fname.c_str()) )
                {
                    if(opts.verbose) printf("Fail.\n");
                }
                else
                {
                    if(opts.verbose) printf("Ok.\n");
                }

                printf("Replacing %s... ", fname.c_str());
                if( rename(fnametmp.c_str(), fname.c_str()) )
                {
                    printf("Fail.\n");
                }
                else
                {
                    printf("Ok.\n");
                }
            }
            else
            {
                if(opts.verbose) printf("Identical!\n");
            }
        }
    }

    // delete tmp files
    {
        set<string>::iterator it;
        for(it = TmpFiles.begin(); it!=TmpFiles.end(); it++)
        {
            string fname = *it;
            if(opts.verbose) printf("Removing %s... ", fname.c_str());
            if( remove(fname.c_str()) ) 
            {
                if(opts.verbose) printf("Fail.\n");
            }
            else
            {
                if(opts.verbose) printf("Ok.\n");
            }
        }
    }

	if (result)
	{
		printf("Ok\n");
	}
	else
	{
		printf("Error during generation of headers\n");
	}
	return result;	
}

bool checkConfigurationForward(ConfigFile &configFile)
{
	bool result = true;	
	int configValueCount = configFile.getConfigValueCount();
	for (int i = 0; i < configValueCount; i++)
	{
		ConfigValue& cv = configFile.getConfigValueAt(i);
		if (!depTree->hasOption(cv.getScopeName(), cv.getOptionName()))
		{
			printf("Unknown option: %s.%s\n", cv.getScopeName().c_str(), cv.getOptionName().c_str());
			result = false;
		}
	}
	return result;
}

bool checkConfigurationBackward(ConfigFile &configFile)
{
	bool result = true;
	int scopeCount = depTree->getScopeCount();
	for (int i = 0; i < scopeCount; i++)
	{
		OptScope *os = depTree->getScopeAt(i);
		int optionCount = os->getOptionCount();
		for (int j = 0; j < optionCount; j++)
		{
			OptDefinition* od = os->getOptionAt(j);
			if (!configFile.hasConfigValue(os->getName(), od->getName()))
			{
				printf("Option not found: %s.%s\n", os->getName().c_str(), od->getName().c_str());
				result = false;
			}
		}
	}
	
	return result;
}

bool checkConfiguration(ConfigFile &configFile)
{
	bool result = true;
	
	ConfigReader configReader;

	printf("Checking configuration \"%s\"...\n", opts.configurationPath);

	if (configReader.read(opts.configurationPath, configFile))
	{
		result = checkConfigurationForward(configFile);
		result = checkConfigurationBackward(configFile) ? result : 0;	
	}
	else
	{
        printf("configReader has failed.\n");
		result = false;
	}

	if (result)
	{
		printf("Ok\n");
	}
	else
	{
		printf("Error during configuration check\n");
	}
	
	return result;	
}

bool makeDefaultConfiguration(ConfigFile &configFile)
{
	ConfigWriter configWriter;

	printf("Making default configuration \"%s\"...\n", opts.defaultConfigurationPath);
	   
	int scopeCount = depTree->getScopeCount();
    for (int i = 0; i < scopeCount; i++)
	{
		OptScope *os = depTree->getScopeAt(i);
		int optionCount = os->getOptionCount();
		for (int j = 0; j < optionCount; j++)
		{
			OptDefinition* od = os->getOptionAt(j);	
			
			if (od->getType() == OptBool)
			{
				ConfigValue cv(os->getName(), od->getName(), od->getDefaultValue()->name);
				configFile.addConfigValue(cv);
			}
			else
			if (od->getType() == OptInt)
			{
				ConfigValue cv(os->getName(), od->getName(), od->getDefaultValue()->name);
				configFile.addConfigValue(cv);
			
			}
			else
			if (od->getType() == OptSet)
			{
                char str_[16];
                sprintf(str_,"%d",od->getDefaultValue()->value);
                string s(str_);
				ConfigValue cv(os->getName(), od->getName(), s); //od->getDefaultValue()->enumeration
				configFile.addConfigValue(cv);
			}
			else
			if (od->getType() == OptString)
			{
				ConfigValue cv(os->getName(), od->getName(), od->getDefaultValue()->name);
				configFile.addConfigValue(cv);
			}
		}
	}

	if (configWriter.write(opts.defaultConfigurationPath, configFile))
	{
		printf("Ok\n");
		return true;
	}
	else
	{
		printf("Error during default configuration making");		
		return false;
	}
}

bool checkTestPlan(TestPlan& testPlan)
{
	if (checkScenarios(testPlan))
	{
		return checkMissingFunctions(testPlan);
	}
	else
	{
		return false;
	}
}

bool checkScenarios(TestPlan &testPlan)
{
	bool result = true;
	
	TestPlanReader testPlanReader;

	printf("Checking scenarios \"%s\"...\n", opts.testPlanPath);
	
	if (testPlanReader.read(opts.testPlanPath, testPlan))
	{
		for (int i = 0; i < testPlan.getEntryCount(); i++)
		{
			TestPlanEntry entry = testPlan.getEntryAt(i);
			//printf("%s", entry.toString().c_str());
			
			if (entry.cluster == "*")
			{
				addAllNestedScenarios(&depTree->getRoot(), testPlan);
			}
			else
			{
				DepDefinition* clusterDefinition = depTree->getRoot().getDefinition(entry.cluster, DepCluster);			
				if (clusterDefinition)
				{
					if (entry.subsystem == "*")
					{
						addAllNestedScenarios(clusterDefinition, testPlan);
					}
					else
					{
						DepDefinition* subsystemDefinition = clusterDefinition->getDefinition(entry.subsystem, DepSubsystem);				
						if (subsystemDefinition)
						{
							if (entry.group == "*")
							{
								addAllNestedScenarios(subsystemDefinition, testPlan);
							}
							else
							{
								DepDefinition* groupDefinition = subsystemDefinition->getDefinition(entry.group, DepGroup);											
								if (groupDefinition)
								{
									if (entry.scenario == "*")
									{
										addAllNestedScenarios(groupDefinition, testPlan);
									}
									else
									{
										DepDefinition* scenarioDefinition = groupDefinition->getDefinition(entry.scenario, DepScenario);																				
										if (scenarioDefinition)
										{
											testPlan.addScenario(scenarioDefinition->getName());
											addAllNestedFunctions(scenarioDefinition, testPlan, scenarioDefinition->getName());
										}
										else
										{
											printf("Unknown scenario: %s\n", entry.scenario.c_str());
											result = false;
										}
									}
								}
								else
								{
									printf("Unknown group: %s\n", entry.group.c_str());
									result = false;
								}
							}
						}
						else
						{
							printf("Unknown subsystem: %s\n", entry.subsystem.c_str());
							result = false;
						}
					}
				}
				else
				{
					printf("Unknown cluster: %s\n", entry.cluster.c_str());
					result = false;
				}
			}
		}			
	}
	else
	{
		result = false;
	}

	if (result)
	{
		printf("Ok\n");
	}
	else
	{
		printf("Error during scenario check\n");
	}
	
	return result;	
}

bool checkMissingFunctions(TestPlan &testPlan)
{
	bool result = true;
		
	printf("Checking functions \"%s\"...\n", opts.missingFunctionsPath);	
	
	if (opts.missingFunctionsPath)
	{
		FILE *f = fopen(opts.missingFunctionsPath, "rt");	
		if (f)
		{
			char buffer[64];
			
			while(!feof(f) && fscanf(f, "%s\n", buffer))
			{
				vector<string> deps = testPlan.getDependentScenarios(buffer);
				for(int i = 0; i < deps.size(); i++)
				{
					printf("Scenario '%s' depends on '%s' function that is not supported by the target\n", deps[i].c_str(), buffer);
					result = false;
				}
			}
			
			fclose(f);
		}
		else
		{
			result = false;
		}
	}

	if (result)
	{
		printf("Ok\n");
	}
	else
	{
		printf("Error during function check\n");
	}
	
	return result;
}

bool generateRunScript(TestPlan& testPlan)
{
	printf("Generating run script %s...\n", opts.runScriptPath);
	
	FILE* f = fopen(opts.runScriptPath, "wt");
	
	if (f) 
	{
		for(int i = 0; i < testPlan.getScenarioCount(); i++)
		{
			fprintf(f, "run %s\n", testPlan.getScenarioAt(i).c_str());
		}
		
		fclose(f);
		printf("Ok\n");
	}
	else
	{
		printf("Error during run script creation\n");
	}

    return true;
}

void addAllNestedScenarios(DepDefinition* depDefinition, TestPlan& testPlan)
{
	if (depDefinition->getType() == DepRoot)
	{
		for(int i = 0; i < depDefinition->getDefinitionCount(); i++)
		{
			DepDefinition* definition = depDefinition->getDefinitionAt(i);
			if (definition->getType() == DepScenario)
			{
				testPlan.addScenario(definition->getName());
				addAllNestedFunctions(definition, testPlan, definition->getName());	
			}
		}
	}	
	else
	if (depDefinition->getType() == DepScenario)
	{
		testPlan.addScenario(depDefinition->getName());	
		addAllNestedFunctions(depDefinition, testPlan, depDefinition->getName());	
	}
	else
	{
		for(int i = 0; i < depDefinition->getDefinitionCount(); i++)
		{
			DepDefinition* definition = depDefinition->getDefinitionAt(i);
			addAllNestedScenarios(definition, testPlan);			
		}
	}
}

void addAllNestedFunctions(DepDefinition* depDefinition, TestPlan& testPlan, string scenario)
{
	if (DepChildType[depDefinition->getType()] == DepTransition)
	{
		for(int i = 0; i < depDefinition->getDefinitionNameCount(); i++)
		{
			testPlan.addFunction(depDefinition->getDefinitionNameAt(i), scenario);
		}
	}
	else
	{
		for(int i = 0; i < depDefinition->getDefinitionCount(); i++)
		{
			DepDefinition* definition = depDefinition->getDefinitionAt(i);
			addAllNestedFunctions(definition, testPlan, scenario);			
		}
	}
}

bool initialize()
{
	depTree = reader.read(opts.olverTreeName);
    
    if (depTree)
    {
        if (!depTree->isReferencesResolved())
        {
            printf("Please, fix unresolved references.\n");
            return false;
        }
    }
    else
    {
        printf("error: Failed to read '%s'.\n", opts.olverTreeName);
    	return false;
    }
    return true;
}

bool finalize()
{
    reader.release(depTree);
	return true;
}

void printDepTree()
{
    //depTree->printDefinitions();
    depTree->printClusters();
    //depTree->printScopes();
    //depTree->printOptions();
}
