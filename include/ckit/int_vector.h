#ifndef INT_VECTORY_H
#define INT_VECTORY_H

#include <stddef.h>

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
}IntVector;

int int_vector_init(IntVector *vector,size_t initial_capacity);
void int_vector_destroy(IntVector *vector);
int int_vector_push(IntVector *vector,int value);
int int_vector_get(const IntVector *vector,size_t index,int *out_value);
int int_vector_set(IntVector *vector,size_t index,int value);
int int_vector_pop(IntVector *vector,int *out_value);

#endif