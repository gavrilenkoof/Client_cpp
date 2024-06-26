#pragma once


#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
namespace net
{


class Client
{
public:
    Client(int, std::string);
    ~Client();

    void connect();

private:
    int init();
    void recieve();
    void process();
    void send();


    static constexpr uint16_t BUFFER_SIZE = 1024;

    int _port;
    std::string _ipaddr;

    sockaddr_in _socket_addr;
    int _socket_fd;
    int _sock_addr_len;

    int _recv_size{-1};
    uint8_t _buffer[BUFFER_SIZE]{0};


};


}



