#ifndef __YL_DICTPRODUCER_H__
#define __YL_DICTPRODUCER_H__

#include "SplitTool.h"
#include <vector>
#include <string>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::set;

class DictProducer
{
public:
    //处理英文
    /* DictProducer(const string& dir); */
    //处理中文
    DictProducer(const string& dir, SplitTool *SplitTool);
    //创建英文字典
    /* void buildEnDdict(); */
    //创建中文字典
    void buildCnDict();
    //创建中文索引
    void buildCnIndex();
    //将词典、索引写入文件
    void store();
    
    //查看文件路径,作为测试用
    void showFiles() const;
    //查看词典,作为测试用
    void showDict() const;
    //查看索引,作为测试用
    void showIndex() const;
    //获取文件的绝对路径
    /* void getFiles(); */
    //存储某个单词
    /* void pushDict(const string & word); */

private:
    vector<string> _files;  //语料库文件的绝对路径集合
    vector<pair<string, int>> _dict;    //词典
    SplitTool *_splitTool;  //分词工具
    map<string, set<int>> _index;   //词典索引
};

#endif
