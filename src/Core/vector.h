#ifndef VECTOR_H
#define VECTOR_H

#ifndef VECTOR_BASE_CAPACITY
#define VECTOR_BASE_CAPACITY 8
#endif

#define VECTOR_GROWTH_RATE 2

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NO_ARENA_VECTOR_IMPLEMENTATION
#include "arena.h"

#define ARENA_VECTOR_IMPLEMENTATION(type, alias)                               \
  static inline vector_##alias vector_arena_create_##alias(Arena *a) {         \
    vector_##alias v;                                                          \
    v.capacity = VECTOR_BASE_CAPACITY;                                         \
    v.size = 0;                                                                \
    v.data = arena_alloc(a, VECTOR_BASE_CAPACITY * sizeof(type));              \
    return v;                                                                  \
  }                                                                            \
                                                                               \
  static inline void vector_arena_realloc_##alias(Arena *a,                    \
                                                  vector_##alias *v) {         \
    v->capacity *= VECTOR_GROWTH_RATE;                                         \
    type *tmp = v->data;                                                       \
    v->data = arena_alloc(a, v->capacity * sizeof(type));                      \
    memcpy(v->data, tmp, v->size * sizeof(type));                              \
  }                                                                            \
                                                                               \
  static inline void vector_arena_push_##alias(Arena *a, vector_##alias *v,    \
                                               type e) {                       \
    if (v->size == v->capacity) {                                              \
      vector_arena_realloc_##alias(a, v);                                      \
    }                                                                          \
                                                                               \
    v->data[v->size] = e;                                                      \
    v->size++;                                                                 \
  }

#else
#define ARENA_VECTOR_IMPLEMENTATION(type, alias)
#endif

#define DEFINE_VECTOR(type, alias)                                             \
  typedef struct {                                                             \
    type *data;                                                                \
    size_t capacity;                                                           \
    size_t size;                                                               \
  } vector_##alias;                                                            \
                                                                               \
  ARENA_VECTOR_IMPLEMENTATION(type, alias)                                     \
                                                                               \
  static inline vector_##alias vector_create_##alias() {                       \
    vector_##alias v;                                                          \
    v.capacity = VECTOR_BASE_CAPACITY;                                         \
    v.size = 0;                                                                \
    v.data = malloc(sizeof(type) * VECTOR_BASE_CAPACITY);                      \
    return v;                                                                  \
  }                                                                            \
                                                                               \
  static inline void vector_realloc_##alias(vector_##alias *v) {               \
    v->capacity *= VECTOR_GROWTH_RATE;                                         \
    v->data = realloc(v->data, v->capacity * sizeof(type));                    \
  }                                                                            \
                                                                               \
  static inline void vector_push_##alias(vector_##alias *v, type e) {          \
    if (v->size == v->capacity) {                                              \
      vector_realloc_##alias(v);                                               \
    }                                                                          \
                                                                               \
    v->data[v->size] = e;                                                      \
    v->size++;                                                                 \
  }                                                                            \
                                                                               \
  static inline type vector_pop_##alias(vector_##alias *v) {                   \
    if (v->size == 0) {                                                        \
      printf("Can't call vector_pop() on an empty vector.\n");                 \
      exit(1);                                                                 \
    }                                                                          \
                                                                               \
    v->size--;                                                                 \
    return v->data[v->size];                                                   \
  }                                                                            \
                                                                               \
  static inline vector_##alias vector_clone_##alias(vector_##alias *v) {       \
    vector_##alias o;                                                          \
    o.capacity = v->capacity;                                                  \
    o.size = v->size;                                                          \
    o.data = malloc(sizeof(type) * v->capacity);                               \
    memcpy(o.data, v->data, v->size * sizeof(type));                           \
    return o;                                                                  \
  }                                                                            \
                                                                               \
  static inline void vector_free_##alias(vector_##alias *v) { free(v->data); }
#endif

#ifndef NO_VECTOR_DEFAULTS

DEFINE_VECTOR(int, int)
DEFINE_VECTOR(float, float)
DEFINE_VECTOR(double, double)
DEFINE_VECTOR(char, char)
DEFINE_VECTOR(char *, str)
static inline void vector_print_int(vector_int *v) {
  printf("[");
  for (int i = 0; i < v->size; i++) {
    printf("%i", v->data[i]);
    if (i != v->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

static inline void vector_print_float(vector_float *v) {
  printf("[");
  for (int i = 0; i < v->size; i++) {
    printf("%f", v->data[i]);
    if (i != v->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

static inline void vector_print_double(vector_double *v) {
  printf("[");
  for (int i = 0; i < v->size; i++) {
    printf("%f", v->data[i]);
    if (i != v->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

static inline void vector_print_char(vector_char *v) {
  printf("[");
  for (int i = 0; i < v->size; i++) {
    printf("%c", v->data[i]);
    if (i != v->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

static inline void vector_print_str(vector_str *v) {
  printf("[");
  for (int i = 0; i < v->size; i++) {
    printf("%s", v->data[i]);
    if (i != v->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
#endif
