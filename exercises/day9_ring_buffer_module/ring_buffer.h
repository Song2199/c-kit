#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define RING_CAPACITY 5

typedef struct{
    char data[RING_CAPACITY];
    int read;
    int write;

}RingBuffer;

void ring_buf_init(RingBuffer *rb);
int ring_buf_is_empty(const RingBuffer *rb);
int ring_buf_is_full(const RingBuffer *rb);
int ring_buf_push(RingBuffer *rb, char value);
int ring_buf_pop(RingBuffer *rb, char *out);

#endif