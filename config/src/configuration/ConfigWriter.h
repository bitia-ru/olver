#ifndef CONFIGWRITER_H_
#define CONFIGWRITER_H_

class ConfigWriter
{
public:
	bool write(const char* fileName, ConfigFile &configFile);
};

#endif /*CONFIGWRITER_H_*/
