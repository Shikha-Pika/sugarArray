#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    size_t capacity;
    size_t count;
    size_t *elements;
} Array;

void array_init(Array *arr)
{
    arr->capacity = 8;
    arr->count = 0;
    arr->elements = (size_t *)malloc(arr->capacity * sizeof(size_t));
}

int array_get(Array *arr, int index)
{
    return arr->elements[index];
}

void array_push(Array *arr, int data)
{
    if (arr->count + 1 > arr->capacity)
    {
        arr->capacity = arr->capacity * 2;
        arr->elements = (size_t *)realloc(arr->elements, arr->capacity * sizeof(size_t));
    }
    arr->elements[arr->count++] = data;
}

int array_pop(Array *arr)
{
    if (arr->count > 0)
    {
        return arr->elements[--arr->count];
    }
    return arr->elements[arr->count];
}

bool array_set(Array *arr, int index, int data)
{
    if (index > arr->count)
        return false;
    arr->elements[index] = data;
    return true;
}

void array_free(Array *arr)
{
    free(arr->elements);
}

