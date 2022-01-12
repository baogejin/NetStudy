#include "../common/BSocket.h"
#include "../common/BEpoll.h"
#include <iostream>
int main()
{
    BEpoll stEpoll;
    int32_t iEpollFd = stEpoll.EpollCreate(111);
    if(iEpollFd < 0)
    {
        std::cout << "EpollCreate err " << iEpollFd << std::endl;
        return 0;
    }

    int iSockFd = TcpServer(7788);
    if(iSockFd < 0)
    {
        std::cout << "TcpServer err " << iSockFd << std::endl;
        return 0;
    }
    stEpoll.EpollAdd(iSockFd);
    for(;;)
    {
        int32_t iCnt = stEpoll.EpollWait();
        for(int i=0;i<iCnt;++i)
        {
            auto* pstEvent = stEpoll.GetEvent(i);
            if(iSockFd == pstEvent->data.fd)
            {
                struct sockaddr_in stAddr;
                socklen_t iLen = sizeof(stAddr);
                int32_t iCliFd = accept(iSockFd, (struct sockaddr *)&stAddr, &iLen);
                if(iCliFd < 0)
                {
                    std::cout << "accept cli err " << iCliFd <<std::endl;
                    continue;
                }
                char szAddr[16];
                inet_ntop(AF_INET, &stAddr.sin_addr, szAddr, sizeof(szAddr));
                std::cout<< "accept " << szAddr <<":"<<ntohs(stAddr.sin_port)<<std::endl;
                stEpoll.EpollAdd(iCliFd);
            }
            else 
            {
                char szMsg[111];
                int32_t iLen = read(pstEvent->data.fd, szMsg, 110);
                if(iLen <= 0)
                {
                    std::cout << "epoll del "<< pstEvent->data.fd << " " << stEpoll.EpollDel(pstEvent->data.fd) << std::endl;
                    close(pstEvent->data.fd);
                    continue;
                }
                else 
                {
                    szMsg[iLen] = '\0';
                    std::cout << szMsg <<std::endl;
                }
            }

        }
    }

    return 0;
}
