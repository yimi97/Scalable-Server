#!/bin/bash
make clean
make
touch /var/log/erss/throughput.log
rm /var/log/erss/throughput.log
./server 32