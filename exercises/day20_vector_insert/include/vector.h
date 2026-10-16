#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>


typedef struct
{
    int *data;
    size_t size;
    size_t capacity;

} IntVector;


int vector_init(
    IntVector *v,
    size_t capacity
);


int vector_resize(
    IntVector *v,
    size_t new_capacity
);


int int_vector_insert(
    IntVector *v,
    size_t index,
    int value
);


void print_vector(
    IntVector *v
);

void vector_destroy(
    IntVector *v);

int vector_get(
    IntVector *v,
    size_t index,
    int *out
);
int vector_set(
    IntVector *v,
    size_t index,
    int value
);
size_t vector_size(const IntVector *v);

size_t vector_capacity(const IntVector *v);

int vector_empty(const IntVector *v);

#endif