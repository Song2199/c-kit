#include <stdio.h>
#include "ring_buffer.h"

int main(void)
{
    RingBuffer rb;
    char value;

    ring_buf_init(&rb);

    printf("empty=%d\n", ring_buf_is_empty(&rb));

    printf("push A=%d\n", ring_buf_push(&rb, 'A'));
    printf("push B=%d\n", ring_buf_push(&rb, 'B'));
    printf("push C=%d\n", ring_buf_push(&rb, 'C'));
    printf("push D=%d\n", ring_buf_push(&rb, 'D'));
    printf("push E=%d\n", ring_buf_push(&rb, 'E'));

    printf("full=%d\n", ring_buf_is_full(&rb));

    while (ring_buf_pop(&rb, &value))
    {
        printf("pop=%c\n", value);
    }

    printf("empty=%d\n", ring_buf_is_empty(&rb));

    return 0;
}