# ERSS HW4
Jingyi Xie (jx95), Yi Mi (ym154)

## Run the server
* In the project root directory, run `sudo docker-compose up`

## Run the testing environment
* In the project root directory, `cd testing`
* In `testing` directory, `./clienttest.sh`

## Change the configurations
* To change the **server address to connect** (for client), change the `SERVER_ADDR` in `test.cpp`
* To change the **bucket number**, change the `BUCKET_NUM` in `config.h` **AND** the command line argument of `./server` in `run.sh`
* To change the **delay count** (small/large), change the `DELAY_SMALL` in `config.h`
* To change the **create policy** (per/pre), change the `PER_CREATE` in `config.h`
* To change the **thread pool size** in pre-create policy, change the `POOL_SIZE` in `config.h`
* To change the **number of cores**, change the `taskset` in `Dockerfile`
