#ifndef SE_INCLUDE_OFFLINE_DIRSCANNER_H
#define SE_INCLUDE_OFFLINE_DIRSCANNER_H

#include <dirent.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class DirScanner {
  public:
    DirScanner() {}

    vector<string> files() { return this->_files; }

    void traverse(const string &dirname) {
        DIR *pDir;
        struct dirent *ptr;
        if (!(pDir = opendir(dirname.c_str()))) {
            cout << "Folder doesn't Exist!" << endl;
            return;
        }
        while ((ptr = readdir(pDir)) != 0) {
            if (strcmp(ptr->d_name, ".") != 0 &&
                strcmp(ptr->d_name, "..") != 0) {
                char *pFile;
                pFile = strrchr(ptr->d_name,
                                '.'); // 判断输入的文件名最后输出.的位置

                if (pFile != NULL) // 输入不为空
                {
                    if (strcmp(pFile, ".xml") == 0) {
                        this->_files.push_back(dirname + "/" + ptr->d_name);
                    }
                }
            }
        }
        closedir(pDir);
    }

  private:
    vector<string> _files;
};

#endif
