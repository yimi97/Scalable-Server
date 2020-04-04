# ERSS HW4
Jingyi Xie (jx95), Yi Mi (ym154)

## Run the Server
* In the project root directory, run `sudo docker-compose up`

## Run the Testing Environment
* In the project root directory, `cd testing`
* In `testing` directory, `./clienttest.sh`

## Change the Configurations
* To change the **server address to connect** (for client), change the `SERVER_ADDR` in `test.cpp`
* To change the **bucket number**, change the `BUCKET_NUM` in `config.h` **AND** the command line argument of `./server` in `run.sh`
* To change the **delay count** (small/large), change the `DELAY_SMALL` in `config.h`
* To change the **create policy** (per/pre), change the `PER_CREATE` in `config.h`
* To change the **thread pool size** in pre-create policy, change the `POOL_SIZE` in `config.h`
* To change the **number of cores**, change the `taskset` in `Dockerfile`

## Throughput  Log
* `throughput.log` can be found in the `log` directory. The log file prints the throughput every 30 seconds and is overwritten every time run the docker. Please notice that you may need to wait a few seconds for the log to generate.

