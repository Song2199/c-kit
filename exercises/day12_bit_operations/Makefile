CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11

TARGET = test_bit_operations
OBJS = bit_operations.o test_bit_operations.o

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

bit_operations.o: bit_operations.c bit_operations.h
	$(CC) $(CFLAGS) -c bit_operations.c -o bit_operations.o

test_bit_operations.o: test_bit_operations.c bit_operations.h
	$(CC) $(CFLAGS) -c test_bit_operations.c -o test_bit_operations.o

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)