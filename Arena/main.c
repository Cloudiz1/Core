#define ARENA_DEBUG
#define ARENA_MINIMUM_MEMORY 16
#include "arena.h"

int main(void) {
  Arena a = arena_create();
  int *arr1 = arena_alloc(&a, 4 * sizeof(int));
  int *arr2 = arena_alloc(&a, 24 * sizeof(int));

  for (int i = 0; i < 4; i++) {
    arr1[i] = i;
  }

  for (int i = 0; i < 24; i++) {
    arr2[i] = i + 4;
  }

  for (int i = 0; i < 4; i++) {
    printf("%i\n", arr1[i]);
  }

  for (int i = 0; i < 24; i++) {
    printf("%i\n", arr2[i]);
  }

  arena_info(a);
  arena_free(&a);
}
