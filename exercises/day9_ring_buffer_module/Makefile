CC = gcc
CFLAGS = -Wall -Wextra -std=c11

day9_ring_buffer_module: main.o ring_buffer.o
	$(CC) main.o ring_buffer.o -o day9_ring_buffer_module

main.o: main.c ring_buffer.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ring_buffer.o: ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -c ring_buffer.c -o ring_buffer.o

.PHONY: clean

clean:
	rm -f main.o ring_buffer.o day9_ring_buffer_module