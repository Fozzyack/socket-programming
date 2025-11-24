#include <stdio.h>

#include "server.h"
#include "common.h"

int main() {
    int server_fd = start_server();
    if (server_fd == STATUS_ERROR) {
        printf("Issue setting up server\n");
        return -1;
    }
    int client_fd = accept_clients(server_fd);
    if (client_fd== STATUS_ERROR) {
        printf("Issue accepting client\n");
        return -1;
    }

    return 0;
}
