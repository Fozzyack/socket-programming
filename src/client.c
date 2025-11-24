#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "server.h"
#include "common.h"

int connect_to_server(char *addr) {
    struct sockaddr_in server = {0}; // The server we are trying to connect to 
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(addr);
    server.sin_port = htons(PORT);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        return STATUS_ERROR;
    }

    if (connect(sock_fd, (struct sockaddr *) &server, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        close(sock_fd);
        return STATUS_SUCCESS;
    }

    close(sock_fd);
    return 0;

}
