//
// Created by xs on 6/15/24.
//

#ifndef REDIS_SOCKET_H
#define REDIS_SOCKET_H

#include <chrono>
#include "SocketAddress.h"



namespace  sammy {
    //封装socket常用操作
    class Socket {
    public:
        static const int INVALID_SOCKET = -1;

        Socket();

        //阻塞模式的连接
        void connect(const SocketAddress& address);

        //非阻塞模式的连接
        void connect(const SocketAddress& address,const std::chrono::milliseconds& timeout);

        //绑定,用于设置地址服用，解决服务器重启后快速绑定端口问题
        void bind(const SocketAddress& address,bool reuseAddress = false);

        //reuseport允许多个套接字绑定到一个端口，用于负载均衡，内核会自动将连接负载均衡转载
        void bind(const SocketAddress& address,bool reuseAddress, bool reusePort);

        void listen(int backlog = 64);

        Socket* acceptConnection(SocketAddress& clientAddr);

        void close();

        //半关闭
        void shutdownReceive();

        void shutdownSend();

        //全关闭
        void shutdown();

        //发送
        int sendBytes(const void* buffer,int length,int flags = 0);

        int sendBytes(std::string& buffer,int flags = 0);

        int receiveBytes(std::string& buffer,int flags = 0);

        //发送超时时间控制
        void setSendTimeout(std::chrono::milliseconds& timeout);

        std::chrono::milliseconds  getSendTimeout();

        //接收超时时间控制
        void setReceiveTimeout(std::chrono::milliseconds& timeout);

        std::chrono::milliseconds getReceiveTimeout();

        void setSendBufferSize(int size);

        int getSendBufferSize();

        void setReceiveBufferSize(int size);

        int getReceiveBufferSize();

        void setBlocking(bool flag);

        bool getBlocking() const;

        void setReuseAddress(bool flag);

        bool getReuseAddress();

        void setReusePort(bool flag);

        bool getReusePort();

    private:
        void initSocket();

        //封装报错相关处理
        static void error(int code);

        static void error(int code,const std::string& arg);

    private:
        int m_sockFd;
        bool m_isBlock;
    };

} //end of namespace sammy


#endif //REDIS_SOCKET_H
