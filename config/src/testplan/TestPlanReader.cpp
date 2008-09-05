#include "testplan/testplancommon.h"
#include "testplan/TestPlan.h"
#include "testplan/TestPlanReader.h"

bool TestPlanReader::read(const char* fileName, TestPlan &testPlan)
{
	bool result = false;
    FILE* infile = 0;

	infile = fopen(fileName, "rb");

    if (infile) 
    {
		result = readFromFile(infile, testPlan);
        fclose(infile);
    }
	return result;
}

bool TestPlanReader::readFromFile(FILE* infile, TestPlan &testPlan)
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
			result = readFromString(buffer, testPlan);
		}
		free(buffer);
	}
	return result;
}

bool TestPlanReader::readFromString(char* str, TestPlan &testPlan)
{
	char seps[]   = " \t\n";
	char *token;
    token = strtok(str, seps);
    while(token != NULL)
    {
    	if (*token == ' ' || *token == '\t')
    	{
    		continue;
    	}
    	
    	testPlan.addEntry(token);
    	
	    token = strtok(NULL, seps);
    } 
	return true;
}