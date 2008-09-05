#include "deptreecommon.h"

string intToString(int value)
{
    char buffer[10];
    sprintf(buffer, "%d", value);
    string temp = buffer;
    return temp;
}
