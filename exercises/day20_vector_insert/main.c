#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
int main(void)
{
    IntVector v;
    int result= vector_init(&v,4);
    printf("result=%d\n",result);
    v.data[0]=10;
    v.data[1]=20;
    v.data[2]=30;
    v.data[3]=40;
    v.size = 4;
    

    int value;
int get_result = vector_get(&v,1,&value);

printf("get result = %d\n",get_result);
printf("value = %d\n",value);

get_result = vector_get(&v,99,&value);
printf("out of range result = %d\n", get_result); 

int set_result = vector_set(&v,1,99);
printf("set result=%d\n", set_result);
print_vector(&v);

set_result = vector_set(&v,99,100);
printf("invalid set result=%d\n", set_result);
print_vector(&v);

    vector_destroy(&v);

printf("after destory:\n");
printf("data=%p\n",v.data);
printf("size=%zu\n",v.size);
printf("capacity=%zu\n",v.capacity);


    result = int_vector_insert(&v,99,1);
    printf("insert result = %d\n",result);
    print_vector(&v);

    free(v.data);

    return 0;
}


    


