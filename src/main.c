#include <stdio.h>
#include <unistd.h>

#include "client.h"
#include "common.h"
#include "server.h"

void print_help() {
    printf("socket_test <addr>\n");
    printf("\tIf No Arguments are givin it will run as a server on %d\n", PORT);
    printf("\t<port_number> - If running a client must specify address\n");
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
                return STATUS_ERROR;
            }
            close(client_fd);
        }
        close(server_fd);
    } else {
        printf("RUNNING CLIENT\n");
        connect_to_server(argv[1]);
    }
    return 0;
}
