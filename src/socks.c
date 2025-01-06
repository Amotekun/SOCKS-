#include "socks.h"

void build_socks4_request(Req *req, uint16_t port, uint32_t ip, const char *userid)
{
    req->vn = 4;
    req->cd = 1;
    req->dstport = htons(port);
    req->dstip = htonl(ip);
    strncpy(req->userid, userid, sizeof(req->userid));
    req->userid[sizeof(req->userid) - 1] = '\0';
}

void log_request(const Req *req)
{
    printf("SOCKS4 Request: \n");
    printf(" Version: %d\n", req->vn);
    printf(" Command: %d\n", req->cd);
    printf(" Port: %d\n", ntohs(req->dstport));
    printf(" IP: %s\n", inet_ntoa((struct in_addr){ntohl(req->dstip)}));
    printf(" Userid: %s\n", req->userid);
}

void log_response(const Res *res)
{
    printf("SOCKS4 Response:\n");
    printf(" Version: %d\n", res->vn);
    printf(" Response Code: %d\n", res->cd);
}