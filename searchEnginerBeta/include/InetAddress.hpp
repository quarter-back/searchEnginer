#ifndef __INETADDRESS_HPP__
#define __INETADDRESS_HPP__

#include <netinet/in.h>

#include <string>

using std::string;

class InetAddress
{
public:
    InetAddress(unsigned short port, const string &ip);
    InetAddress(const sockaddr_in &addr);
    ~InetAddress();

    unsigned short getPort() const;
    string getIp() const;

    sockaddr_in *getSockaddrprt();

private:
    sockaddr_in _addr;
};

#endif