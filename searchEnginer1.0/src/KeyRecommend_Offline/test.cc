#include "SplitTool.h"
#include "DictProducer.h"

int main()
{
    SplitTool *tool = new SplitTool();
    DictProducer *dict = new DictProducer("../corpus", tool);
    dict->buildCnDict();
    dict->buildCnIndex();
    dict->showDict();
    dict->showIndex();
    dict->store();
    return 0;
}

