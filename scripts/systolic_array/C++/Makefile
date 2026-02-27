CC=g++
CFLAGS=-std=c++17 -Wall -g -Wno-sign-compare

# ===== SoftFloat Paths =====
SOFTFLOAT_ROOT := ../berkeley-softfloat-3
SOFTFLOAT_INC  := $(SOFTFLOAT_ROOT)/source/include
SOFTFLOAT_LIB  := $(SOFTFLOAT_ROOT)/build/Linux-x86_64-GCC/softfloat.a

# The source files we use for building custom_tests
ALL_SRC=$(wildcard *.cpp)

# The name of the resulting executable
APP=gen_test_vectors

test:
	$(CC) $(CFLAGS) -I$(SOFTFLOAT_INC) $(ALL_SRC) $(SOFTFLOAT_LIB) -o $(APP)	
	./$(APP)

clean:
	rm -f $(APP)
