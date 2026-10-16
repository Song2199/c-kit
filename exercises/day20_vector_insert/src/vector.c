#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void print_vector(IntVector *v)
{
    for(size_t i = 0;i< v->size; i++)
    {
        printf("%d", v->data[i]);
    }
    printf("\n");
}

int vector_init(IntVector *v, size_t capacity)
{
    if(v== NULL)
    {
        return 0;
    }
    int *new_data = malloc(capacity* sizeof(int));
    if(new_data == NULL)
    {
        return 0;
    }
    v->data = new_data;
    v->size = 0;
    v->capacity = capacity;
    return 1;
}

int vector_resize(IntVector *v,size_t new_capacity)
{
    if(v == NULL)
    {
        return 0;
    }
    int *new_data = malloc(new_capacity * sizeof(int));
    if(new_data == NULL)
    {
        return 0;
    }
    for(size_t i=0;i < v->size;i++)
    {
        new_data[i] = v->data[i];
    }
    int *old_data = v->data;
    v->data = new_data;
    v->capacity = new_capacity;
    free(old_data);
    return 1;
}

int int_vector_insert(IntVector *v,size_t index,int value)
{
    if (v == NULL)
{
    return 0;
}

if (index > v->size)
{
    return 0;
}

if(v->size == v->capacity)
{
    size_t new_capacity;
    if(v->capacity == 0)
    {
        new_capacity = 4;
    }
    else
    {
        new_capacity = v->capacity * 2;
    }
    if(!vector_resize(v,new_capacity))
    {
        return 0;
    }
}
    for(size_t i = v->size; i > index; i--)
    {
        v->data[i] = v->data[i-1];
    }
    v->data[index] = value;
    v->size++;
    return 1;

return 1;

}
void vector_destroy(IntVector *v)
{
    if(v == NULL)
    {
        return;
    }
    free(v->data);

    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}
int vector_get(
    IntVector *v,
    size_t index,
    int *out
)
{
    if(v == NULL || out == NULL)
    {
        return 0;
    }
    if(index >= v->size)
    {
        return 0;
    }
    *out = v->data[index];
    return 1 ;
}

int vector_set(
    IntVector *v,
    size_t index,
    int value
)
{
    if(v == NULL)
    {
        return 0;
    }

    if(index >= v->size)
    {
        return 0;
    }

    v->data[index] = value;

    return 1;
}
size_t vector_size(const IntVector *v)
{
    if(v == NULL)
    {
        return 0;
    }
    return v->size;
}
size_t vector_capacity(const IntVector *v)
{
    if(v == NULL)
    {
        return 0;
    }
    return v->capacity;
}
int vector_empty(const IntVector *v)
{
    if(v == NULL)
    {
        return 0;
    }
    return v->size == 0;
}