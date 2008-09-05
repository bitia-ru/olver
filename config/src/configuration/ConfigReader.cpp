#include "configuration/configcommon.h"
#include "configuration/ConfigFile.h"
#include "configuration/ConfigReader.h"

bool ConfigReader::read(const char* fileName, ConfigFile &configFile)
{
	bool result = false;
    FILE* infile = 0;

	infile = fopen(fileName, "rb");

    if (infile) 
    {
		result = readFromFile(infile, configFile);
        fclose(infile);
    }
	return result;
}

bool ConfigReader::readFromFile(FILE* infile, ConfigFile &configFile)
{
	bool result = false;
	if(!fseek(infile, 0, SEEK_END))
	{
        size_t fileSize = ftell(infile);
		fseek(infile, 0, SEEK_SET);
        char* buffer = (char*)malloc(fileSize + 1);
		buffer[fileSize] = 0;
		size_t readBytes = fread(buffer, 1, fileSize, infile);
		if (readBytes == fileSize)
		{
			result = readFromString(buffer, configFile);
		}
		free(buffer);
	}
	return result;
}

bool ConfigReader::readFromString(char* str, ConfigFile &configFile)
{
    int valueReady = 0;
    string name = "";
    string value = "";

	char seps[]   = " \t=\n";
	char *token;
    token = strtok(str, seps);
    while(token != NULL)
    {
    	if (*token == ' ' || *token == '\t')
    	{
    		continue;
    	}
    	
	    valueReady++;
	    
	    if (valueReady == 1)
	    {
	    	name = token;
	    }
	    else
	    if (valueReady == 2)
	    {
	    	value = token;
	    	valueReady = 0;
	    	
	    	ConfigValue cv(name, value);
	    	configFile.addConfigValue(cv);
	    }
    	
	    token = strtok(NULL, seps);
    } 
	return true;
}
