#include <stddef.h>

typedef struct {
    size_t size;
    size_t capacity;
    size_t typesize;
    void *data;
} vector;

vector *vnew(size_t typesize);
void vresize(vector *vec);
void vind(vector *vec, size_t i, void *element);
void vadd(vector *vec, void *element);
void *vget(vector *vec, size_t i);
void vdelu(vector *vec, size_t i);
void vdel(vector *vec, size_t i);
void *vpop(vector *vec);
void *vpopb(vector *vec);
void vfree(vector* vec);

// vector vecinit(size_t size);
// void vecresize(vector* vec);
// void vecadd(vector *vec, void *element);
// void *vecget(vector vec, size_t i);
// void vecdel(vector *vec, size_t i);
// void vecfree(vector *vec);
