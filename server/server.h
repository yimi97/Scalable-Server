#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <atomic>
#include <vector>

#define HOSTNAME "127.0.0.1"
#define PORT "12345"

class Server {
private:
    int status;
    int socket_fd;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;
    struct sockaddr_storage socket_addr;
    socklen_t socket_addr_len;
    std::vector<atomic<int>> * buckets;
public:
    Server(int bucketNum);
    void run();
    ~Server();
};
#endif
