#include "ring_buffer.h"

void ring_buf_init(RingBuffer *rb)
{
    rb->read = 0;
    rb->write = 0;
}

int ring_buf_is_empty(const RingBuffer *rb)
{
    return rb->read == rb->write;
}

int ring_buf_is_full(const RingBuffer *rb)
{
    return (rb->write + 1) % RING_CAPACITY == rb->read;
}

int ring_buf_push(RingBuffer *rb, char value)
{
    if (ring_buf_is_full(rb))
    {
        return 0;
    }

    rb->data[rb->write] = value;
    rb->write = (rb->write + 1) % RING_CAPACITY;

    return 1;
}

int ring_buf_pop(RingBuffer *rb, char *value)
{
    if (ring_buf_is_empty(rb))
    {
        return 0;
    }

    *value = rb->data[rb->read];
    rb->read = (rb->read + 1) % RING_CAPACITY;

    return 1;
}