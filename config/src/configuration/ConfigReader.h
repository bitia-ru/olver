#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_

class ConfigReader
{
public:
	bool read(const char* fileName, ConfigFile &configFile);
	
private:
	bool readFromFile(FILE* infile, ConfigFile &configFile);
	bool readFromString(char* str, ConfigFile &configFile);
};

#endif /*CONFIGREADER_H_*/
