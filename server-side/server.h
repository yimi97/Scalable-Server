#ifndef SERVER_H
#define SERVER_H
#include "../config.h"
class Server {
private:
    int status;
    int socket_fd;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;
    struct sockaddr_storage socket_addr;
    socklen_t socket_addr_len;
    std::vector<int> * buckets;
public:
    Server(int bucketNum);
    void per_run();
    void pre_run();
    ~Server();
};
#endif
