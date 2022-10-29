#include "/home/kk/Desktop/server/include/socket.h"
//#include "/home/kk/Desktop/server/include/logger.h"
#include <cstdio>
#include <sys/socket.h>


Socket::~Socket() {
    close(sock_fd);
    if (buffer != nullptr) {
        delete [] buffer;
        buffer = nullptr;
    }
}

int Socket::getFd() {
    return sock_fd;
}

string Socket::getIP() {
    return string(IP);
}

char* Socket::getBf() {
    return buffer;
}
int Socket::readData() {
    int re = read(sock_fd, buffer, sizeof(buffer));
    buffer[re] = '\0';
    if (re == -1) {
        //logger.setLog(Log::Error, "readData ERROR");
        return -1;
    }
    if (re == 0) { //客户端强行关闭连接
        //logger.setLog(Log::Info, "one client close the connection");
        return 0;
    }
    if (re > 0) {
        //logger.setLog(Log::Info, (string)buffer + "from client");
        return re;
    }
    return re;
}

int Socket::writeData() {
    int re = send(sock_fd, buffer, strlen(buffer), 0);
    if (re == -1) {
        //logger.setLog(Log::Error, "sendData ERROR");
        return -1;
    }
    if (re > 0) {
        //logger.setLog(Log::Info, string(buffer) + " to client");
        return re;
    }
    return re;
}