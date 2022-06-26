#ifndef __DATABAG_HPP__
#define __DATABAG_HPP__

#include "KeyRecommander.hpp"
#include "WebPageSearcher.hpp"



struct DataBag
{
    int ThreadIdx;
    KeyRecommander *keyRecommanderPtr;
    WebPageSearcher *webPageSearcherPtr;
};

#endif