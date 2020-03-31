#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define TEST_NUM 100
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "12345"

using namespace std;
void *client_generator(void* args) {
    int status;
    int socket_fd;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;
    memset(&host_info, 0, sizeof(host_info));
    host_info.ai_family   = AF_UNSPEC;
    host_info.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(SERVER_IP, SERVER_PORT, &host_info, &host_info_list);
    if (status != 0) {
        cout << "Error(Client): cannot get address info for host" << endl;
        exit(EXIT_FAILURE);
    } //if

    socket_fd = socket(host_info_list->ai_family, 
                host_info_list->ai_socktype, 
                host_info_list->ai_protocol);
    if (socket_fd == -1) {
        cout << "Error(Client): cannot create socket" << endl;
        exit(EXIT_FAILURE);
    } //if    
    status = connect(socket_fd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1) {
        cout << "Error(Client): cannot connect to server socket" << endl;
        exit(EXIT_FAILURE);
    } //if

    //generate random numbers
    const char *message = "5, 10\n";
    send(socket_fd, message, strlen(message), 0);

    freeaddrinfo(host_info_list);
    close(socket_fd);
}
int main(int argc, char **argv) {
    int threads[TEST_NUM];
    pthread_attr_t thread_attr[TEST_NUM];
    pthread_t thread_ids[TEST_NUM];

    for (int i = 0; i < TEST_NUM; ++i) {
        threads[i] = pthread_create(&thread_ids[i], NULL, client_generator, NULL);
        //usleep(1000);
    }
    // for (int i = 0; i < THREAD_NUM; ++i) {
    //     pthread_join(thread_ids[i], NULL);
    // }
}