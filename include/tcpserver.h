#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_
#include "/home/kk/Desktop/server/include/epoll.h"
#include "/home/kk/Desktop/server/include/socket.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <memory>
using namespace std;
// 封装服务器的功能  绑定连接，监听连接，获取连接
class TcpConnection {
private:
  struct sockaddr_in server_addr; // 服务器地址
  int sock_fd = -1;                    // 初始化 绑定 监听
  //int server_fd;                  // 连接
  unique_ptr<Epoll> tcp_epoll;
  unique_ptr<Socket> tcp_socket;
  unique_ptr<Logger> logger;
public: 
  void run();

//回调函数的主体， 之后作为对象传递到epoll上。
  void tcpConnectionCB();
  void tcpCloseCB(Socket* s);
  void tcpReadCB(Socket* s); 
  void tcpSendCB(Socket* s);  
public:
  TcpConnection(string ip, int port);
  //void initAddress(); //配置地址
  int bindSocket(); //绑定
  int listenSocket(); //监听
  int connectSocket(); //接受客户端
  void init();
};
#endif