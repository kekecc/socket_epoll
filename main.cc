#include "/home/kk/Desktop/server/include/socket.h"
#include "/home/kk/Desktop/server/include/logger.h"
#include "/home/kk/Desktop/server/include/epoll.h"
#include "/home/kk/Desktop/server/include/tcpserver.h"

int main() {
    TcpConnection my_connection("127.0.0.1", 8888);
    //cout << "成功" << endl; 未初始化导致读取了未知内存
    
    my_connection.init();
    my_connection.bindSocket();
    my_connection.listenSocket();
    my_connection.run();
    return 0;
}