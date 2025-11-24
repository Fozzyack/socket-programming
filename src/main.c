#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    struct sockaddr_in server_info = {0};
    server_info.sin_family = AF_INET;
    server_info.sin_addr.s_addr = 0;
    server_info.sin_port = htons(5555);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }

    if(bind(fd, (struct sockaddr *)&server_info, sizeof(server_info)) == -1) {
        perror("bind");
        close(fd);
        return -1;
    }


    close(fd);

    return 0;
}
