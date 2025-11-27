#include <stdio.h>
#include <unistd.h>

#include "client.h"
#include "common.h"
#include "server.h"

void print_help() {
    printf("socket_test <address>\n");
    printf("\tIf No Arguments are givin it will run as a server on port:%d\n", PORT);
    printf("\t<address> - If running a client must specify address of the server it is trying to connect to\n");
}

int main(int argc, char *argv[]) {
    print_help();
    if (argc == 1) {
        printf("RUNNING SERVER\n");
        int server_fd = start_server();
        if (server_fd == STATUS_ERROR) {
            printf("Issue setting up server\n");
            return -1;
        }
        while (1) {
            int client_fd = accept_clients(server_fd);
            if (client_fd == STATUS_ERROR) {
                printf("Issue accepting client\n");
                return -1;
            }
            if(handle_client(client_fd) == STATUS_ERROR) {
                printf("Had issues handling client request\n");
                close(client_fd);
                close(server_fd);
                return -1;
            }
            close(client_fd);
        }
        close(server_fd);
    } else {
        printf("RUNNING CLIENT\n");
        int client_fd = connect_to_server(argv[1]);
        if (client_fd == -1) {
            printf("Error: Coult not connect to server\n");
            return -1;
        }
        if (handle_server(client_fd) == STATUS_ERROR) {
            printf("Error: Receiving server header\n");
            close(client_fd);
            return -1;
        }
        close(client_fd);
    }
    return 0;
}
