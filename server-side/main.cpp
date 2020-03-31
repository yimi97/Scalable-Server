#include "server.h"
#include "server.cpp"

using namespace std;
int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: bucketNum, MODE(PER/PRE)" << endl;
        exit(EXIT_FAILURE);
    }
    int bucketNum = atoi(argv[1]);

    Server * s = new Server(bucketNum);
    s->run(); //TODO: PER/PRE

    return EXIT_SUCCESS;
}