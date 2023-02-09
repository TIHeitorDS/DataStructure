#include <stdio.h>

int main(void) {
    int a, b, sum;
    int *x, *y;

    printf("Input the first number : \n");
    scanf("%d", &a);

    printf("Input the second number : \n");
    scanf("%d", &b);

    x = &a;
    y = &b;
    
    sum = *x + *y;

    printf("The sum of the entered numbers is : %d", sum);
    return 0;
}