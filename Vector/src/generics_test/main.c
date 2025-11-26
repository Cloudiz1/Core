#include <stdio.h>

#define GEN_TYPE char
#include "varvec.c"

#define GEN_TYPE int
#include "varvec.c"

#define GEN_TYPE float
#include "varvec.c"

#define GEN_TYPE char *
#define GEN_TYPE_NAME char_p
#include "varvec.c"

#define GEN_TYPE int *
#define GEN_TYPE_NAME int_p
#include "varvec.c"

#define GEN_TYPE float *
#define GEN_TYPE_NAME float_p
#include "varvec.c"

int main()
{
    Vector_int intvec = Vector_Create_int();
    Vector_float floatvec = Vector_Create_float();
}

