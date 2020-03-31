#include <string>
using namespace std;
class Request {
private:
    int delay;
    int bucketNum;
public:
    Request(string str) {
        int delimiter = str.find(',');
        delay = stoi(str.substr(0, delimiter));
        bucketNum = stoi(str.substr(delimiter + 1));
    }
    int getDelay() { return delay; }
    int getBucketNum() { return bucketNum; }
};
