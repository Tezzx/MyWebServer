#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

#include"server_deal.h"
#include"threadpool.h"

#define MAX_EVENTS

class server{

public:
    server(int);
    ~server();

private:
    void init(int);//套接字初始化
    void init_sql();//数据库连接初始化
    void init_sem();//信号处理初始化
    void work();
    void eventloop();

private:
    int m_listenfd;
    int m_epollfd;
    sockaddr_in m_address;
    int m_port;
    epoll_event m_events[MAX_EVENTS];
    int stop=0;
    threadpool m_pool;
};