CFLAGS=--std=c++11 -pedantic -Wall -Werror -ggdb3
all: server test
server: server-side/server.h config.h
	g++ $(CPPFLAGS) server-side/main.cpp -o server -pthread
test: config.h
	g++ $(CPPFLAGS) testing/test.cpp -o test -pthread
clean:
	rm server test
