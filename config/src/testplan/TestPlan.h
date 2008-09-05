#ifndef TESTPLAN_H_
#define TESTPLAN_H_

class TestPlanEntry
{
public:
	string cluster;
	string subsystem;
	string group;
	string scenario;
	
public:
	string toString();	
};

class TestPlan
{
public:
	void addEntry(string entry);
	int getEntryCount();
	TestPlanEntry getEntryAt(int index);

	void addScenario(string name);
	int getScenarioCount();
	string getScenarioAt(int index);
	
	void addFunction(string name, string scenario);
	int getFunctionCount();
	string getFunctionAt(int index);
	vector<string> getDependentScenarios(string functionName);
	
public:
	string toString();	
	
private:
	vector<string> entries;
	vector<string> scenarios;
	vector<string> functions;
	vector<string> sf_deps;
};

#endif /*TESTPLAN_H_*/
