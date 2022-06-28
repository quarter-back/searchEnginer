#include "SplitTool.h"
#include "../cppjieba/include/cppjieba/Jieba.hpp"
#include <unordered_set>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_set;
    
vector<string> SplitTool::cut(const string & sentence)
{
    const char* const DICT_PATH = "../cppjieba/dict/jieba.dict.utf8";
    const char* const HMM_PATH = "../cppjieba/dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "../cppjieba/dict/user.dict.utf8";
    const char* const IDF_PATH = "../cppjieba/dict/idf.utf8";
    const char* const STOP_WORD_PATH = "../cppjieba/dict/stop_words.utf8";

    cppjieba::Jieba jieba(DICT_PATH, 
                          HMM_PATH,
                          USER_DICT_PATH,
                          IDF_PATH,
                          STOP_WORD_PATH);
    vector<string> words;
    vector<cppjieba::Word> jiebawords;
    unordered_set<string> stopWords;
    jieba.CutForSearch(sentence, words, true);

    ifstream ifs("../cppjieba/dict/stop_words.utf8");
    if(!ifs.is_open()){
        perror("ifs open failed");
    }
    string tmpStr;
    while(getline(ifs, tmpStr)){
        tmpStr.pop_back();
        stopWords.insert(tmpStr);
    }
    ifs.close();

    vector<string> tmp;
    for(auto &iter : words)
    {
        if(stopWords.find(iter) != stopWords.end()){
            continue;
        }
        tmp.push_back(iter);
    }
    words.clear();

    for(auto &it : tmp)
    {
        unsigned char x = it[0];
        if(x < 128){
            continue;
        }
        words.push_back(it);
    }

    return words;
}
