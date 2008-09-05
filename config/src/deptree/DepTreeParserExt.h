#ifndef DEPTREEPARSEREXT_H
#define DEPTREEPARSEREXT_H

#include "DepTreeParser.h"

class DepTreeParserExt : public DepTreeParser
{
public:
	DepTreeParserExt(ANTLRTokenBuffer* atb) : DepTreeParser(atb)
	{
	};  
    
protected:
    bool isTokenBufferEmpty();
    void reportParseError();    

private:
    string getCurrentTokenText();
};

#endif /* DEPTREEPARSEREXT_H */
