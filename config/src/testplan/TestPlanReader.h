#ifndef TESTPLANREADER_H_
#define TESTPLANREADER_H_

class TestPlanReader
{
public:
	bool read(const char* file, TestPlan &testPlan);
	
private:
	bool readFromFile(FILE* infile, TestPlan &testPlan);
	bool readFromString(char* str, TestPlan &testPlan);	
};

#endif /*TESTPLANREADER_H_*/
