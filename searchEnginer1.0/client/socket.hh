#ifndef __SOCKET_HH__
#define __SOCKET_HH__

#include "noCopy.hh"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

class Socket : NoCopy {
  public:
    Socket() {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        if (_fd < 0) {
            perror("socket()");
            return;
        }
    }

    explicit Socket(int fd) : _fd(fd) {}

    ~Socket() { close(_fd); }

    int fd() const { return _fd; }

    void shutDownWrite() {
        int ret = shutdown(_fd, SHUT_WR);
        if (ret) {
            perror("shutdown");
            return;
        }
    }

  private:
    int _fd;
};

#endif
