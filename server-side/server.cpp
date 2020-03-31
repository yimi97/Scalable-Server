#include "server.h"

#define BUFFER_SIZE 512
using namespace std;

void request_handler(int client_fd, string req, vector<int> * buckets) {
    //parse request
    int delimiter = req.find(',');
    int delay = stoi(req.substr(0, delimiter));
    int bucketNum = stoi(req.substr(delimiter + 1));
    //delay
    struct timeval start, check, end;
    double elapsed_seconds;
    gettimeofday(&start, NULL);
    do {
        gettimeofday(&check, NULL); 
        elapsed_seconds = (check.tv_sec + (check.tv_usec/1000000.0)) - (start.tv_sec + (start.tv_usec/1000000.0)); 
    } while (elapsed_seconds < delay);
    //lock and add

    //TODO: lock the single element!
    
    buckets->at(bucketNum) = buckets->at(bucketNum) + delay;
    //sendBack
    stringstream ss;
    ss << buckets->at(bucketNum);
    const char * value = ss.str().c_str();
    cout << "[DEBUG] new value is " << value << endl;
    send(client_fd, value, strlen(value), 0);

    //TODO: unlock

    //closeFd
    close(client_fd);
}
Server::Server(int bucketNum) {

    buckets = new vector<int>(bucketNum, 0);
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
        int client_connection_fd;
        client_connection_fd = accept(socket_fd, (struct sockaddr *)&socket_addr, &socket_addr_len);
        if (client_connection_fd == -1) {
            cerr << "Error: cannot accept connection on socket" << endl;
            continue;
        } //if
        //receive
        char buffer[BUFFER_SIZE];
        recv(client_connection_fd, buffer, BUFFER_SIZE, 0);
        cout << "[DEBUG] received request" << buffer << endl;
        //create thread
        thread t(request_handler, client_connection_fd, string(buffer), buckets);
        t.detach();
    }
}

Server::~Server() {
    delete buckets;
    freeaddrinfo(host_info_list);
    close(socket_fd);
}

