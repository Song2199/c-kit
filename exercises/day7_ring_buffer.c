#include <stdio.h>

#define RING_CAPACITY 5

typedef struct {
    char data[RING_CAPACITY];
    int read;
    int write;
} RingBuffer;

void ring_buf_init(RingBuffer *rb)
{
    rb->write = 0;
    rb->read = 0;
}

int ring_buf_is_empty(const RingBuffer *rb)
{
    return rb -> write == rb->read;
}

int ring_buf_is_full(const RingBuffer *rb)
{
    return (rb->write + 1) % RING_CAPACITY == rb -> read;
}



int ring_buf_push(RingBuffer *rb, char value)
{
    /* 1. 如果缓冲区已满，返回0 */
    if(ring_buf_is_full(rb))
    {
        return 0;
    }

    /* 2. 在write当前指向的位置写入value */
    rb->data[rb->write] = value;
    /* 3. 移动write并通过取模绕回 */
    rb->write = (rb->write + 1) % RING_CAPACITY;
    /* 4. 返回1 */
    return 1;
}
int ring_buf_pop(RingBuffer *rb, char *out)
{
    /* 1. 如果缓冲区为空，返回0 */
    if(ring_buf_is_empty(rb))
    {
        return 0;
    }
    /* 2. 把data[read]中的字符写入out指向的位置 */
    *out = rb->data[rb->read];
    /* 3. 移动read并通过取模绕回 */
    rb->read = (rb->read + 1) % RING_CAPACITY;
    /* 4. 返回1 */
    return 1;
}

int main(void)
{
    RingBuffer rb;
   ring_buf_init(&rb);
    char value = '?';
 
printf("push A=%d\n", ring_buf_push(&rb, 'A'));

printf("after push: read=%d, write=%d, empty=%d, full=%d\n",
       rb.read,
       rb.write,
       ring_buf_is_empty(&rb),
       ring_buf_is_full(&rb));

 int pop_result = ring_buf_pop(&rb,&value) ;   

printf("pop=%d\n", pop_result);

    printf("read=%d, write=%d\n", rb.read, rb.write);
    printf("empty=%d, full=%d\n",
       ring_buf_is_empty(&rb),
       ring_buf_is_full(&rb));
   

printf("after pop: read=%d, value=%c, write=%d, empty=%d, full=%d\n",rb.read,value,rb.write, ring_buf_is_empty(&rb),
       ring_buf_is_full(&rb));

       int result = ring_buf_pop(&rb, &value);
printf("empty pop=%d\n", result);
printf("after empty pop: value=%c, read=%d, write=%d\n",
       value, rb.read, rb.write);
       
    return 0;
}
