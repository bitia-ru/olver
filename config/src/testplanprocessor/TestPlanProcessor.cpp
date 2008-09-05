#include "testplan/testplancommon.h"
#include "testplan/TestPlan.h"
#include "testplan/TestPlanReader.h"

int main(int argc, char** argv)
{
	TestPlanReader testPlanReader;
	TestPlan testPlan;
	
	if (testPlanReader.read("config/olver.tp", testPlan))
	{
		printf(testPlan.toString().c_str());
		printf("Pass\n");
		
		
		for (int i = 0; i < testPlan.getEntryCount(); i++)
		{
			TestPlanEntry entry = testPlan.getEntryAt(i);
			printf("%s\n", entry.toString().c_str());
		}
	}
	else
	{
		printf("Fail\n");
	}
	return 0;
}
