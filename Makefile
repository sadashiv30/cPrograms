CXX=gcc
#CXX=clang++-3.8
RM=rm -f
CFLAGS= -o0 -g
LDFLAGS=

SRCS := $(wildcard *.c)
#OBJS := $(patsubst %.c,%.o,$(SRCS))
TARGETS = $(patsubst %.c,%,$(SRCS))

all: $(TARGETS)

reverseLinekedList: reverseLinekedList.c
adjacent_digits_product: adjacent_digits_product.c
deviceID: deviceID.c
matrixRow0: matrixRow0.c
packedPIN: packedPIN.c
stringTests: stringTests.c
compressString: compressString.c
$(TARGETS):
	$(CXX) $(CFLAGS) -o $@  $^
	@mv $@ bin/
	
find_next_prime: find_next_prime.c
	$(CXX) $(CFLAGS) -o $@  $^ -lm
	@mv $@ bin/

format:
	@find . -type f -name '*.c' | xargs clang-format -i
	@find . -type f -name '*.h' | xargs clang-format -i
	
clean:
	rm -f $(OBJS) $(TARGETS) 
	rm -rf bin/*
PHONY: clean all format