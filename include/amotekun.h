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

/*
- these are the header files and they are used for filling in the gap when the program is spun up
- in the sense that when there is a spot they need to fill they are there to fill it
- the #ifndef and #endif here simply mean that if the files are not yet defined, they can be defined, if not they cannot be defined.

- #include <stdio.h>  this is a system call for basic input and output
#include <stdlib.h> this are standard library [insert the meaning, i do not know what they do]
#include <string.h> this is a standard library for the string
#include <unistd.h>     // For close() used for closing sockets, if i am correct?
#include <sys/socket.h> // For socket(), connect() this are used to create a socket and also used to connect server and a client to the socket, i am not so sure though, if they are used to listen and accept connections as well. help me out with that
#include <arpa/inet.h>  // For htons(), inet_addr() these are for network byte order, in the sense that they translate, IP string address to network order and also int PORT to network order, majorly the big endian
#include <netinet/in.h> these I have no idea what they do
*/