#include <stdio.h>
#include "ring_buffer.h"

int main(void)
{
    RingBuffer rb;
    char value;

    ring_buf_init(&rb);

    ring_buf_push(&rb, 'A');
    ring_buf_push(&rb, 'B');

    while (ring_buf_pop(&rb, &value))
    {
        printf("%c\n", value);
    }

    return 0;
}