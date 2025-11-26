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
    GENTYPE *data;
}
GEN_TYPE;

static inline GEN_TYPE
GEN_NAME(create)()
{
    GEN_TYPE v;
    v.capacity = VECTOR_BASE_CAPACITY;
    v.size = 0;
    v.data = malloc(sizeof(GEN_TYPE) * VECTOR_BASE_CAPACITY);
    return v;
}

static inline void
GEN_NAME(realloc)(GEN_TYPE *v)
{
    v->capacity *= VECTOR_GROWTH_RATE;
    v->data = realloc(v->data, v->capacity * sizeof(GEN_TYPE));
}

static inline void
GEN_NAME(push)(GEN_TYPE *v, GENTYPE e)
{
    if (v->size == v->capacity)
    {
      GEN_NAME(realloc)(v);
    }

    v->data[v->size] = e;
    v->size++;
}

static inline GENTYPE
GEN_NAME(pop)(GEN_TYPE *v)
{
    if (v->size == 0)
    {
      printf("Can't call vector_pop() on an empty vector.\n");
      exit(1);
    }

    v->size--;
    return v->data[v->size];
}

static inline GEN_TYPE
GEN_NAME(clone)(GEN_TYPE *v)
{
    GEN_TYPE o;
    o.capacity = v->capacity;
    o.size = v->size;
    o.data = malloc(sizeof(GENTYPE) * v->capacity);
    memcpy(o.data, v->data, v->size * sizeof(GENTYPE));
    return o;
}

static inline void
GEN_NAME(free)(GEN_TYPE *v)
{
    free(v->data);
}


#undef VECTOR_BASE_CAPACITY
#undef VECTOR_GROWTH_RATE

#include "gen_end.h"
