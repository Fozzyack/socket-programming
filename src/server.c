#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "server.h"

int start_server(void) {

    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = BIND_ADDR;
    server.sin_port = htons(PORT);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        return -1;
    }

    if (bind(sock_fd, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        close(sock_fd);
        return -1;
    }

    if (listen(sock_fd, BACKLOG) == -1) {
        perror("listen");
        close(sock_fd);
        return -1;
    }

    return sock_fd;
}
