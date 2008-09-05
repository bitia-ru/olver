#ifndef __DEPTREE_DLL__
#define __DEPTREE_DLL__


/* 
#ifdef WIN32

#ifdef _DEBUG
#pragma comment(lib,"deptreed.lib")
#pragma message("Automatically linking with deptree.lib ( Debug Version )")
#else
#pragma comment(lib,"deptree.lib")
#pragma message("Automatically linking with deptree.lib ( Release Version )")
#endif

#define DEP_EXT_CLASS __declspec(dllimport)

#else
*/
#define DEP_EXT_CLASS

//#endif

#endif  // __DEPTREE_DLL__
