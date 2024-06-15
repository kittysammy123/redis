//
// Created by xs on 6/15/24.
//

#ifndef REDIS_SOCKETADDRESS_H
#define REDIS_SOCKETADDRESS_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

namespace sammy {

    //封装成sockaddr_in
    class SocketAddress {
    public:
        SocketAddress();
        explicit SocketAddress(const char* ip,uint16_t port);  //ip和端口转换成网路字节序
        SocketAddress(struct sockaddr_in* p_sock_in);

        char* getIp();
        uint16_t getPort();

        struct sockaddr* toSockAddr();  //转换为sockaddr

        std::string toString();  //转换为ip:port形式的string
    private:
        struct sockaddr_in  m_addr;
    };

}  //end namespace sammy



#endif //REDIS_SOCKETADDRESS_H
