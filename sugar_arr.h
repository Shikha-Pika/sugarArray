#ifndef sugar_arr_h
#define sugar_arr_h

#define DECLARE_WRAPPER(type, name)                     \
    typedef struct                                      \
    {                                                   \
        size_t capacity;                                \
        size_t count;                                   \
        type *elements;                                 \
    } name;                                             \
                                                        \
    void array_init(name *arr);                         \
    type array_get(name *arr, size_t index);            \
    void name_push(name *arr, type data);               \
    bool array_set(name *arr, size_t index, type data); \
    void array_free(name *arr);                         \
    type array_pop(name *arr)

#define DEFINE_ARRAY(type, name)                                                          \
    void array_init(name *arr)                                                            \
    {                                                                                     \
        arr->capacity = 8;                                                                \
        arr->count = 0;                                                                   \
        arr->elements = (type *)malloc(arr->capacity * sizeof(type));                     \
    }                                                                                     \
                                                                                          \
    type array_get(name *arr, size_t index)                                               \
    {                                                                                     \
        return arr->elements[index];                                                      \
    }                                                                                     \
                                                                                          \
    void array_push(name *arr, type data)                                                 \
    {                                                                                     \
        if (arr->count + 1 > arr->capacity)                                               \
        {                                                                                 \
            arr->capacity = arr->capacity * 2;                                            \
            arr->elements = (type *)realloc(arr->elements, arr->capacity * sizeof(type)); \
        }                                                                                 \
        arr->elements[arr->count++] = data;                                               \
    }                                                                                     \
                                                                                          \
    bool array_set(name *arr, size_t index, type data)                                    \
    {                                                                                     \
        if (index > arr->count)                                                           \
            return false;                                                                 \
        arr->elements[index] = data;                                                      \
        return true;                                                                      \
    }                                                                                     \
                                                                                          \
    void array_free(name *arr)                                                            \
    {                                                                                     \
        free(arr->elements);                                                              \
        arr->count = 0;                                                                   \
        arr->capacity = 0;                                                                \
    }                                                                                     \
                                                                                          \
    type array_pop(name *arr)                                                             \
    {                                                                                     \
        if (arr->count > 0)                                                               \
        {                                                                                 \
            return arr->elements[--arr->count];                                           \
        }                                                                                 \
        return arr->elements[arr->count];                                                 \
    }

#endif