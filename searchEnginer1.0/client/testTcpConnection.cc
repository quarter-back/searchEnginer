#include "tcpConnection.hh"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    TcpConnection con("127.0.0.1", 7777);
    con.connection();

    cout << con.toString() << "connected!" << endl;
    while (1) {
        cout << "<$> recv msg from client: " << con.receive();
        con.send("hello motor!\n");
    }
}
