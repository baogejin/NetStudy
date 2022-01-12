#include "BSocket.h"

int tcp_server(int port, int family) //默认ipv4
{
    int socketfd = socket(family, SOCK_STREAM, 0);
    if(socketfd < 0)
    {
        return -1;
    }
    int bindret = 1;
    if(family == AF_INET)
    {
        struct sockaddr_in svraddr;
        bzero(&svraddr, sizeof(svraddr));
        svraddr.sin_family = family;
        svraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        svraddr.sin_port = htons(port);
        bindret = bind(socketfd, (struct sockaddr *)&svraddr, sizeof(svraddr));
    }else if(family == AF_INET6)
    {
        struct sockaddr_in6 svraddr;
        bzero(&svraddr, sizeof(svraddr));
        svraddr.sin6_family = family;
        svraddr.sin6_addr = in6addr_any;
        svraddr.sin6_port = htons(port);
        bindret = bind(socketfd, (struct sockaddr *)&svraddr, sizeof(svraddr));
    }
    if(bindret != 0)
    {
        close(socketfd);
        return -1;
    }
    int listenret = listen(socketfd, 5);
    if(listenret != 0)
    {
        close(socketfd);
        return -1;
    }
    return socketfd;
}

int tcp_connect(const char* host, int port, int family) //默认ipv4
{
    int socketfd = socket(family, SOCK_STREAM, 0);
    if(socketfd < 0)
    {
        return -1;
    }
    int ret = -1;
    if(family == AF_INET)
    {
        struct sockaddr_in svraddr;
        bzero(&svraddr, sizeof(svraddr));
        svraddr.sin_family = family;
        inet_pton(family, host, &svraddr.sin_addr);
        svraddr.sin_port   = htons(port);
        ret = connect(socketfd, (struct sockaddr *)&svraddr, sizeof(svraddr));
    }else if(family == AF_INET6)
    {
        struct sockaddr_in6 svraddr;
        bzero(&svraddr, sizeof(svraddr));
        svraddr.sin6_family = family;
        inet_pton(AF_INET6, host, &svraddr.sin6_addr);
        svraddr.sin6_port = htons(port);
        ret = connect(socketfd, (struct sockaddr *)&svraddr, sizeof(svraddr));
    }
    if(ret < 0)
    {
        close(socketfd);
        return -1;
    }
    return socketfd;
}
