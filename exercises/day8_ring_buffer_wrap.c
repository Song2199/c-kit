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

    int result_a = ring_buf_push(&rb, 'A');
    int result_b = ring_buf_push(&rb, 'B');
    int result_c = ring_buf_push(&rb, 'C');
    int result_d = ring_buf_push(&rb, 'D');

    printf("push A=%d , B=%d , c=%d , d = %d\n", result_a,result_b,result_c, result_d);

    printf("after push : read=%d , write=%d, empty=%d, full=%d\n" ,rb.read,rb.write,
        ring_buf_is_empty(&rb),ring_buf_is_full(&rb));
    int result_e = ring_buf_push(&rb,'E');
    printf("E=%d\n",result_e);
    printf("read=%d , write=%d, empty=%d, full=%d\n",rb.read,rb.write,ring_buf_is_empty(&rb),ring_buf_is_full(&rb));

    char value1;
    char value2;
    int pop_result1 = ring_buf_pop(&rb,&value1) ;
    printf("pop=%d value1=%c\n", pop_result1,value1);
    int pop_result2 = ring_buf_pop(&rb,&value2);  
   printf("pop=%d value2=%c\n", pop_result2,value2);
   printf("read=%d , write=%d, empty=%d, full=%d\n",rb.read,rb.write,ring_buf_is_empty(&rb),ring_buf_is_full(&rb));

    int result_e_again=ring_buf_push(&rb,'E');
    int result_f=ring_buf_push(&rb,'F');
    printf("push E=%d,push F=%d\n",result_e_again,result_f);
    printf("read=%d , write=%d, empty=%d, full=%d\n",rb.read,rb.write,ring_buf_is_empty(&rb),ring_buf_is_full(&rb));
    
    char value3,value4,value5,value6;
    int pop_result3 = ring_buf_pop(&rb,&value3) ;
    int pop_result4 = ring_buf_pop(&rb,&value4) ;
    int pop_result5 = ring_buf_pop(&rb,&value5) ;
    int pop_result6 = ring_buf_pop(&rb,&value6) ;
   printf("pop_result3=%d, pop_result4=%d, pop_result5=%d, pop_result6=%d, "
       "value3=%c, value4=%c, value5=%c, value6=%c\n",
       pop_result3, pop_result4, pop_result5, pop_result6,
       value3, value4, value5, value6);
    printf("read=%d , write=%d, empty=%d, full=%d\n",rb.read,rb.write,ring_buf_is_empty(&rb),ring_buf_is_full(&rb));

    int result = ring_buf_pop(&rb, &value6);
    printf("result = %d,value6 = %c\n",result,value6);
    printf("read=%d , write=%d, empty=%d, full=%d\n",rb.read,rb.write,ring_buf_is_empty(&rb),ring_buf_is_full(&rb));
    return 0;
}