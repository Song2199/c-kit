CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = test_debounce_button
OBJS = debounce_button.o test_debounce_button.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

debounce_button.o: debounce_button.c debounce_button.h
	$(CC) $(CFLAGS) -c debounce_button.c

test_debounce_button.o: test_debounce_button.c debounce_button.h
	$(CC) $(CFLAGS) -c test_debounce_button.c

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all test clean