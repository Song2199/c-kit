CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11

.PHONY: test clean

test: test_ring_buffer
	./test_ring_buffer

test_ring_buffer: test_ring_buffer.o libringbuffer.a
	$(CC) test_ring_buffer.o -L. -lringbuffer -o test_ring_buffer

test_ring_buffer.o: test_ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -c test_ring_buffer.c -o test_ring_buffer.o

libringbuffer.a: ring_buffer.o
	ar rcs libringbuffer.a ring_buffer.o

ring_buffer.o: ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -c ring_buffer.c -o ring_buffer.o

clean:
	rm -f ring_buffer.o test_ring_buffer.o libringbuffer.a test_ring_buffer