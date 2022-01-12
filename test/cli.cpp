#include "../common/BSocket.h"
#include <iostream>
int main()
{
    char ip[] = "00:16:3e:12:99:82";
    int fd = tcp_connect(ip,7788,AF_INET6);
    std::cout<<fd <<std::endl;
    return 0;
}
