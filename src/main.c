#include "include/vector.h"
#include <stdio.h>

void vprinti(vector *vec) {
    printf("[");
    for (int i = 0; i < vec->size; i++)
    {
        printf("%i", *(int*)vget(vec, i));
        if (i != vec->size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(void) {
    vector *vec = vnew(sizeof(int));

    for (int i = 0; i < 10; i++) {
        vadd(vec, &i);
    }

    for (int i = 0; i < 10; i++) {
        // vprinti(vec);
        // printf("%i \n", *(int*)vpop(vec));
        vpop(vec);
    }

    // // printf("%i \n", *(int*)vget(v0ec, 9));
    // for (int i = 0; i < 10; i++)
    //     printf("%i \n", *(int*)vpop(vec));
}