CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
TARGET = test_gpio
OBJS = gpio.o test_gpio.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

gpio.o: gpio.c gpio.h
	$(CC) $(CFLAGS) -c gpio.c -o gpio.o

test_gpio.o: test_gpio.c gpio.h
	$(CC) $(CFLAGS) -c test_gpio.c -o test_gpio.o

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean