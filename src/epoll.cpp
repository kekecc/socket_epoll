#include "/home/kk/Desktop/server/include/epoll.h"
#include "/home/kk/Desktop/server/include/logger.h"
#include <memory>
#include <sys/epoll.h>

Epoll::Epoll():epoll_fd(epoll_create(1)), events(MAXEVENTS) {
    logger.reset(new Logger);
}

Epoll::~Epoll() {
    close(epoll_fd);
    events.clear();
}

int Epoll::addTo(int fd, Socket *sock, int events) { //events代表事件类型
    struct epoll_event event;
    event.data.ptr = (void*)sock; //获取连接参数
    event.events = events; //类型
    
    int re = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
    if (re == -1) {
        logger->setLog(Log::Error, "addToEpoll ERROR");
    }
    return re;
}

int Epoll::modAt(int fd, Socket *sock, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.ptr = (void*) sock;

    int re = epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event);
    if (re == -1) {
        logger->setLog(Log::Error, "modAtEpoll ERROR");
    }
    return re;
}

int Epoll::delFro(int fd, Socket *sock, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.ptr = (void*) sock;
    
    int re = epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &event);
    if (re == -1) {
        logger->setLog(Log::Error, "delFroEpoll ERROR");
    }
    return re;
}

int Epoll::waitFor(int time_out) {
    int num = epoll_wait(epoll_fd, &*events.begin(), static_cast<int>(events.size()), time_out);
    if (num == -1) {
        logger->setLog(Log::Error, "waitFor ERROR");
    }

    return num;
}

int Epoll::handler(int listen_fd, int num) {
    if (num <= 0) {
        logger->setLog(Log::Error, "A nagative num was passed to handler");
        return -1;
    }
    for (int i = 0; i < num; i++) { //xun huan
        Socket* s = (Socket*)events[i].data.ptr; //获取到描述符信息
        int fd = s->getFd();
        if (fd == listen_fd) {
            //回调函数
            connection_cb();
        } else if (events[i].events & EPOLLIN) {
            read_cb(s);
        } else if (events[i].events & EPOLLOUT) {
            send_cb(s);
        }
    }
    return 0;
}