#include <assert.h>
#include <stdio.h>
#include <vector.h>

int main(void)
{
    IntVector v;
    vector_init(&v,4);

    assert(vector_size(&v) == 0);
    assert(vector_capacity(&v) == 4);

    assert(vector_empty(&v) == 1);

    assert(int_vector_insert(&v,0,10) == 1);
    assert(vector_size(&v) == 1);
    assert(vector_capacity(&v) == 4);
    // 继续插入三个元素，让 Vector 装满
    assert(int_vector_insert(&v, 1, 20) == 1);
    assert(int_vector_insert(&v, 2, 30) == 1);
    assert(int_vector_insert(&v, 3, 40) == 1);

// 验证装满后的状态
    assert(vector_size(&v) == 4);
    assert(vector_capacity(&v) == 4);

    // 插入第5个元素，触发扩容
    assert(int_vector_insert(&v, 4, 50) == 1);

    // 验证扩容后的状态
    assert(vector_size(&v) == 5);
    assert(vector_capacity(&v) == 8);

    int expected[]={10,20,30,40,50};

    for(size_t i = 0;i<5;i++)
    {
        int actual = 0;
        assert(vector_get(&v,i,&actual) == 1);
        assert(actual == expected[i]);
    }
    int value = -1;
    assert(vector_get(&v,5,&value) == 0);
    assert(value == -1);

    assert(vector_set(&v,2,99)==1);

    assert(vector_get(&v,2,&value) == 1);
    assert(value == 99);

    assert(vector_set(&v,5,123)==0);

    assert(vector_get(&v,2,&value) == 1);
    assert(value == 99);

    assert(vector_empty(&v) == 0);

    vector_destroy(&v);

    printf("ALL tests passed!\n");

    return 0;
}