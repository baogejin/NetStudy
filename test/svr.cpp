#include "../common/BSocket.h"
#include <iostream>
int main()
{
    int fd = tcp_server(7788, AF_INET6);
    std::cout << "fd "<<fd<<std::endl;

    int cfd  = accept(fd,nullptr,nullptr);
    std::cout << cfd <<std::endl;
    return 0;
}
