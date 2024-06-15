//
// Created by xs on 6/15/24.
//

#include "SocketAddress.h"

#include <cstring>
#include <arpa/inet.h>

namespace  sammy {

    SocketAddress::SocketAddress() {
        std::memset(&m_addr,0,sizeof(struct sockaddr_in));
        m_addr.sin_family = AF_INET;
    }

    SocketAddress::SocketAddress(const char *ip, uint16_t port) {
        m_addr.sin_port = htons(port);
        m_addr.sin_addr.s_addr = inet_addr(ip);
        m_addr.sin_family = AF_INET;
    }

    SocketAddress::SocketAddress(struct sockaddr_in *p_sock_in) {
        m_addr = *p_sock_in;
    }

    char *SocketAddress::getIp() {
        return inet_ntoa(m_addr.sin_addr);
    }

    uint16_t SocketAddress::getPort() {
        return ntohs(m_addr.sin_port);
    }

    struct sockaddr *SocketAddress::toSockAddr() {
        return reinterpret_cast<struct sockaddr*>(&m_addr);
    }

    std::string SocketAddress::toString() {
        std::string res;

        res.append(getIp());
        res.append(":");
        res.append(std::to_string(getPort()));

        return res;
    }
}