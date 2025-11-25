#include "Core/arena.h"
#include "Core/vector.h"

int main(void) {
  Arena a = arena_create();
  vector_int vec = vector_arena_create_int(&a);

  for (int i = 0; i < 256; i++) {
    vector_arena_push_int(&a, &vec, i);
  }

  vector_print_int(&vec);
  arena_free(&a);
}
