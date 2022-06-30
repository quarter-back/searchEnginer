#ifndef __PROTOCOLPARSER_HH__
#define __PROTOCOLPARSER_HH__
#include "../lib/json.hpp"
#include <string>

#define KEYRECOMMAD 1
#define WEBSEARCH 2

using namespace nlohmann;
using std::string;

//通过构造函数构造协议类
//用to_json转成json后即可send
class ProtocolParser {
  public:
    ProtocolParser(int cmd, string &str)
        : _cmd(cmd)
        , _msg(str) {}
    ~ProtocolParser() {}
    void to_json(json &j, const ProtocolParser &p) {
        j = json{{"_cmd", p._cmd}, {"_msg", p._msg}};
    }
    void from_json(const json &j, ProtocolParser &p) {
        j.at("_cmd").get_to(p._cmd);
        j.at("_msg").get_to(p._msg);
    }

  private:
    int _cmd;
    string _msg;
};

#endif
