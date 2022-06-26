#ifndef __TCPSERVER_HPP__
#define __TCPSERVER_HPP__

#include "Acceptor.hpp"
#include "EventLoop.hpp"
#include "TcpConnection.hpp"

class TcpServer
{
public:
    TcpServer(unsigned short port, const string &ip = "127.0.0.1");
    ~TcpServer();

    void setAllCallbakcs(TcpConnectionCallback &&conCb, 
                        TcpConnectionCallback &&msgCb,
                        TcpConnectionCallback &&clsCb);
    
    void start();
    void stop();

private:
    Acceptor _acceptor;
    EventLoop _loop;
};

#endif