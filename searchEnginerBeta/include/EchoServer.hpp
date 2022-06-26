#ifndef __ECHOSERVER_HPP__
#define __ECHOSERVER_HPP__

#include "TcpServer.hpp"
#include "Threadpool.hpp"
#include "MyTask.hpp"
#include "DataBag.hpp"

class EchoServer
{
public:
    EchoServer(DataBag *dataPtr, unsigned short port, const string &ip = "127.0.0.1");
    ~EchoServer();

    void onConnection(const TcpConnectionPtr &);
    void onMessage(const TcpConnectionPtr &);
    void onClose(const TcpConnectionPtr &);

    void start();

private:
    Threadpool _threadpool;
    TcpServer _server;
    DataBag *_dataPtr;
};

#endif