#include "../common/BSocket.h"
#include <iostream>
#include <string>
int main()
{
    char ip[] = "127.0.0.1";
    int fd = TcpConnect(ip,7788);
    std::cout<<fd <<std::endl;
    char szMsg[] = "hello svr, i am cli!";
    write(fd, szMsg, sizeof(szMsg));
    std::string strMsg = "\n";
    while(getline(std::cin,strMsg))
    {
        write(fd, strMsg.c_str(), strMsg.length());
    }
    return 0;
}
