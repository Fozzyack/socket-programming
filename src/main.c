#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9191
#define BACKLOG 5

int start_server(void) {
    // Your code here
    struct sockaddr_in server_info = {0};
    struct sockaddr_in client_info = {0};


    socklen_t client_size = sizeof(client_info);

    server_info.sin_family = AF_INET;
    server_info.sin_addr.s_addr = INADDR_ANY;
    server_info.sin_port = htons(PORT);



    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }

    if (bind(fd, (struct sockaddr *) &server_info, sizeof(server_info)) == -1) {
        perror("bind");
        close(fd);
        return -1;
    }
    

    if (listen(fd, 5) == -1) {
        perror("listen");
        close(fd);
        return -1;
    }

    int cfd = accept(fd, (struct sockaddr *)&client_info, &client_size);
    if (cfd == -1) {
        perror("accept");
        close(fd);
        return -1;

    }

    return cfd;
}


int main() {
    int fd = start_server();
    if (fd != -1) {
        close(fd);
    }
    return 0;
}
