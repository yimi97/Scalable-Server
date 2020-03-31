#include "server.h"
#include "request.cpp"

using namespace std;

void request_handler(int client_fd, Request req, vector<atomic<int>> * buckets) {
    int delay = req.getDelay();
    int bucketNum = req.getBucketNum();
    //delay
    //fetch_add
    //sendBack
    //closeFd

}
Server::Server(int bucketNum) {

    buckets = new vector<atomic<int>>(bucketNum);
    socklen_t socket_addr_len = sizeof(socket_addr);
    memset(&host_info, 0, sizeof(host_info));
    host_info.ai_family   = AF_UNSPEC;
    host_info.ai_socktype = SOCK_STREAM;
    host_info.ai_flags    = AI_PASSIVE;
    status = getaddrinfo(HOSTNAME, PORT, &host_info, &host_info_list);
    if (status != 0) {
        cerr << "Error: cannot get address info for host" << endl;
        cerr << "  (" << HOSTNAME << "," << PORT << ")" << endl;
        exit(EXIT_FAILURE);
    } //if

    socket_fd = socket(host_info_list->ai_family, 
                host_info_list->ai_socktype, 
                host_info_list->ai_protocol);
    if (socket_fd == -1) {
        cerr << "Error: cannot create socket" << endl;
        cerr << "  (" << HOSTNAME << "," << PORT << ")" << endl;
        exit(EXIT_FAILURE);
    } //if

    int yes = 1;
    status = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    status = bind(socket_fd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1) {
        cerr << "Error: cannot bind socket" << endl;
        cerr << "  (" << HOSTNAME << "," << PORT << ")" << endl;
        exit(EXIT_FAILURE);
    } //if

    status = listen(socket_fd, 100);
    if (status == -1) {
        cerr << "Error: cannot listen on socket" << endl; 
        cerr << "  (" << HOSTNAME << "," << PORT << ")" << endl;
        exit(EXIT_FAILURE);
    } //if
}

void Server::run() {
    while(true) {
        //accept
        //receive and create req
        //create thread, pass fd and req
    }
}

Server::~Server() {
    delete buckets;
    freeaddrinfo(host_info_list);
    close(socket_fd);
}

