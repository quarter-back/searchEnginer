#ifndef __WEBPAGE_HPP__
#define __WEBPAGE_HPP__

#include "../lib/json.hpp"
#include <stdlib.h>
#include <tinyxml2.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace tinyxml2;
using namespace nlohmann;

class WebPage {
  public:
    WebPage(string &); //传入newpage中的一整行doc内容
    ~WebPage();

    int getDocId();                  //获取文档id
    string getURL();                 //获取URL
    string getContent();             //获取文档内容
    string getTitle();               //获取文档标题
    string getDoc();                 //获取整篇文档
    map<string, int> &getWordsMap(); //获取文档词频

    void ProcessDoc(); //将传入的doc进行分割处理
    void show();       //打印测试函数

    void WordsHandle(); //处理单词词频

    void to_json(json &j, const WebPage &web) {
        j = json{{"_docId", web._docId},
                 {"_docTitle", web._docTitle},
                 {"_docURL", web._docURL},
                 {"_docContent", web._docContent},
                 {"_docSummary", web._docSummary}};
    }
    void from_json(const json &j, WebPage &web) {
        j.at("_docId").get_to(web._docId);
        j.at("_docTitle").get_to(web._docTitle);
        j.at("_docURL").get_to(web._docURL);
        j.at("_docContent").get_to(web._docContent);
        j.at("_docSummary").get_to(web._docSummary);
    }

  private:
    string _doc;        //整篇文档
    int _docId;         //文档id
    string _docTitle;   //文档标题
    string _docURL;     //文档URL
    string _docContent; //文档内容
    string _docSummary; //文档摘要
    // vector<string> _topWords;//最高词频前20个
    map<string, int> _wordsMap; //所有单词和词频
};

#endif
