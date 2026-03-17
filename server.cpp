#include"server.h"

void server::init(int port){
    m_port=port;

    m_listenfd=socket(PF_INET,SOCK_STREAM,0);
    m_address.sin_addr.s_addr=htonl(INADDR_ANY);
    m_address.sin_family=AF_INET;
    m_address.sin_port=htons(m_port);

    bind(m_listenfd,(sockaddr*)&m_address,sizeof(m_address));
    listen(m_listenfd,10);

    m_epollfd=epoll_create(1);
    epoll_event ev;
    ev.data.fd=m_listenfd;
    ev.events=EPOLLIN | EPOLLET;
    epoll_ctl(m_epollfd,EPOLL_CTL_ADD,m_listenfd,&ev);
}

void server::init_sql(){

}

void server::init_sem(){

}

server::server(int port_t){
    this->init(port_t);
    this->init_sql();
    this->init_threadpool();
    this->init_sem();
}

void server::work(){

}

void server::eventloop(){
    while(!stop){
        int num=epoll_wait(m_epollfd,events,MAX_EVENTS,-1);
        for(int i=0;i<num;i++){
            int sockfd=events[i].data.fd;
            if()//处理新fd
            {
                tool::deal_fd();
            }
            else if()//处理信号
            {
                tool::deal_sem();
            }
            else if()//处理任务
            {
                work();
            }
        }
    }
}