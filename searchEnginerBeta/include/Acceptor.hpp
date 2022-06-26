#ifndef __ACCEPTOR_HPP__
#define __ACCEPTOR_HPP__

#include "Socket.hpp"
#include "InetAddress.hpp"

class Acceptor
{
public:
    Acceptor(unsigned short port, const string &ip = "127.0.0.1");
    ~Acceptor();

    void ready();
    int accept();
    int getFd() const;

private:
    void setReuseAddr();
    void setReusePort();
    void bind();
    void listen();

private:
    Socket _listensock;
    InetAddress _addr;
};

#endif