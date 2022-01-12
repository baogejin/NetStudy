#include "BEpoll.h"

BEpoll::BEpoll()
{
    m_iSize = 0;
    m_iEpollFd = -1;
    m_iEventCnt = 0;
    m_pEvents = nullptr;
}

BEpoll::~BEpoll()
{
    if(m_iEpollFd >= 0)
    {   
        close(m_iEpollFd);
    }   
    if(m_pEvents)
    {   
        free(m_pEvents);
    }   
}

int32_t BEpoll::EpollCreate(int iSize)
{
    m_iSize = iSize;
    bzero(&m_stEpollEvent, sizeof(m_stEpollEvent));
    m_stEpollEvent.events = EPOLLIN | EPOLLET;
    m_stEpollEvent.data.ptr = nullptr;
    m_stEpollEvent.data.fd = -1;

    m_pEvents = (struct epoll_event *) malloc(m_iSize * sizeof(struct epoll_event));
    if(nullptr == m_pEvents)
    {
        return -1;
    }
    m_iEpollFd = epoll_create(m_iSize);
    if(m_iEpollFd < 0)
    {
        return -1;
    }
    return 0;
}

int32_t BEpoll::EpollAdd(int32_t iFd)
{
    if(iFd < 0)
    {
        return -1;
    }
    m_stEpollEvent.data.fd = iFd;
    return epoll_ctl(m_iEpollFd, EPOLL_CTL_ADD, iFd, &m_stEpollEvent);
}

int32_t BEpoll::EpollDel(int32_t iFd)
{
    if(iFd < 0)
    {
        return -1;
    }
    m_stEpollEvent.data.fd = iFd;
    return epoll_ctl(m_iEpollFd, EPOLL_CTL_DEL, iFd, &m_stEpollEvent);
}

int32_t BEpoll::EpollWait(int32_t iTimeout)
{
    m_iEventCnt = epoll_wait(m_iEpollFd, m_pEvents, m_iSize, iTimeout);
    return m_iEventCnt;
}

int32_t BEpoll::GetEpollFd()
{
    return m_iEpollFd;
}

struct epoll_event* BEpoll::GetEvent(int32_t iIndex)
{
    if(m_iEventCnt <= 0 || iIndex >= m_iEventCnt || iIndex < 0)
    {
        return nullptr;
    }
    return &m_pEvents[iIndex]; 
}
