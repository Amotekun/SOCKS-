#include "amotekun.h"
#include "socks.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    printf("Host: %s, Port: %d\n", host, port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        error_exit("socket");
    }

    printf("Socket created successfully: %d\n", sock);

    struct sockaddr_in proxy_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PROXYPORT),
        .sin_addr.s_addr = inet_addr(PROXY)};

    if (connect(sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0)
    {
        error_exit("connect");
    }

    printf("Connected to proxy\n");

    Req req;
    build_socks4_request(&req, port, inet_addr(host), "user");
    log_request(&req);

    if (write(sock, &req, sizeof(req)) < 0)
    {
        error_exit("write");
    }

    Res res;
    if (read(sock, &res, sizeof(res)) < 0)
    {
        error_exit("read");
    }

    log_response(&res);

    close(sock);
    return EXIT_SUCCESS;
}
