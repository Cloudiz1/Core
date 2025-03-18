#include <stdio.h>

#include "corevec.h"

int main()
{
    Vector_int *intvec = vnew(intvec);
    Vector_float_p *floatvec = vnew(floatvec);
    float f = 5.0;
    float *p = &f;

    vadd(intvec, 5);
    vadd(floatvec, p);

    return intvec->size + floatvec->size;
}

