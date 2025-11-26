#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GEN_PREFIX Vector

#include "gen_start.h"

#define VECTOR_BASE_CAPACITY 8
#define VECTOR_GROWTH_RATE 2

typedef struct
{
    size_t size;
    size_t capacity;
    GEN_TYPE *data;
}
GEN_DATA;

static inline GEN_DATA
GEN_NAME(Create)()
{
    GEN_DATA v;
    v.capacity = VECTOR_BASE_CAPACITY;
    v.size = 0;
    v.data = malloc(sizeof(GEN_DATA) * VECTOR_BASE_CAPACITY);
    return v;
}

static inline void
GEN_NAME(Realloc)(GEN_DATA *v)
{
    v->capacity *= VECTOR_GROWTH_RATE;
    v->data = realloc(v->data, v->capacity * sizeof(GEN_DATA));
}

static inline void
GEN_NAME(Push)(GEN_DATA *v, GEN_TYPE e)
{
    if (v->size == v->capacity)
    {
      GEN_NAME(Realloc)(v);
    }

    v->data[v->size] = e;
    v->size += 1;
}

static inline GEN_TYPE
GEN_NAME(Pop)(GEN_DATA *v)
{
    if (v->size == 0)
    {
      fprintf(stderr, "Can't call vector_pop() on an empty vector.\n");
    }

    v->size -= 1;
    return v->data[v->size];
}

static inline GEN_DATA
GEN_NAME(Clone)(GEN_DATA *v)
{
    GEN_DATA o;
    o.capacity = v->capacity;
    o.size = v->size;
    o.data = malloc(sizeof(GEN_TYPE) * v->capacity);
    memcpy(o.data, v->data, v->size * sizeof(GEN_TYPE));
    return o;
}

static inline void
GEN_NAME(Free)(GEN_DATA *v)
{
    free(v->data);
}

#undef VECTOR_BASE_CAPACITY
#undef VECTOR_GROWTH_RATE

#include "gen_end.h"
