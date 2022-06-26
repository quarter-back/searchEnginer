#include "../include/PageProducer.hpp"
#include "../include/SplitTool.hpp"
#include "../include/tinyxml2.h"
#include "../include/utf8.h"

#include <dirent.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

using namespace tinyxml2;
using std::cerr;
using std::cout;
using std::endl;
using std::ostringstream;
using std::regex;
using std::ofstream;

PageProducer::PageProducer(string fileDir) {
    initFileName(fileDir);
}

void PageProducer::initFileName(string fileDir) {
    DIR* dirp = opendir(fileDir.c_str());
    dirent* pdirent;
    string dirName;
    while ((pdirent = readdir(dirp)) != nullptr) {
        dirName = pdirent->d_name;
        if (dirName != "." && dirName != "..") {
            _files.push_back(dirName);
        }
    }
    closedir(dirp);
}

void PageProducer::buildripepage() {
    map<string, int> _map;
    for (int i = 0; i < _files.size(); ++i) {
        cout << _files[i] << endl;
        XMLDocument xml;
        // string fileName = "../material/" + _files[i];
        string fileName = "../m/" + _files[i];
        if (xml.LoadFile(fileName.c_str()) != XML_SUCCESS) {
            cerr << "open xml fail" << endl;
            return;
        }
        XMLElement* rss = xml.RootElement();
        XMLElement* channel = rss->FirstChildElement();
        XMLElement* item = channel->FirstChildElement("item");

        regex reg("<\\/?.+?\\/?>");
        string contextTitle;
        string contextDescription;
        string contextLink;
        size_t idx = 0;
        while (item) {
            XMLElement* itemChild = item->FirstChildElement("title");
            if (itemChild == nullptr) {
                item = item->NextSiblingElement();
                continue;
            }
            RssItem ritem;
            

            ritem.title = regex_replace(itemChild->GetText(), reg, "");

            itemChild = itemChild->NextSiblingElement("link");
            ritem.link = regex_replace(itemChild->GetText(), reg, "");

            itemChild = itemChild->NextSiblingElement("description");
            ritem.description =
                regex_replace(itemChild->GetText(), reg, "");
            
            ++idx;
            _rss.push_back(ritem);
            item = item->NextSiblingElement();
        }
    }
}

void PageProducer::store(){
    ofstream ofs("../data/ripepage.dat");
     if(!ofs){
        cerr << "ofs fail" << endl;
        return;
    }

    for(int i = 0; i < _rss.size(); ++i){
        Offset offset;
        _offset.push_back(offset);
        _offset[i].idx = i + 1;
        _offset[i].startPos = ofs.tellp();
        ofs << "<doc>" << endl;
        ofs << "\t<docid>" << i + 1 << "</docid>" << endl;
        ofs << "\t<title>" << _rss[i].title << "</title>" << endl;
        ofs << "\t<link>" << _rss[i].link << "</link>" << endl;
        ofs << "\t<description>" << _rss[i].description << "</description>" << endl;
        ofs << "</doc>" << endl;
        _offset[i].endPos = ofs.tellp();
    }

    ofstream ofs2("../data/offset.dat");
     if(!ofs2){
        cerr << "ofs2 fail" << endl;
        return;
    }

    for(int i = 0; i < _offset.size(); ++i){
        ofs2 << _offset[i].idx << " "
            << _offset[i].startPos << " "
            << _offset[i].endPos << " \n";
    }

    ofs2.close();
    ofs.close();
}