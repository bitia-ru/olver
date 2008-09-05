#ifndef DEPTREEXMLWRITER_H
#define DEPTREEXMLWRITER_H

class DepTree;
class DepDefinition;
class OptScope;
class OptDefinition;
//class DLGInputStream;

class DEP_EXT_CLASS DepTreeXMLWriter
{
public:
    bool write(const char* fileName, DepTree * tree);

private:
    FILE * f;
    int tab_lev;
    char spaces[81];

private:
    void writeTree(DepTree * tree);
    
    char * tablevel();
    void writeDepDef(DepDefinition * def, DepDefinition * root);
    void writeScope(OptScope * sc, DepDefinition * root);
    void writeOption(OptDefinition * opt);


};

#endif /* DEPTREEXMLWRITER_H */
