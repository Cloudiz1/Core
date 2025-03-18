#if defined (GENTYPE)

#ifndef GENTYPENAME
#define GENTYPENAME GENTYPE
#endif // GENTYPENAME

#define _CONCAT_(a, b) a ## b
#define _CONCAT(a, b) _CONCAT_(a, b)
#define _PREFIX Vector
#define _NAME(qualifier) _CONCAT(qualifier, _CONCAT(_, GENTYPENAME))
#define _TYPE _NAME(Vector)

#define VECTOR_BASE_CAPACITY 5

typedef struct {
    size_t size;
    size_t capacity;
    GENTYPE *data;
} _TYPE;

_TYPE *_NAME(vnew)()
{
    _TYPE *vec = malloc(sizeof (_TYPE));
    if (vec == NULL) {
        return NULL;
    }

    vec->size = 0;
    vec->capacity = VECTOR_BASE_CAPACITY;
    vec->data = malloc(vec->capacity * sizeof (vec->data));
    if (vec->data == NULL) {
        return NULL;
    }

    return vec;
}

void _NAME(vadd)(_TYPE *vec, GENTYPE elem) {
    if (vec->size == vec->capacity) {
        // vresize(vec); // Not implemented.
    }

    // vind(vec, vec->size, element); // Not implemented.

    vec->size += sizeof (elem); // BS
    vec->size++;
}

#undef _CONCAT_
#undef _CONCAT
#undef _NAME
#undef _TYPE

#endif // defined (GENTYPE)

#undef GENTYPE
#undef GENTYPENAME

