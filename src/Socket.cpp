//
// Created by xs on 6/15/24.
//

#include "Socket.h"

namespace sammy {

    Socket::Socket() : m_sockFd(INVALID_SOCKET),m_isBlock(false) {
    }

    void Socket::initSocket() {
        m_sockFd = socket(AF_INET,SOCK_STREAM,0);
        if(m_sockFd == INVALID_SOCKET) {
            //直接抛错
        }
    }

    void Socket::connect(const sammy::SocketAddress &address) {
        if(m_sockFd == INVALID_SOCKET) {
            initSocket();
        }

    }

    void Socket::error(int code) {
        std::string str;
        error(code,str);
    }

    void Socket::error(int code, const std::string &arg) {
        switch (code) {

            case EFAULT:
                throw std::exception("Bad address");
        }    
    }
    
}