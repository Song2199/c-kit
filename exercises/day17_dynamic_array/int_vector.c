#include <stdlib.h>
#include "int_vector.h"

int int_vector_init(IntVector *vector,size_t initial_capacity)
{
    if(vector == NULL)
    {
        return 0;
    }
    vector->data = NULL;
    vector->size = 0u;
    vector->capacity = 0u;
    if(initial_capacity == 0u)
    {
        return 0;
    }
    vector->data = malloc(initial_capacity * sizeof(int));
    if(vector->data == NULL)
    {
        return 0;
    }
    vector->capacity = initial_capacity;
    return 1;
}
void int_vector_destroy(IntVector *vector)
{
    if(vector == NULL)
    {
        return;
    }
    free(vector->data);

    vector->data = NULL;
    vector->size = 0u;
    vector->capacity = 0u;
}
int int_vector_push(IntVector *vector,int value)
{
    if(vector == NULL || vector->data == NULL)
    {
        return 0;
    }
    if (vector->size == vector->capacity)
    {
        size_t new_capacity;
        int *new_data;

        new_capacity= vector->capacity *2;
        new_data=realloc(vector->data,new_capacity * sizeof(int));
        if(new_data == NULL)
        {
            return 0;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->data[vector->size] = value;
    vector->size++;

    return 1;
}
int int_vector_get(const IntVector *vector,size_t index,int *out_value)
{
    if (vector == NULL ||
        vector->data == NULL ||
        out_value == NULL)
    {
        return 0;
    }

    if (index >= vector->size)
    {
        return 0;
    }

    *out_value = vector->data[index];

    return 1;
}
int int_vector_set(IntVector *vector,size_t index,int value)
{
    if(vector == NULL || vector->data == NULL)
    {
        return 0;
    }
    if(index>=vector->size)
    {
        return 0;
    }
    vector->data[index]=value;
    return 1;
}
int int_vector_pop(IntVector *vector,int *out_value)
{
    if(vector == NULL || vector->data == NULL || out_value == NULL)
    {
        return 0;
    }
    if(vector->size == 0u)
    {
        return 0;
    }
    *out_value = vector->data[vector->size - 1u];
    vector->size--;
    return 1;
}