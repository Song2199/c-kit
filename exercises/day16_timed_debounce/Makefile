CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = test_timed_debounce_button
OBJS = timed_debounce_button.o test_timed_debounce_button.o

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

timed_debounce_button.o: timed_debounce_button.c timed_debounce_button.h
	$(CC) $(CFLAGS) -c timed_debounce_button.c

test_timed_debounce_button.o: test_timed_debounce_button.c timed_debounce_button.h
	$(CC) $(CFLAGS) -c test_timed_debounce_button.c

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)