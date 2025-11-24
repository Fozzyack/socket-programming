#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "server.h"
#include "common.h"

int start_server(void) {

    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = BIND_ADDR;
    server.sin_port = htons(PORT);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        return STATUS_ERROR;
    }

    if (bind(sock_fd, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        close(sock_fd);
        return STATUS_ERROR;
    }

    if (listen(sock_fd, BACKLOG) == -1) {
        perror("listen");
        close(sock_fd);
        return STATUS_ERROR;
    }

    return sock_fd;
}

int accept_clients(int sock_fd) {
    struct sockaddr_in client = {0};
    socklen_t client_size = sizeof(struct sockaddr_in);

    int client_fd = accept(sock_fd, (struct sockaddr *)&client, &client_size);
    if (client_fd == -1) {
        perror("accept");
        close(sock_fd);
        return STATUS_ERROR;
    }

    return client_fd;
}
