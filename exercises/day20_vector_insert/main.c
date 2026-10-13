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
    print_vector(&v);
    
    
    result = int_vector_insert(&v,99,1);
    printf("insert result = %d\n",result);
    print_vector(&v);

    free(v.data);

    return 0;
}


    


