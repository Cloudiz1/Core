// #define NO_VECTOR_DEFAULTS
#include "vector.h"
// DEFINE_VECTOR(int, int);
// DEFINE_VECTOR(int *, int_ptr);

int main(void) {
  vector_int v = vector_create_int();
  for (int i = 0; i < 256; i++) {
    vector_push_int(&v, i);
  }

  vector_int v2 = vector_clone_int(&v);

  vector_print_int(&v);
  vector_free_int(&v);
  vector_free_int(&v2);
}
