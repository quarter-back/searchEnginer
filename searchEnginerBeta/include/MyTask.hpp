#ifndef __MYTASK_HPP__
#define __MYTASK_HPP__

#include "TcpConnection.hpp"
#include "DataBag.hpp"



class MyTask
{
public:
    MyTask(const string &, const TcpConnectionPtr &);
    ~MyTask();

    void process(DataBag *dataPtr);
    void parse();

private:
    string _request;
    int operatorId;
    int msgLen;
    string msgContent;
    TcpConnectionPtr _conn;
};

#endif