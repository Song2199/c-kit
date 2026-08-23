#include <assert.h>
#include <stdio.h>

#include "int_vector.h"

static void test_initialization(void)
{
    IntVector vector;
    int result;
    result = int_vector_init(&vector,3u);

    assert(result==1);
    assert(vector.data != NULL);
    assert(vector.size == 0u);
    assert(vector.capacity == 3u);

    int_vector_destroy(&vector);
    assert(vector.data == NULL);
    assert(vector.size == 0u);
    assert(vector.capacity == 0u);
    printf("Initialization test passed.\n");

}
static void test_push_without_growth(void)
{
    IntVector vector;
    int result;

    result = int_vector_init(&vector, 3u);
    assert(result == 1);

    result = int_vector_push(&vector, 10);
    assert(result == 1);
    assert(vector.data[0] == 10);
    assert(vector.size == 1u);
    assert(vector.capacity == 3u);

    result = int_vector_push(&vector, 20);
    assert(result == 1);
    assert(vector.data[1] == 20);
    assert(vector.size == 2u);
    assert(vector.capacity == 3u);

    int_vector_destroy(&vector);

    printf("Push without growth test passed.\n");
}
static void test_push_with_growth(void)
{
    IntVector vector;
    int result;

    result = int_vector_init(&vector, 2u);
    assert(result == 1);

    assert(int_vector_push(&vector, 10) == 1);
    assert(int_vector_push(&vector, 20) == 1);

    assert(vector.size == 2u);
    assert(vector.capacity == 2u);

    result = int_vector_push(&vector, 30);

    assert(result == 1);
    assert(vector.size == 3u);
    assert(vector.capacity == 4u);

    assert(vector.data[0] == 10);
    assert(vector.data[1] == 20);
    assert(vector.data[2] == 30);

    int_vector_destroy(&vector);

    printf("Push with growth test passed.\n");
}
static void test_get(void)
{
    IntVector vector;
    int result;
    int value;

    assert(int_vector_init(&vector, 2u) == 1);
    assert(int_vector_push(&vector, 10) == 1);
    assert(int_vector_push(&vector, 20) == 1);
    assert(int_vector_push(&vector, 30) == 1);

    value = -1;
    result = int_vector_get(&vector, 1u, &value);

    assert(result == 1);
    assert(value == 20);

    value = -1;
    result = int_vector_get(&vector, 3u, &value);

    assert(result == 0);
    assert(value == -1);

    int_vector_destroy(&vector);

    printf("Get test passed.\n");
}
static void test_invalid_inputs(void)
{
    IntVector vector;
    int value;

    /* 没有提供结构体对象 */
    assert(int_vector_init(NULL, 3u) == 0);
    assert(int_vector_push(NULL, 10) == 0);

    value = -1;
    assert(int_vector_get(NULL, 0u, &value) == 0);
    assert(value == -1);

    /* 初始容量为 0 */
    assert(int_vector_init(&vector, 0u) == 0);
    assert(vector.data == NULL);
    assert(vector.size == 0u);
    assert(vector.capacity == 0u);

    /* 正常初始化后，输出指针不能为 NULL */
    assert(int_vector_init(&vector, 1u) == 1);
    assert(int_vector_push(&vector, 10) == 1);
    assert(int_vector_get(&vector, 0u, NULL) == 0);

    int_vector_destroy(&vector);

    /* 销毁后没有数组空间，不能继续 push */
    assert(int_vector_push(&vector, 20) == 0);

    /* destroy 接收 NULL 时应安全返回 */
    int_vector_destroy(NULL);

    printf("Invalid input test passed.\n");
}
static void test_set(void)
{
    IntVector vector;
    int result;

    assert(int_vector_init(&vector, 4u) == 1);
    assert(int_vector_push(&vector, 10) == 1);
    assert(int_vector_push(&vector, 20) == 1);
    assert(int_vector_push(&vector, 30) == 1);

    result = int_vector_set(&vector, 1u, 99);

    assert(result == 1);
    assert(vector.data[0] == 10);
    assert(vector.data[1] == 99);
    assert(vector.data[2] == 30);
    assert(vector.size == 3u);
    assert(vector.capacity == 4u);
        result = int_vector_set(&vector, 3u, 77);

    assert(result == 0);
    assert(vector.data[0] == 10);
    assert(vector.data[1] == 99);
    assert(vector.data[2] == 30);
    assert(vector.size == 3u);
    assert(vector.capacity == 4u);

    int_vector_destroy(&vector);

    printf("Set test passed.\n");
}
static void test_pop(void)
{
    IntVector vector;
    int result;
    int value;

    assert(int_vector_init(&vector, 4u) == 1);
    assert(int_vector_push(&vector, 10) == 1);
    assert(int_vector_push(&vector, 20) == 1);
    assert(int_vector_push(&vector, 30) == 1);

    /* 输出指针为 NULL，操作失败且 size 不变 */
    assert(int_vector_pop(&vector, NULL) == 0);
    assert(vector.size == 3u);

    value = -1;
    result = int_vector_pop(&vector, &value);

    assert(result == 1);
    assert(value == 30);
    assert(vector.size == 2u);
    assert(vector.capacity == 4u);
    assert(vector.data[0] == 10);
    assert(vector.data[1] == 20);

    assert(int_vector_pop(&vector, &value) == 1);
    assert(value == 20);
    assert(vector.size == 1u);

    assert(int_vector_pop(&vector, &value) == 1);
    assert(value == 10);
    assert(vector.size == 0u);
    assert(vector.capacity == 4u);

    /* 空数组 pop 失败，不能修改输出变量 */
    value = -1;
    result = int_vector_pop(&vector, &value);

    assert(result == 0);
    assert(value == -1);
    assert(vector.size == 0u);
    assert(vector.capacity == 4u);

    assert(int_vector_pop(NULL, &value) == 0);

    int_vector_destroy(&vector);

    printf("Pop test passed.\n");
}

int main(void)
{
   test_initialization();
   test_push_without_growth();
   test_push_with_growth();
   test_get();
   test_invalid_inputs();
   test_set();
   test_pop();
   return 0;
}