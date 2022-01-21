#ifndef B_SOCKET_H
#define B_SOCKET_H

#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int TcpServer(int iPort, int iFamily = AF_INET);
int TcpConnect(const char* szHost, int iPort, int iFamily = AF_INET);

#endif
