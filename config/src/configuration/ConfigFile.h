#ifndef CONFIGFILE_H_
#define CONFIGFILE_H_

class ConfigValue
{
public:
	ConfigValue();
	ConfigValue(string name, string value);
	ConfigValue(string scopeName, string optionName, string value);
	
public:
	void setName(string name);
	string getName();
	void setValue(string value);
	string getValue();
	string getScopeName();
	string getOptionName();
	
public:
	string toString();	
	
private:
	string name;
	string value;
	string scopeName;
	string optionName;
};

class ConfigFile
{
public:
	void addConfigValue(ConfigValue& value);
	int getConfigValueCount();
	ConfigValue& getConfigValueAt(int index);
	bool hasConfigValue(string scopeName, string optionName);
	
public:
	string toString();

private:
	vector<ConfigValue> values;
};

#endif /*CONFIGFILE_H_*/
