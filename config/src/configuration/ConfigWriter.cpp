#include "configuration/configcommon.h"
#include "configuration/ConfigFile.h"
#include "configuration/ConfigWriter.h"

bool ConfigWriter::write(const char* fileName, ConfigFile &configFile)
{

	FILE* f = fopen(fileName, "wb");
	
	if (f)
	{
		int configValueCount = configFile.getConfigValueCount();
		for(int i = 0; i < configValueCount; i++)
		{
			ConfigValue& cv = configFile.getConfigValueAt(i);
			fprintf(f, "%s = %s\x0A", cv.getName().c_str(), cv.getValue().c_str());
		}
		fclose(f);
	}	
	else
	{
		return false;
	}

	return true;	
}
