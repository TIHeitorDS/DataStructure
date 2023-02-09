#include <stdio.h>

int main(void) {
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("Pointer : Demonstrate the use of & and * operator :\n");
    printf("m = %d\nfx = %f\ncht = %c\n\n", m, fx, cht);

    printf("Using & operator :\n");
    printf("address of m = %p\n\n", &m);
    printf("address of fx = %p\n\n", &fx);
    printf("address of cht = %p\n\n", &cht);

    printf("Using & and * operator :\n");
    printf("value at address of m = %d\n\n", m);
    printf("value at address of fx = %f\n\n", fx);
    printf("value at address of cht = %c\n\n", cht);

    int *point1 = &m;
    float *point2 = &fx;
    char *point3 = &cht;

    printf("Using only pointer variable :\n");
    printf("address of m = %p\n\n", &point1);
    printf("address of fx = %p\n\n", &point2);
    printf("address of cht = %p\n\n", &point3);

    printf("Using only pointer operator :\n");
    printf("value at address of m = %d\n\n", *point1);
    printf("value at address of fx = %f\n\n", *point2);
    printf("value at address of cht = %c\n\n", *point3);

    return 0;
}