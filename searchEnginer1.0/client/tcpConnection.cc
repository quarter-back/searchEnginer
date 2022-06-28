#include "tcpConnection.hh"
#include <iostream>
#include <sstream>

using std::endl;

TcpConnection::TcpConnection(const string &ip, unsigned short port)
    : _socket()
    , _socketIO(_socket.fd())
    , _serverAddr(ip, port)
    , _localAddr(getLocalAddr())
    , _peerAddr(getPeerAddr()) {}

void TcpConnection::connection() {

    int ret =
        ::connect(_socket.fd(), (struct sockaddr *)_serverAddr.getInetAddrPtr(),
                  sizeof(struct sockaddr));
    if (ret) {
        perror("connect");
        return;
    }
}

TcpConnection::~TcpConnection() {}

void TcpConnection::send(const string &msg) {
    _socketIO.writen(msg.c_str(), msg.size());
}

string TcpConnection::receive() {
    char buff[65535] = {0};
    _socketIO.readLine(buff, sizeof(buff));
    return string(buff);
}

string TcpConnection::toString() {
    std::ostringstream oss;
    oss << _localAddr.ip() << ":" << _localAddr.port() << "-->"
        << _peerAddr.ip() << ":" << _peerAddr.port() << endl;
    return oss.str();
}

InetAddress TcpConnection::getLocalAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getsockname(_socket.fd(), (struct sockaddr *)&addr, &len);
    if (-1 == ret) {
        perror("getsockname");
    }
    return InetAddress(addr);
}
InetAddress TcpConnection::getPeerAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getpeername(_socket.fd(), (struct sockaddr *)&addr, &len);
    if (-1 == ret) {
        perror("getpeername");
    }
    return InetAddress(addr);
}
