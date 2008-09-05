#include "testplan/testplancommon.h"
#include "testplan/TestPlan.h"

void TestPlan::addEntry(string entry)
{
	entries.push_back(entry);
}

int TestPlan::getEntryCount()
{
	return entries.size();
}

TestPlanEntry TestPlan::getEntryAt(int index)
{
	TestPlanEntry entry;
	
	string str = entries[index];
	int pos = 0;
	int count = 0;
	int startPos = 0;
	while(pos < str.length())
	{
		if (str[pos] == '.' || pos == str.length() - 1)
		{
			if (pos == str.length() - 1)
				pos++;
				
			if (count == 0)
			{
				entry.cluster = str.substr(startPos, pos - startPos);			
			}
			else
			if (count == 1)
			{
				entry.subsystem = str.substr(startPos, pos - startPos);
			}
			else
			if (count == 2)
			{
				entry.group = str.substr(startPos, pos - startPos);
			}
			else
			if (count == 3)
			{
				entry.scenario = str.substr(startPos, pos - startPos);		
			}
			
			startPos = pos + 1;
			count++;
		}
		pos++;
	}

	return entry;
}

void TestPlan::addScenario(string name)
{
	scenarios.push_back(name);
}

int TestPlan::getScenarioCount()
{
	return scenarios.size();
}

string TestPlan::getScenarioAt(int index)
{
	return scenarios[index];
}

void TestPlan::addFunction(string name, string scenario)
{
	functions.push_back(name);
	sf_deps.push_back(scenario);
}

int TestPlan::getFunctionCount()
{
	return functions.size();
}

string TestPlan::getFunctionAt(int index)
{
	return functions[index];
}

vector<string> TestPlan::getDependentScenarios(string functionName)
{
	vector<string> deps;
	
	for (int i = 0; i < functions.size(); i++)
	{
		if (functions[i] == functionName)
		{
			deps.push_back(sf_deps[i]);
		}
	}	
	return deps;
}

string TestPlan::toString()
{
	string result = "";
	for (int i = 0; i < entries.size(); i++)
	{
		result += entries[i] + "\n";
	}
	return result;
}

string TestPlanEntry::toString()
{
	string result = "";
	result += "cluster: " + cluster + "\n";
	result += "subsystem: " + subsystem + "\n";
	result += "group: " + group + "\n";
	result += "scenario: " + scenario + "\n";			
	return result;
}
