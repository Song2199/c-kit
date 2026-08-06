CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = day10_static_library
LIB = libring_buffer.a

all: $(TARGET)

$(TARGET): main.o $(LIB)
	$(CC) main.o $(LIB) -o $(TARGET)

main.o: main.c ring_buffer.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ring_buffer.o: ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -c ring_buffer.c -o ring_buffer.o

$(LIB): ring_buffer.o
	ar rcs $(LIB) ring_buffer.o

clean:
	rm -f *.o $(LIB) $(TARGET)

.PHONY: all clean