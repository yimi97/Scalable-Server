#include "server.h"
#include "server.cpp"

using namespace std;
int main(int argc, char **argv) {
    if (argc != 3 || (strcmp(argv[2], "PER") && strcmp(argv[2], "PRE"))) {
        cout << "Usage: bucketNum, MODE(PER/PRE)" << endl;
        exit(EXIT_FAILURE);
    }
    int bucketNum = atoi(argv[1]);

    Server * s = new Server(bucketNum);
    if (strcmp(argv[2], "PER") == 0) {
        cout << "=======PER CREATE POLICY========" << endl;
        s->per_run();
    }
    else {
        cout << "=======PRE CREATE POLICY========" << endl;
        s->pre_run();
    }
    return EXIT_SUCCESS;
}