#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/vector.h"

#define VECTOR_BASE_CAPACITY 5

vector* vnew(size_t typesize) {
    vector *vec = malloc(sizeof(vector));
    if (vec == NULL)
        return NULL;
    
    vec->size = 0;
    vec->typesize = typesize;
    vec->capacity = VECTOR_BASE_CAPACITY;
    vec->data = malloc(sizeof(vector) + vec->capacity * typesize);
    if (vec->data == NULL)
        return NULL;

    return vec;
}

void vresize(vector *vec) {
    vec->data = realloc(vec->data, vec->capacity * 2);
    vec->capacity *= 2;
}

/*
i must be defined such that i <= vec->size
*/
void vind(vector *vec, size_t i, void *element) {
    if (i < vec->capacity && i > 0)
        memcpy((void*)((char*)vec->data + i * vec->typesize), element, vec->typesize);
}

/*
resize if needed
calls vind() on last element
*/
void vadd(vector *vec, void *element) {
    if (vec->size == vec->capacity)
        vresize(vec);

    vind(vec, vec->size, element);
    vec->size++;
}

// can i make this return a void pointer to a typecasted pointer which points to the struct?
// or maybe just make the data a typecasted pointer somehow?
// like get the data ptr, type cast, and return a pointer to that pointer?
// that way you dont have to type cast when youre calling, you just have to dereference.
void *vget(vector *vec, size_t i) {
    if (i >= vec->size)
        return NULL;

    return (void*)((char *)vec->data + (i * vec->typesize));
}

/*
unordered vector delete: O(1)

swaps vec[i] with vec[vec->size - 1]
shrinks vec->size to effectively delete it
*/
void vdelu(vector *vec, size_t i) {
    memcpy((char *)vec->data + (i * vec->typesize), (char *)vec->data + ((vec->size - 1) * vec->typesize), vec->typesize);
    vec->size--;
}

/*
vector delete: O(n)

shifts vec[i + 1]: vec[vec->size - 1] onto vec[i], which overwrites vec[i] and moves everything else down one
shrinks vec->size to effectively delete it 
*/
void vdel(vector *vec, size_t i) {
   memcpy((char *)vec->data + (i * vec->typesize), (char *)vec->data + ((i+1) * vec->typesize), (vec->size - 1 - i) * vec->typesize);
   vec->size--;
}

/*
gets first element and remove
*/
//TODO no worky :(
void *vpop(vector *vec) {
    void *element = vget(vec, 0);
    printf("%i", *(int*)element);
    vdel(vec, 0); // something is getting messed up because its a pointer. printing before deleting returns different numbers than prining after deleting
    return element;
}

/*
gets last element and remove
*/
void *vpopb(vector *vec) {
    void *element = vget(vec, vec->size - 1);
    vdelu(vec, vec->size - 1);
    return element;
}

void vfree(vector *vec) {
    free(vec->data);
    free(vec);
}