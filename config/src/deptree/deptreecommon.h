#ifdef WIN32

#define DEP_EXT_CLASS __declspec(dllexport)

#else

#define DEP_EXT_CLASS

#endif

#define DEP_DLL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>
#include <map>

using namespace std;


#pragma warning( disable : 4786 )
#pragma warning( disable : 4251 )


string intToString(int value);
