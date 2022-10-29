#include "/home/kk/Desktop/server/include/tcpserver.h"
#include "/home/kk/Desktop/server/include/logger.h"
#include <asm-generic/errno-base.h>
#include <cerrno>
#include <new>
#include <sys/epoll.h>
#include <sys/socket.h>

TcpConnection::TcpConnection(string ip, int port) {
  // 创建
  sock_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
  //  if (sock_fd == -1) {
  //
  //}
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
}

int TcpConnection::bindSocket() {
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        logger->setLog(Log::Error, "Bind ERROR");
        return -1;
    }
    return 0;
}

int TcpConnection::listenSocket() {
    if (listen(sock_fd, 20) == -1) {
        logger->setLog(Log::Error, "listen ERROR");
        return -1;
    }
    return 0;
}

void TcpConnection::init() {
    tcp_epoll.reset(new Epoll); //初始化
    tcp_socket.reset(new Socket(sock_fd));
    logger.reset(new Logger);
}

void TcpConnection::tcpConnectionCB() {
    //while (true) {
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        char* clientIP = new char[INET_ADDRSTRLEN];
        int client_fd = accept(sock_fd, (struct sockaddr*)&cli_addr, &cli_len);
        if (client_fd == -1) {
            if (errno == EAGAIN) {
                logger->setLog(Log::Error, "get connection ERROR");    
                //break;
            }
        }
        inet_ntop(AF_INET, &cli_addr.sin_addr, clientIP, INET_ADDRSTRLEN);
        Socket* s = new Socket(client_fd, clientIP); //注册新的事件
        logger->setLog(Log::Info, s->getIP() + " connect!");
        tcp_epoll->addTo(client_fd, s, (EPOLLIN | EPOLLET)); //将事件插入epoll存储结构中
    //}
}

void TcpConnection::tcpCloseCB(Socket* s) {
    int fd = s->getFd();
    tcp_epoll->delFro(fd, s, 0);
    close(fd);
    delete s;
    s = nullptr; 
}

void TcpConnection::tcpReadCB(Socket *s) {
    int fd = s->getFd();
    int n = s->readData();
    if (n > 0) {
        logger->setLog(Log::Info, s->getIP() + ":" + s->getBf());
        tcp_epoll->modAt(fd, s, EPOLLOUT);//转为可写事件
    }
    if (n == -1) {
        logger->setLog(Log::Error, s->getIP() + ":" + "readData ERROR");
    }
    if (n == 0) {
        logger->setLog(Log::Info, s->getIP() + ":" + "closed the connection");
        tcpCloseCB(s);
    }
}

void TcpConnection::tcpSendCB(Socket *s) {
    int fd = s->getFd();
    int n = s->writeData();
    if (n > 0) {
        logger->setLog(Log::Info, "send to " + s->getIP() + ":" + s->getBf());
        //转为可读事件
        tcp_epoll->modAt(fd, s, EPOLLIN);
    } else if (n == -1) {
        logger->setLog(Log::Error, "read from" + s->getIP() + ":" + "ERROR");
    }
}

void TcpConnection::run() {
    tcp_epoll->addTo(sock_fd, tcp_socket.get(), (EPOLLIN | EPOLLET));
    tcp_epoll->setConnectionCB(bind(&TcpConnection::tcpConnectionCB, this));
    tcp_epoll->setCloseCB(bind(&TcpConnection::tcpCloseCB, this, placeholders::_1));
    tcp_epoll->setReadCB(bind(&TcpConnection::tcpReadCB, this, placeholders::_1));
    tcp_epoll->setSendCB(bind(&TcpConnection::tcpSendCB, this, placeholders::_1));
    logger->setLog(Log::Info, "server start");
    while (true) {
        int num = tcp_epoll->waitFor(-1);
        if (num > 0) {
            tcp_epoll->handler(sock_fd, num);
        }
    }
}