#ifndef __TCPCNNECTION_H__
#define __TCPCNNECTION_H__
#include "inetAddress.hh"
#include "socket.hh"
#include "socketIO.hh"

class TcpConnection {
  public:
    TcpConnection(const string &ip, unsigned short port);
    ~TcpConnection();
    void send(const string &msg);
    string receive();
    string toString();
    void connection();

  private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

  private:
    Socket _socket;
    SocketIO _socketIO;
    InetAddress _serverAddr;
    InetAddress _localAddr;
    InetAddress _peerAddr;
};
#endif
