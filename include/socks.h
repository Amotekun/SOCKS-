#ifndef SOCKS_H
#define SOCKS_H

#include <stdint.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    uint8_t vn;
    uint8_t cd;
    uint16_t dstport;
    uint32_t dstip;
    char userid[8];
} Req;

typedef struct
{
    uint8_t vn;
    uint8_t cd;
    uint16_t reserved;
    uint32_t reserved_ip;
} Res;

void build_socks4_request(Req *req, uint16_t port, uint32_t ip, const char *userid);
void log_request(const Req *req);
void log_response(const Res *res);

#endif