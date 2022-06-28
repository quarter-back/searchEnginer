#ifndef __INETADDRESS_HH__
#define __INETADDRESS_HH__
#include <arpa/inet.h>
#include <string.h>
#include <string>

using std::string;

class InetAddress {
  public:
    InetAddress(const string &ip, unsigned short port)
        : _addr() {
        bzero(&_addr, sizeof(struct sockaddr_in));
        _addr.sin_family = AF_INET;
        _addr.sin_port = htons(port);
        _addr.sin_addr.s_addr = inet_addr(ip.c_str());
    }

    InetAddress(const struct sockaddr_in &addr)
        : _addr(addr) {}

    ~InetAddress() {}

    string ip() const { return string(inet_ntoa(_addr.sin_addr)); }

    unsigned short port() const { return ntohs(_addr.sin_port); }

    const sockaddr_in *getInetAddrPtr() const { return &_addr; }

  private:
    struct sockaddr_in _addr;
};
#endif
