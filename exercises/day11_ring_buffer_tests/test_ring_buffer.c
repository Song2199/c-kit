#include <assert.h>
#include <stdio.h>

#include "ring_buffer.h"

static void test_init_is_empty(void)
{
    /* 准备 */
    RingBuffer rb;

    /* 执行 */
    ring_buf_init(&rb);

    /* 验证 */
    assert(ring_buf_is_empty(&rb) == 1);
    assert(ring_buf_is_full(&rb) == 0);
    assert(rb.read == 0);
    assert(rb.write == 0);
}

static void test_push_and_pop(void)
{
    RingBuffer rb;
    char value='X';
    ring_buf_init(&rb);
    assert(ring_buf_push(&rb, 'A') == 1);
    assert(ring_buf_is_empty(&rb) == 0);

    assert(ring_buf_pop(&rb, &value) == 1);
   assert(value == 'A');
    assert(ring_buf_is_empty(&rb) == 1);
}
int main(void)
{
     test_init_is_empty();
    printf("test_init_is_empty passed\n");

    test_push_and_pop();
    printf("test_push_and_pop passed\n");

    return 0;
}