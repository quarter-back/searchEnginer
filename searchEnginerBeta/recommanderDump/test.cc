#include "../include/SplitTool.hpp"
#include "../include/DictProducer.hpp"

#include <iostream>

using std::endl;
using std::cout;

int main()
{
    SplitTool *psp = new SplitTool();
    // DictProducer *pdp = new DictProducer("../material", psp);
    DictProducer *pdp = new DictProducer("../m", psp);
    pdp->buildCnDict();
    pdp->createIndex();
    pdp->store();
    return 0;
}

