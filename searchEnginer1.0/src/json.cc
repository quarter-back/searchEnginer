#include "../json-develop/single_include/nlohmann/json.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace nlohmann;
class Point {
  public:
    Point(){};
    Point(int x, int y)
        : _x(x)
        , _y(y) {
        _vec.reserve(100);
    }
    ~Point() {}
    int getx() { return _x; }
    int gety() { return _y; }

    //要完成类对象到json结构体的转换需要重载json的转换函数
    //形式如下
    void to_json(json &j, const Point &p) {
        j = json{{"_x", p._x}, {"_y", p._y}};
    }
    //转回对象
    void from_json(const json &j, Point &p) {
        j.at("_x").get_to(p._x);
        j.at("_y").get_to(p._y);
    }

  private:
    int _x;
    int _y;
    vector<int> _vec;
};
int main() {
    //写入内容的一种方法
    json j1;
    j1["pi"] = 3.14;
    // cout j1 的结果{"pi":3.14}
    cout << j1 << endl;

    //常用函数
    // size 、empty 、type（得到结构体的类型） 、clear
    json j2;
    j2.push_back("hello");
    j2.push_back("world");
    cout << j2 << endl;
    for (json::iterator it = j2.begin(); it != j2.end(); ++it) {
        std::cout << *it << '\n';
    }

    //转换为类对象
    Point p(1, 2);
    cout << "sizeP" << sizeof(p) << endl;
    json j;
    p.to_json(j, p);
    cout << "j:" << j << "sizeof(j):" << sizeof(j) << endl;

    Point pp;
    pp.from_json(j, pp);
    cout << "(" << pp.getx() << "," << pp.gety() << ")" << endl;
    return 0;
}
