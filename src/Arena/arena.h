#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef ARENA_MINIMUM_MEMORY
#define ARENA_MINIMUM_MEMORY (8 * 1024)
#endif

typedef struct Arena_t {
  size_t capacity;
  size_t allocated;
  struct Arena_t *next;
  char *data;
} Arena;

static inline Arena arena_create() {
  Arena a;
  a.next = NULL;
  a.data = (char *)malloc(ARENA_MINIMUM_MEMORY);
  a.allocated = 0;
  a.capacity = ARENA_MINIMUM_MEMORY;
  return a;
}

static inline void *arena_alloc(Arena *a, size_t n) {
  Arena *curr_block = a;
  while (curr_block->allocated + n > curr_block->capacity) {
    if (curr_block->next == NULL) {
      Arena *new_block = (Arena *)malloc(sizeof(Arena));
      new_block->next = NULL;

      size_t size = ARENA_MINIMUM_MEMORY;
      while (n > size) {
        size *= 2;
      }

      new_block->data = (char *)malloc(size);
      new_block->capacity = size;
      new_block->allocated = 0;

      curr_block = new_block;
      a->next = curr_block;
    } else {
      curr_block = curr_block->next;
    }
  }

  void *out = curr_block->data + (int)(curr_block->allocated);
  curr_block->allocated += n;
  return out;
}

static inline void arena_free(Arena *a) {
  Arena *current = a;
  Arena *next = a->next;
  free(current->data);

  while (next != NULL) {
    current = next;
    next = next->next;
    free(current->data);
    free(current);
  }
}

#endif

#ifdef ARENA_DEBUG
static inline void ptrprint(void *p) { printf("pointer address: %p\n", p); }
static inline void ptrdiff(void *p1, void *p2) {
  printf("ptr diff: %li\n", (ptrdiff_t)((char *)p1 - (char *)p2));
}

static inline void arena_info(Arena a) {
  int i = 0;
  Arena *ptr = &a;
  do {
    printf("block %i:\n", i);
    printf("\tcapacity: %li\n", ptr->capacity);
    printf("\tallocated: %li\n", ptr->allocated);
    ptr = ptr->next;
    i++;
  } while (ptr != NULL);
}

static inline void pallocated(Arena a) {
  printf("memory used: %li\n", a.allocated);
}
#endif
