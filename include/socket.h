#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include <cstring>

using namespace std;
// socket类 封装socket的功能 read write
class Socket {
private:
  char* buffer;
  int sock_fd; // 连接符
  char* IP = new char[16]; //用户地址

public:
  Socket(int sock_fd):sock_fd(sock_fd), buffer(new char[1024]){}
  Socket(int sock_fd, char* IP):sock_fd(sock_fd), IP(IP),buffer(new char[1024]){}
  ~Socket();
  int readData();
  int writeData();
  int getFd();
  string getIP();
  char* getBf();
};
#endif