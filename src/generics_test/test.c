#define GENTYPE char
#include "varvec.h"

#define GENTYPE char *
#define GENTYPENAME char_p
#include "varvec.h"

#define GENTYPE int
#include "varvec.h"

#define GENTYPE int *
#define GENTYPENAME int_p
#include "varvec.h"

#define GENTYPE float
#include "varvec.h"

#define GENTYPE float *
#define GENTYPENAME float_p
#include "varvec.h"

#define vnew(v) _Generic((*v), \
    Vector_char: vnew_char, \
    Vector_int: vnew_int, \
    Vector_float: vnew_float, \
    Vector_char_p: vnew_char_p, \
    Vector_int_p: vnew_int_p, \
    Vector_float_p: vnew_float_p, \
    )()

#define vadd(v, e) _Generic((*v), \
    Vector_char: vadd_char, \
    Vector_int: vadd_int, \
    Vector_float: vadd_float, \
    Vector_char_p: vadd_char_p, \
    Vector_int_p: vadd_int_p, \
    Vector_float_p: vadd_float_p, \
    )((v), (e))

