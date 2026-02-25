CC=g++
CFLAGS=-std=c++17 -Wall -g


# The source files we use for building custom_tests
ALL_SRC=$(wildcard *.cpp)

# The name of the resulting executable
APP=generate_test_vectors

test:
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(APP)	

clean:
	rm -f $(APP)
