#include "../include/PagePreProcessor.hpp"
#include "../include/PageProducer.hpp"
#include "../include/SplitTool.hpp"
#include "../include/WebPageSearcher.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // PageProducer pp("../m");
    // pp.buildripepage();
    // pp.store();
    // SplitTool *psp = new SplitTool();
    PagePreProcessor *pre = new PagePreProcessor();
    pre->invertProcess();
    // pre->dump();
    pre->store();

    // string str;
    // string res;
    // getline(cin, str);
    // WebPageSearcher searcher;
    // searcher.doQuery(str, res);
    // // searcher.dump();
    // cout << res << endl;
    return 0;
}

