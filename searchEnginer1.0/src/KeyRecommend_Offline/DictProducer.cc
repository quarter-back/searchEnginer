#include "../utfcpp-master/source/utf8.h"
#include "DictProducer.h"
#include "tinyxml2.h"
#include <dirent.h>
#include <fstream>
#include <sstream>

using namespace tinyxml2;
using std::ofstream;
using std::ostringstream;
using std::cout;
using std::endl;
using std::cerr;

//处理中文
DictProducer::DictProducer(const string& dir, SplitTool *SplitTool)
: _dict()
, _splitTool(SplitTool)
, _index()
{
    DIR *dirp = opendir(dir.c_str());
    if(dirp == NULL){
        perror("opendir");
        return;
    }
    struct dirent *pdirent;
    while((pdirent = readdir(dirp)) != NULL){
        string DirName = pdirent->d_name;
        if(DirName != "." && DirName != ".."){
            _files.push_back(DirName);
        }
    }
    closedir(dirp);
}

//创建中文字典
void DictProducer::buildCnDict()
{
    cout << "bulidCnDict" << endl;
    string text;
    for(auto &file :_files)
    {
        cout << "load " << file << endl;
        //加载xml文件
        XMLDocument doc;
        string filename = "../corpus/" + file;
        int ret = doc.LoadFile(filename.c_str());
        if(ret != 0){
            cerr << "load xml file failed" << endl;
        }

        //遍历结点
        XMLElement *root = doc.FirstChildElement("rss")->FirstChildElement("channel");
        XMLElement *node = root->FirstChildElement("item");
        while(node){
            //获取标题
            text += " ";
            text += node->FirstChildElement("title")->GetText();
            
            //获取内容,内容不能为空
            text += " ";
            text += node->FirstChildElement("description")->GetText();

            node = node->NextSiblingElement();
        }
    }

    cout << "cut begin" << endl;
    map<string, int> dict;
    vector<string> word = _splitTool->cut(text);
    for(auto &it_word : word)
    {
        auto it = dict.find(it_word);
        if(it != dict.end()){
            it->second ++;
        }else{
            dict[it_word] = 1;
        }
    }

    for(auto &it : dict)
    {
        _dict.push_back(it);
    }
    cout << "cut end" << endl;
}

//创建中文索引
void DictProducer::buildCnIndex()
{
    string letter;
    int line = 0;
    for(auto &dict :_dict)
    {
        ++ line;
        letter = dict.first;
        for(auto it = letter.begin(), it2 = letter.begin(); it2 != letter.end(); )
        {
            utf8::next(it2, letter.end());
            ostringstream oss;
            while(it < it2){
                oss << *it;
                ++it;
            }
            _index[oss.str()].insert(line);
        }
    }
}

//将词典、索引写入文件
void DictProducer::store()
{
    cout << "store dict.dat" << endl;
    ofstream ofs;
    ofs.open("../data/dict.dat");
    if(!ofs){
        cout << "ofstream open dict.dat error" << endl;
    }
    for(auto &dict : _dict)
    {
        ofs << dict.first << " " << dict.second << endl;
    }
    ofs.close();
    
    cout << "store dictIndex.dat" << endl;
    ofstream ofs1;
    ofs1.open("../data/dictIndex.dat");
    if(!ofs1){
        cout << "ofstream open dictIndex.dat error" << endl;
    }
    for(auto &index : _index)
    {
        ofs1 << index.first << " ";
        for(auto &num : index.second)
        {
            ofs1 << num << " ";
        }
        ofs1 << endl;
    }
    ofs1.close();
}

//查看文件路径,作为测试用
void DictProducer::showFiles() const
{
    for(auto &file : _files)
    {
        cout << file << " ";
    }
    cout << endl;
}

//查看词典,作为测试用
void DictProducer::showDict() const
{
    cout << "show dict" << endl;
    for(auto &dict : _dict)
    {
        cout << dict.first << " " << dict.second << endl;
    }
}
//查看索引,作为测试用
void DictProducer::showIndex() const
{
    cout << "show Index" << endl;
    for(auto &index : _index)
    {
        cout << index.first << endl;
    }
}
