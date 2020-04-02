CFLAGS=--std=c++11 -pedantic -Wall -Werror -ggdb3
server: server-side/server.h config.h
	g++ $(CPPFLAGS) server-side/main.cpp -o server -pthread
clean:
	rm server
