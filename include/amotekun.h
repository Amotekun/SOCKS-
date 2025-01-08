/* amotekun.h */
#ifndef AMOTEKUN_H
#define AMOTEKUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // For close()
#include <sys/socket.h> // For socket(), connect()
#include <arpa/inet.h>  // For htons(), inet_addr()
#include <netinet/in.h>

#define PROXY "127.0.0.1"
#define PROXYPORT 9050

#endif