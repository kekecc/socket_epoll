#ifndef _EPOLL_H_
#define _EPOLL_H_
#include "/home/kk/Desktop/server/include/socket.h"
#include "/home/kk/Desktop/server/include/logger.h"
#include <memory>
#include <vector>
#include <sys/epoll.h>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#define MAXEVENTS 1024
using namespace std;
//epoll类 封装有关epoll的系统调用
class Epoll {
public:
  Epoll();
  ~Epoll();
  using connectionCallBack = function<void()>; //连接的回调函数
  using thingCallBack = function<void(Socket*)>; //其他事件的回调函数


  int addTo(int fd, Socket* sock, int events); //添加事件
  int modAt(int fd, Socket* sock, int events); //修改事件
  int delFro(int fd, Socket* sock, int events); //删除事件
  int waitFor(int time_out); //等待事件就绪
  int handler(int listen_fd, int num); //传入的第一个表示的是监听描述符 用来判断 后面是就绪事件数量
  
  //回调函数
  void setConnectionCB(const connectionCallBack &cb) {connection_cb = cb;}
  void setCloseCB(const thingCallBack &cb) {close_cb = cb;};
  void setReadCB(const thingCallBack &cb) {read_cb = cb;};
  void setSendCB(const thingCallBack &cb) {send_cb = cb;};
private:
  int epoll_fd;
  unique_ptr<Logger> logger;
  vector<struct epoll_event> events; //就绪列表
  connectionCallBack connection_cb; //连接的回调函数
  thingCallBack close_cb; //关闭连接的回调函数
  thingCallBack read_cb; //读取数据的回调函数
  thingCallBack send_cb; //发送数据的回调函数
};

#endif