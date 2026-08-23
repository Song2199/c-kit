CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = test_int_vector
OBJS = int_vector.o test_int_vector.o

SANITIZE_TARGET = test_int_vector_sanitize
SANITIZE_FLAGS = -g -fsanitize=address,undefined -fno-omit-frame-pointer

.PHONY: all test sanitize clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

int_vector.o: int_vector.c int_vector.h
	$(CC) $(CFLAGS) -c int_vector.c

test_int_vector.o: test_int_vector.c int_vector.h
	$(CC) $(CFLAGS) -c test_int_vector.c

test: $(TARGET)
	./$(TARGET)

sanitize:
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) \
		int_vector.c test_int_vector.c \
		-o $(SANITIZE_TARGET)
	./$(SANITIZE_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(SANITIZE_TARGET)