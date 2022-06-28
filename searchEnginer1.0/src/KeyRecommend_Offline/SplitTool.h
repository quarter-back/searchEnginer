#ifndef __YL_SPLITTOOL_H__
#define __YL_SPLITTOOL_H__

#include <iostream>
#include <vector>

using std::vector;
using std::string;

class SplitTool
{
public:
    vector<string> cut(const string & sentence);
};

#endif
