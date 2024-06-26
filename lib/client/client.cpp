

#include "client.h"

namespace net
{

Client::Client(int port, std::string ipaddr):
    _port(port),
    _ipaddr(ipaddr),
    _socket_fd(-1),
    _sock_addr_len(sizeof(_socket_addr))
{
    
}


Client::~Client()
{
    if(_socket_fd == -1){
        close(-_socket_fd);
    }
}



int Client::init()
{
    int ret = -1;

    _socket_addr.sin_family = AF_INET;
    _socket_addr.sin_port = htons(_port);
    _socket_addr.sin_addr.s_addr = INADDR_ANY;

    _socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(_socket_fd == -1){
        std::cerr << "[ERROR] Error create socket\n";
        return ret;
    }

    ret = 0;
    return ret;

}


void Client::recieve()
{



    socklen_t len = sizeof(_sock_addr_len);

    _recv_size = recvfrom(_socket_fd, _buffer, BUFFER_SIZE, 0, (struct sockaddr*) & _socket_addr, &len);

    if(_recv_size == -1){
        std::cerr << "[ERROR] recieve" << std::endl;
        exit(-1);
    }


}


void Client::process()
{


    // // do some work here
    if(_recv_size > 0){

        std::cout << "Client: ";
        for(int i = 0; i < _recv_size; ++i){
            std::cout << _buffer[i];
        }

        std::cout << std::endl;

    }

}


void Client::send()
{

    std::string message;
    std::getline(std::cin, message);


    int status = sendto(_socket_fd, message.c_str(), message.size(), 0, (struct sockaddr*)&_socket_addr, _sock_addr_len);
    if(status == -1){
        std::cerr << "[ERROR] Client send" << std::endl;
    }


}


void Client::connect()
{

    init();


    for(;;){
        send();
        recieve();
        process();
        
    }


}



}