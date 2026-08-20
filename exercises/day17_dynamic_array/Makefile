CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = test_int_vector
OBJS = int_vector.o test_int_vector.o

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

int_vector.o: int_vector.c int_vector.h
	$(CC) $(CFLAGS) -c int_vector.c

test_int_vector.o: test_int_vector.c int_vector.h
	$(CC) $(CFLAGS) -c test_int_vector.c

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)