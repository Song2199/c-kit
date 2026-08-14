CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
TARGET = test_button
OBJS = button.o test_button.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

button.o: button.c button.h
	$(CC) $(CFLAGS) -c button.c -o button.o

test_button.o: test_button.c button.h
	$(CC) $(CFLAGS) -c test_button.c -o test_button.o

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean