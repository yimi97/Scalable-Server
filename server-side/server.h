#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include <sys/time.h>
#include <sstream>
#include <mutex>
#include <list>

#define HOSTNAME "127.0.0.1"
#define PORT "12345"
#define BUFFER_SIZE 20
#define POOL_SIZE 500


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
