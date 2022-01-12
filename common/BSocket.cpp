#include "BSocket.h"

int TcpServer(int iPort, int iFamily) //默认ipv4
{
    int iSocketFd = socket(iFamily, SOCK_STREAM, 0);
    if(iSocketFd < 0)
    {
        return -1;
    }
    int iBindRet = 1;
    if(iFamily == AF_INET)
    {
        struct sockaddr_in stSvrAddr;
        bzero(&stSvrAddr, sizeof(stSvrAddr));
        stSvrAddr.sin_family = iFamily;
        stSvrAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        stSvrAddr.sin_port = htons(iPort);
        iBindRet = bind(iSocketFd, (struct sockaddr *)&stSvrAddr, sizeof(stSvrAddr));
    }else if(iFamily == AF_INET6)
    {
        struct sockaddr_in6 stSvrAddr;
        bzero(&stSvrAddr, sizeof(stSvrAddr));
        stSvrAddr.sin6_family = iFamily;
        stSvrAddr.sin6_addr = in6addr_any;
        stSvrAddr.sin6_port = htons(iPort);
        iBindRet = bind(iSocketFd, (struct sockaddr *)&stSvrAddr, sizeof(stSvrAddr));
    }
    if(iBindRet != 0)
    {
        close(iSocketFd);
        return -1;
    }
    int iListenRet = listen(iSocketFd, 5);
    if(iListenRet != 0)
    {
        close(iSocketFd);
        return -1;
    }
    return iSocketFd;
}

int TcpConnect(const char* szHost, int iPort, int iFamily) //默认ipv4
{
    int iSocketFd = socket(iFamily, SOCK_STREAM, 0);
    if(iSocketFd < 0)
    {
        return -1;
    }
    int iRet = -1;
    if(iFamily == AF_INET)
    {
        struct sockaddr_in stSvrAddr;
        bzero(&stSvrAddr, sizeof(stSvrAddr));
        stSvrAddr.sin_family = iFamily;
        inet_pton(iFamily, szHost, &stSvrAddr.sin_addr);
        stSvrAddr.sin_port   = htons(iPort);
        iRet = connect(iSocketFd, (struct sockaddr *)&stSvrAddr, sizeof(stSvrAddr));
    }else if(iFamily == AF_INET6)
    {
        struct sockaddr_in6 stSvrAddr;
        bzero(&stSvrAddr, sizeof(stSvrAddr));
        stSvrAddr.sin6_family = iFamily;
        inet_pton(AF_INET6, szHost, &stSvrAddr.sin6_addr);
        stSvrAddr.sin6_port = htons(iPort);
        iRet = connect(iSocketFd, (struct sockaddr *)&stSvrAddr, sizeof(stSvrAddr));
    }
    if(iRet < 0)
    {
        close(iSocketFd);
        return -1;
    }
    return iSocketFd;
}
