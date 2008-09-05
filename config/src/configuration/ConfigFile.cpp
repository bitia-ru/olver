#include "configuration/configcommon.h"
#include "configuration/ConfigFile.h"

/*
 * ConfigValue
 */

ConfigValue::ConfigValue()
{
	name = "";
	value = "";
	scopeName = "";
	optionName = "";
}

ConfigValue::ConfigValue(string name, string value)
{
	setName(name);
	setValue(value);
}

ConfigValue::ConfigValue(string scopeName, string optionName, string value)
{
	setName(scopeName + "." + optionName);
	this->value = value;
}
	
void ConfigValue::setName(string name)
{
	int pos = name.find_last_of(".", name.length());
	if (pos)
	{
		scopeName = name.substr(0, pos);
		optionName = name.substr(pos + 1, name.length() - pos - 1);
	}
	this->name = name;
	
}

string ConfigValue::getName()
{
	return name;
}

void ConfigValue::setValue(string value)
{
	this->value = value;
}

string ConfigValue::getValue()
{
	return value;
}

string ConfigValue::getScopeName()
{
	return scopeName;
}

string ConfigValue::getOptionName()
{
	return optionName;
}
	
string ConfigValue::toString()
{
	return name + " = " + value;
}

/*
 * ConfigFile
 */

void ConfigFile::addConfigValue(ConfigValue& value)
{
	values.push_back(value);
}

int ConfigFile::getConfigValueCount()
{
	return values.size();
}

ConfigValue& ConfigFile::getConfigValueAt(int index)
{
	return values[index];
}

bool ConfigFile::hasConfigValue(string scopeName, string optionName)
{
	string name = scopeName + "." + optionName;
	for (int i = 0; i < values.size(); i++)
	{
		ConfigValue& cv = values[i];
		if (cv.getName() == name)
		{
			return true;
		}
	}
	return false;
}
	
string ConfigFile::toString()
{
	string result = "";
	for (int i = 0; i < values.size(); i++)
	{
		ConfigValue& cv = values[i];
		result += cv.toString() + "\n";
	}
	return result;
}

