#include "configuration/configcommon.h"
#include "configuration/ConfigFile.h"
#include "configuration/ConfigReader.h"


int main(int argc, char** argv)
{
	ConfigReader configReader;
	ConfigFile configFile;
	
	if (configReader.read("config/olver.conf", configFile))
	{
		printf(configFile.toString().c_str());
		printf("Pass\n");
	}
	else
	{
		printf("Fail\n");
	}
	return 0;
}
