#include "deptree/deptreecommon.h"
#include "deptree/deptreegrammar.h"
#include "deptree/DepTreeParserExt.h"

typedef ANTLRCommonToken ANTLRToken;

int lineNumber;

void DepTreeParserExt::reportParseError()
{
    printf("%s(%d) : error : parse error near '%s'\n", fileName.c_str(), lineNumber + 1, getCurrentTokenText().c_str());
    result = false;
}

string DepTreeParserExt::getCurrentTokenText()
{
    ANTLRTokenPtr t = (ANTLRTokenPtr) LT(1);

    string st = "";

    if (t != 0)
    {
        st = mytoken(t)->getText();
        if (st == "\n")
            return "\\n";
        if (st == "�")
            return "\"";
    }
    return st;
}

bool DepTreeParserExt::isTokenBufferEmpty()
{
	if (LA(1) == eofToken)
		return true;
	return false;
}
