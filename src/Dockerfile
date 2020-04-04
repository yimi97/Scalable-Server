FROM gcc:9

RUN mkdir -p /code
RUN mkdir -p /var/log/erss
WORKDIR /code
add . /code/

# for one core
ENTRYPOINT ["taskset --cpu-list 0 ./run.sh"]

# for two cores
# ENTRYPOINT ["taskset --cpu-list 0-1 ./run.sh"]

# for four cores
# ENTRYPOINT ["taskset --cpu-list 0-3 ./run.sh"]
