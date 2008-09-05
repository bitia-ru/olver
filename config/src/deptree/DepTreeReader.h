#ifndef DEPTREEREADER_H
#define DEPTREEREADER_H

class DepTree;
class DLGInputStream;


class DEP_EXT_CLASS DepTreeReader 
{
public:
    DepTree* read(const char* fileName);
    void release(DepTree* depTree);

private:
    DepTree* readFromFile(FILE* file);
    DepTree* readFromString(const char* deptreeString);
    DepTree* readFromDlgInput(DLGInputStream& in);

private:
    string fileName;
};

#endif /* DEPTREEREADER_H */
