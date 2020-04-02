#ifndef CONFIG_H
#define CONFIG_H

// ============= change config here ====================
#define BUCKET_NUM 32  //32, 128, 512, 2048
#define DELAY_SMALL true //set false to change to large delay
#define PER_CREATE true //set false to change to PRE_CREATE
#define REQUEST_NUM 100
#define HOSTNAME "127.0.0.1"
#define PORT "12345"
#define POOL_SIZE 500
// =====================================================

#define BUFFER_SIZE 20
#define MYLOG "throughput.log"
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
