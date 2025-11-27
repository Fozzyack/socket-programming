#ifndef CLIENT_H
#define CLIENT_H

#define PORT 5555
#define BACKLOG 10
#define BIND_ADDR 0

int connect_to_server(char *);
int handle_server(int sock_fd);

#endif // !CLIENT_H
