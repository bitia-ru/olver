#include "deptree/deptreecommon.h"
#include "deptree/deptreegrammar.h"
#include "deptree/DepTreeParserExt.h"
#include "deptree/DepTreeReader.h"
#include "deptree/DepTree.h"
 

DepTree* DepTreeReader::read(const char* fileName)
{
	DepTree* depTree = 0;
    FILE* infile = 0;

    this->fileName = fileName;

    infile = fopen(fileName, "rb");

    if (infile) 
    {
        depTree = readFromFile(infile);
        fclose(infile);
    }

    if (depTree)
    {
        depTree->resolveReferences();
    }

    return depTree;
}

DepTree* DepTreeReader::readFromFile(FILE* file)
{
	DLGFileInput in(file);
	return readFromDlgInput(in);
}

DepTree* DepTreeReader::readFromString(const char* deptreeString)
{
	DLGStringInput in(deptreeString);
	return readFromDlgInput(in);
}

DepTree* DepTreeReader::readFromDlgInput(DLGInputStream& in)
{
	lineNumber = 0;                 // initialize line counter

    int ReturnParserSignal;
	DDlgLexer scan(&in);            // connect a scanner to an input stream
	ANTLRTokenBuffer pipe(&scan);   // connect scanner, parser via pipe
	ANTLRCommonToken aToken;		// create token for cloning
	scan.setToken(&aToken);
	DepTreeParserExt parser(&pipe); // create parser
	parser.init();					// init parser

	DepTree* depTree = parser.root(&ReturnParserSignal, fileName);      // invoke parser start rule

	if (!parser.result)
	{
		return NULL;
	}
	else
	{
		return depTree;
	}
}

void DepTreeReader::release(DepTree* depTree)
{
    delete(depTree);
}
