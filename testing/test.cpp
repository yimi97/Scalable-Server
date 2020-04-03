#include "../src/config.h"

// ============= change server info here ====================
#define SERVER_ADDR "vcm-14348.vm.duke.edu"
#define SERVER_PORT "12345"
// ==========================================================

using namespace std;
void *client_generator(void* args) {
    int status;
    int socket_fd;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;
    memset(&host_info, 0, sizeof(host_info));
    host_info.ai_family   = AF_UNSPEC;
    host_info.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(SERVER_ADDR, SERVER_PORT, &host_info, &host_info_list);
    if (status < 0) {
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
    int delay = 0;
    int bucketNum = rand() % (BUCKET_NUM - 1) + 0;
    if (DELAY_SMALL) {
        delay = rand() % 3 + 1;
    } else {
        delay = rand() % 20 + 1;
    }
    stringstream ss;
    ss << delay << "," << bucketNum << endl;
    const char *message = ss.str().c_str();
    send(socket_fd, message, strlen(message), 0);
    char valueBuffer[BUFFER_SIZE];
    recv(socket_fd, valueBuffer, BUFFER_SIZE, 0);
    cout << "[DEBUG] receive new value " << valueBuffer << endl;
    freeaddrinfo(host_info_list);
    close(socket_fd);
}
int main(int argc, char **argv) {
    srand (time(NULL));
    pthread_t thread[REQUEST_NUM];

    for (int i = 0; i < REQUEST_NUM; ++i) {
        pthread_create(&thread[i], NULL, client_generator, NULL);
        usleep(1000);
    }
    for (int i = 0; i < REQUEST_NUM; ++i) {
        pthread_join(thread[i], NULL);
    }
    return EXIT_SUCCESS;
}