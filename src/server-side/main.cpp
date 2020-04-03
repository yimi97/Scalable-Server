#include "server.h"
#include "server.cpp"
#include "../config.h"

using namespace std;
int main(int argc, char **argv) {
    //Check if input is valid
    if (argc != 2) {
        cout << "Usage: bucketNum" << endl;
        exit(EXIT_FAILURE);
    }
    int bucketNum = atoi(argv[1]);

    Server * s = new Server(bucketNum);
    if (PER_CREATE) {
        cout << "=======PER CREATE POLICY========" << endl;
        s->per_run();
    }
    else {
        cout << "=======PRE CREATE POLICY========" << endl;
        s->pre_run();
    }
    return EXIT_SUCCESS;
}