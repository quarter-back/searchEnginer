#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

class Socket
{
public:
    Socket();
    explicit Socket(int fd);
    ~Socket();

    int getFd()const;
    void setNonBlock();
    void shutdownWrite();

private:
    int _fd;
};

#endif