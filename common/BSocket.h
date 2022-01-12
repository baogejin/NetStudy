#ifndef B_SOCKET_H
#define B_SOCKET_H

#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int tcp_server(int port, int family = AF_INET);
int tcp_connect(const char* host, int port, int family = AF_INET);

#endif
