#include "../include/json.hpp"
#include <arpa/inet.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using nlohmann::json;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void parse(string request) {
    char _request[4096] = {0};
    memcpy(_request, request.c_str(), request.size());
    string msgContent;
    int operatorId = 0;
    size_t msgLen = 0;
    char buf[4096] = {0};
    string tmp;
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        buf[i] = _request[idx++];
    }
    memcpy(&msgLen, buf, 4);
    memset(buf, 0, sizeof(buf));

    for (int i = 0; i < 4; ++i) {
        buf[i] = _request[idx++];
    }
    memcpy(&operatorId, buf, 4);
    memset(buf, 0, sizeof(buf));

    for (int i = 0; i < msgLen; ++i) {
        buf[i] = _request[idx++];
    }

    msgContent = buf;

    cout << "msgLen:" << msgLen << endl;
    cout << "operatorId:" << operatorId << endl;
    cout << "msgContent:" << msgContent << endl;
}

void pack(string &line, int op, string &data) {
    int dataSz = line.size();
    char dataSz_c[4] = {0};
    // cout << "dataSz:" << dataSz << endl;

    memcpy(dataSz_c, (char *)&dataSz, 4);
    int opId = op;
    char opId_c[4] = {0};
    // cout << "opId:" << opId << endl;

    memcpy(opId_c, (char *)&opId, 4);

    char buf[4096] = {0};

    int idx = 0;
    for (; idx < 4; ++idx) {
        buf[idx] = dataSz_c[idx];
    }

    for (int i = 0; i < 4; ++i) {
        buf[idx++] = opId_c[i];
    }
    for (int i = 0; i < line.size(); ++i) {
        buf[idx++] = line[i];
    }
    for (int i = 0; i < 8 + line.size(); ++i) {
        data.push_back(buf[i]);
    }
    data.append("\n");
}

struct WebPage {
    int id;
    string title;
    string link;
    vector<string> description;
};

void unpack(json &j) {
    vector<WebPage> vecPage;
    for (auto it = j.begin(); it != j.end(); ++it) {
        WebPage webpage;
        webpage.id = (*it)["id"];
        webpage.title = (*it)["title"];
        webpage.link = (*it)["link"];
        for (auto it2 = (*it)["description"].begin();
             it2 != (*it)["description"].end(); ++it2) {
            webpage.description.push_back(*it2);
        }
        vecPage.push_back(webpage);
    }

    int idx = 0;
    char op[10];
    idx = ((idx + 5) > vecPage.size() ? vecPage.size() : (idx + 5));

    while (1) {
        for (int i = ((idx - 5 < 0) ? 0 : (idx - 5)); i < idx; ++i) {
            cout << "-->No:" << i + 1 << endl;
            cout << "-->title: " << vecPage[i].title << endl;
            cout << "-->link:  " << vecPage[i].link << endl;
            cout << "-->description:   ";
            for (int j = 0; j < vecPage[i].description.size(); ++j) {
                cout << "..." << vecPage[i].description[j] << "...";
            }
            cout << endl << endl;
        }
        cout << "Page:  " << idx << "/" << vecPage.size() << endl;
        cout << "n:for next page  b:for back page q:quit" << endl;
        //==>
        cout << "g:for to link    q:for quit" << endl;
        cin >> op;
        if (op[0] == 'n') {
            idx = ((idx + 5) > vecPage.size() ? vecPage.size() : (idx + 5));
        } else if (op[0] == 'b') {
            if ((idx - 5) < 5) {
                if (vecPage.size() < 5) {
                    idx = vecPage.size();
                } else {
                    idx = 5;
                }
            } else {
                idx -= 5;
            }
        } else if (op[0] == 'q') {
            cin.clear();
            cin.ignore();
            break;
        } else if (op[0] == 'g') {
            char number[1024] = {0};
            strcpy(number, op + 1);
            int index = atoi(number);
            cout << "index:" << index << endl;
            string linkstr("w3m ");

            linkstr += vecPage[index].link;
            system(linkstr.c_str());
        }
    }
}

void work() {
    int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd < 0) {
        perror("socket");
        return;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    /* serverAddr.sin_addr.s_addr = inet_addr("192.168.30.128"); */
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    socklen_t length = sizeof(serverAddr);

    if (::connect(clientfd, (struct sockaddr *)&serverAddr, length) < 0) {
        perror("connect");
        close(clientfd);
        return;
    }
    system("clear");
    cout << endl << endl << endl << endl;
    system("figlet -c seseENGINER");
    string recommanderKey;
    string solitaireKey;
    bool reFlag = false;
    bool soFlag = false;
    bool firstOp4 = false;
    string line;
    int opId;
    while (1) {
        if (!reFlag && !soFlag) {
            cout << "<seseENGINER>$ pls input selection:" << endl
                 << "<seseENGINER>$ 1.关键字查询 " << endl
                 << "<seseENGINER>$ 2.网页查询 " << endl
                 << "<seseENGINER>$ 3.关键字推荐 " << endl
                 << "<seseENGINER>$ 5.退出" << endl;
            getline(cin, line);
            opId = std::stoi(line);
            if (opId == 4) {
                firstOp4 = true;
            }
        }
        if (opId == 1 || opId == 2) {
            if (!reFlag) {
                cout << "请输入查询的关键字=>" << endl;
                getline(cin, line);
            } else {
                if (reFlag) {
                    line = recommanderKey;
                    reFlag = false;
                }
            }

            string data;
            pack(line, opId, data);

            int ret = send(clientfd, data.c_str(), data.size(), 0);
            if (ret < 0) {
                perror("send");
            }
            ret = 0;
            // string str;
            char buff[65536] = {0};
            ret = recv(clientfd, buff, sizeof(buff), 0);
            std::istringstream iss;
            iss.str(buff);
            if (opId == 1) {
                json j;
                iss >> j;
                // cout << j << endl;
                string key;
                j["key"].get_to(key);
                cout << key << ":" << endl;
                for (auto it = j["values"].begin(); it != j["values"].end();
                     ++it) {
                    cout << it.value() << endl;
                }

            } else if (opId == 2) {
                json j;
                iss >> j;
                unpack(j);
            }
        } else if (opId == 5) {
            break;
        } else if (opId == 3) {
            string data;
            string emptyStr("");

            pack(emptyStr, opId, data);

            int ret = send(clientfd, data.c_str(), data.size(), 0);
            if (ret < 0) {
                perror("send");
            }

            ret = 0;
            // string str;
            char buff[65536] = {0};
            ret = recv(clientfd, buff, sizeof(buff), 0);

            std::istringstream iss;

            iss.str(buff);

            json j;
            iss >> j;
            // cout << j << endl;
            vector<string> keys;
            for (auto it = j["keys"].begin(); it != j["keys"].end(); ++it) {
                keys.push_back(it.value());
            }

            for (int i = 0; i < keys.size(); ++i) {
                cout << i + 1 << ":" << keys[i] << endl;
            }

            getline(cin, line);
            opId = 2;
            recommanderKey = keys[std::stoi(line) - 1];
            reFlag = true;

        } else if (opId == 4) {
            if (firstOp4) {
                firstOp4 = false;

                string data;
                string emptyStr("");

                pack(emptyStr, 3, data);

                int ret = send(clientfd, data.c_str(), data.size(), 0);
                if (ret < 0) {
                    perror("send");
                }

                ret = 0;
                // string str;
                char buff[65536] = {0};
                ret = recv(clientfd, buff, sizeof(buff), 0);

                std::istringstream iss;

                iss.str(buff);

                json j;
                iss >> j;
                // cout << j << endl;
                vector<string> keys;
                for (auto it = j["keys"].begin(); it != j["keys"].end(); ++it) {
                    keys.push_back(it.value());
                }

                for (int i = 0; i < keys.size(); ++i) {
                    cout << i + 1 << ":" << keys[i] << endl;
                }

                cout << endl;
                cout << "当前关键字:" << solitaireKey << endl;
                cout << "e: enter page q:quit" << endl;

                getline(cin, line);

                if (line[0] == 'e') {
                    recommanderKey = solitaireKey;
                    opId = 2;
                    reFlag = true;
                    soFlag = false;

                } else if (line[0] == 'q') {
                    reFlag = false;
                    soFlag = false;
                    continue;
                } else {
                    solitaireKey = keys[std::stoi(line) - 1];
                    opId = 4;
                    soFlag = true;
                }
            } else {
                string data;
                pack(solitaireKey, opId, data);

                int ret = send(clientfd, data.c_str(), data.size(), 0);
                if (ret < 0) {
                    perror("send");
                }
                /* close(clientfd); */

                ret = 0;
                // string str;
                char buff[65536] = {0};
                ret = recv(clientfd, buff, sizeof(buff), 0);

                std::istringstream iss;

                iss.str(buff);

                json j;
                iss >> j;
                // cout << j << endl;
                vector<string> keys;
                for (auto it = j["keys"].begin(); it != j["keys"].end(); ++it) {
                    keys.push_back(it.value());
                }

                for (int i = 0; i < keys.size(); ++i) {
                    cout << i + 1 << ":" << keys[i] << endl;
                }

                cout << endl;
                cout << "当前关键字:" << solitaireKey << endl;
                cout << "e: enter page q:quit" << endl;

                getline(cin, line);

                if (line[0] == 'e') {
                    recommanderKey = solitaireKey;
                    opId = 2;
                    reFlag = true;
                    soFlag = false;

                } else if (line[0] == 'q') {
                    reFlag = false;
                    soFlag = false;
                    continue;
                } else {
                    solitaireKey = keys[std::stoi(line) - 1];
                    opId = 4;
                    soFlag = true;
                }
            }
        }
    }
    close(clientfd);
}

int main(void) {
    work();
    return 0;
}
