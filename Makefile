CFLAGS=--std=c++11 -pedantic -Wall -Werror -ggdb3
all: server test
server: server-side/main.cpp server-side/server.h server-side/server.cpp
	g++ $(CPPFLAGS) server-side/main.cpp -o server -pthread
test: testing/test.cpp
	g++ $(CPPFLAGS) testing/test.cpp -o test -pthread
clean:
	rm server test
