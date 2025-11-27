
#ifndef SOCKET_H
#define Scoket

#define PORT 5555
#define BACKLOG 10
#define BIND_ADDR 0

typedef enum {
    PROTO_HELLO,

} proto_type_e;

typedef struct {
    proto_type_e type;
    unsigned short len;
} proto_hdr_t;

int start_server(void);
int accept_clients(int sock_fd);
int handle_client(int sock_fd);

#endif // SOCKET_H
