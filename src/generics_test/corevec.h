#include <stdlib.h>

#include "intvec.h"
#include "charvec.h"
#include "floatpvec.h"

#define vnew(v) _Generic((*v),         \
    Vector_int: vnew_int,              \
    Vector_char: vnew_char,            \
    Vector_float_p: vnew_float_p,      \
    default: vnew_int)()

#define vadd(v, e) _Generic((*v),      \
    Vector_int: vadd_int,              \
    Vector_char: vadd_char,            \
    Vector_float_p: vadd_float_p,      \
    default: vadd_int)((v), (e))

#define vnewtest(t) _Generic(((t)0),   \
    int: vnew_int,                     \
    char: vnew_char,                   \
    float *: vnew_float_p,             \
    default: vnew_int)()
