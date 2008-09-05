#include "deptree/deptreecommon.h"
#include "deptree/DepTreeXMLWriter.h"
#include "deptree/DepTree.h"

bool DepTreeXMLWriter::write(const char* fileName, DepTree * tree)
{
    if(!tree)
        return false;

    f = fopen(fileName, "wt");

    if(!f)
        return false;

    writeTree(tree);

    fclose(f);

    return true;
}

void DepTreeXMLWriter::writeTree(DepTree * tree)
{
    tab_lev = 0;

    fprintf(f, "<?xml-stylesheet href='tree.xsl' type='text/xsl'?>\n");
    fprintf(f, "<Root>\n"); tab_lev++;

    DepDefinition * root = &(tree->getRoot());

    writeDepDef(root, root);

    fprintf(f, "</Root>\n"); tab_lev--;
}

char * DepTreeXMLWriter::tablevel()
{
    int splen = tab_lev;
    if(splen>80)
        splen = 80;

    memset(spaces, '\t', splen);
    spaces[splen] = 0;

    return spaces;
}

void DepTreeXMLWriter::writeDepDef(DepDefinition * def, DepDefinition * root)
{
    fprintf(f, "%s<Def", tablevel());
    {
        string strName = def->getName();
        int lastInd = def->getName().find_last_of(".");
        if(lastInd>=0)
        {
            strName = strName.substr(lastInd+1);
        }
        fprintf(f, " type=\"%s\"", toString_DepDefinitionType(def->getType()).c_str() );
        fprintf(f, " name=\"%s\"", strName.c_str() );
    }fprintf(f, ">\n"); tab_lev++;

    OptScope * scope = def->getScope();
    if(scope)
    {
        writeScope(scope, root);
        fprintf(f,"\n");
    }

    int definitionCount = root->getDefinitionCount();
    for (int i = 0; i < definitionCount; i++)
    {
        DepDefinition* child = root->getDefinitionAt(i);

        if(child->getParent() == def)
            writeDepDef(child, root);
    }

    tab_lev--; fprintf(f, "%s</Def>\n", tablevel() );
}

void DepTreeXMLWriter::writeScope(OptScope * sc, DepDefinition * root)
{
    int optionCount = sc->getOptionCount();

    for(int i = 0; i < optionCount; i++)
    {
        OptDefinition * opt = sc->getOptionAt(i);

        writeOption(opt);
    }
}

void DepTreeXMLWriter::writeOption(OptDefinition * opt)
{
    fprintf(f, "%s<Option", tablevel());
    {
        fprintf(f, " name=\"%s\"", opt->getName().c_str() );
        fprintf(f, " type=\"%s\"", toString_OptType(opt->getType()).c_str() );
        fprintf(f, " kind=\"%s\"", toString_OptKind(opt->getKind()).c_str() );
        fprintf(f, " destination=\"%s\"", opt->getDestinationFile().c_str() );
    }fprintf(f, ">\n"); tab_lev++;

    vector<OptValue*> values = opt->getValues();
    vector<OptValue*>::iterator it;

    for(it = values.begin(); it!=values.end(); it++)
    {
        OptValue * optval = (*it);
        OptType opttype = opt->getType();
        string isdef_str = (optval->isDefault?" isdefault=\"1\"":"");
        const char * isdef = isdef_str.c_str();

        if(opttype == OptBool || opttype == OptInt)
        {
            fprintf(f, "%s<Value val=\"%s\"%s/>\n", tablevel(), optval->name.c_str(), isdef );
        }
        else
        if(opttype == OptSet)
        {
            fprintf(f, "%s<Value val=\"%d\"%s>", tablevel(), optval->value, isdef);
            fprintf(f, "<![CDATA[%s]]>", optval->name.c_str());
            fprintf(f, "</Value>\n");
        }
        else
        if(opttype == OptString)
        {
            if(optval->value)
                fprintf(f, "%s<Value val=\"%s\"%s/>\n", tablevel(), optval->name.c_str(), isdef );
            else
                fprintf(f, "%s<Value Null=\"1\"%s/>\n", tablevel(), isdef);
        }
    }

    tab_lev--; fprintf(f, "%s</Option>\n", tablevel() );
}