#ifndef CONFIG_H
#define CONFIG_H

// ============= change config here ====================
#define BUCKET_NUM 32  //32, 128, 512, 2048
#define DELAY_SMALL true //true: small delay; false: large delay
#define PER_CREATE true //true: PER CREATE; false: PRE CREATE
#define REQUEST_NUM 10000
#define HOSTNAME "0.0.0.0" //only for server.cpp, NOT test.cpp
#define PORT "12345"  //only for server.cpp, NOT test.cpp
#define POOL_SIZE 500
// =====================================================

#define BUFFER_SIZE 20
#define MYLOG "/var/log/erss/throughput.log"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h> 
#include <stdlib.h> 
#include <vector>
#include <thread>
#include <sys/time.h>
#include <sstream>
#include <mutex>
#include <list>
#include <semaphore.h>
#include <atomic>
#include <fstream>

#endif
