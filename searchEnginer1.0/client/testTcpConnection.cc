#include "tcpConnection.hh"
#include <iostream>

using std::cout;

int main() {
    TcpConnection con("127.0.0.1", 7777);
    con.connection();
    system("figlet searchEnginer");
    while (1) {
        cout << "<$> recv msg from client: " << con.receive();
        con.send("hello motor!\n");
    }
}
