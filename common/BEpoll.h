#ifndef B_EPOLL_H
#define B_EPOLL_H

#include <sys/epoll.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

class BEpoll
{
public:
    BEpoll();
    ~BEpoll();
    int32_t EpollCreate(int iSize);
    int32_t EpollAdd(int32_t iFd);
    int32_t EpollDel(int32_t iFd);
    int32_t EpollWait(int32_t iTimeout = -1);
    int32_t GetEpollFd();
    struct epoll_event* GetEvent(int32_t iIndex);

private:
    int32_t m_iSize;
    int32_t m_iEpollFd;
    int32_t m_iEventCnt;
    struct epoll_event* m_pEvents;
    struct epoll_event m_stEpollEvent;
};


#endif
