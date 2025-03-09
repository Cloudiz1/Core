#include <stdio.h>

#include "intvec.h"
#include "floatpvec.h"

int main()
{
    Vector_int intvec = { 0 };
    Vector_float_p floatvec = { 0 };

    return intvec.size + floatvec.size;
}

