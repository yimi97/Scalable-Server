CFLAGS=--std=c++11 -pedantic -Wall -Werror -ggdb3
test: ../src/config.h
	g++ $(CPPFLAGS) test.cpp -o test -pthread
clean:
	rm test
