#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4786 )
#pragma warning( disable : 4251 )


#include "deptree/deptreelib.h"
#include "deptree/DepTree.h"
#include "deptree/DepTreeReader.h"

int main(int argc, char** argv)
{
    DepTreeReader reader;

    DepTree* depTree = reader.read("..\\..\\dep.tree");

    if (depTree)
    {
        if (!depTree->isReferencesResolved())
        {
            printf("Please, fix unresolved references.\n");
        }

        //depTree->printDefinitions();
        depTree->printClusters();
        depTree->printScopes();
        depTree->printOptions();
    }
    
    reader.release(depTree);

    return 0;
}
