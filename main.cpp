#include"server.h"

int main(){

    server m_server(8888);
    m_server.eventloop();
    
}