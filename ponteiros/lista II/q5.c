#include <stdio.h>

void numbers(int *sum, int n1, int n2) {
    *sum = n1 + n2;
}

int main(void) {
    int x, y, sum;

    printf("Input the first number : \n");
    scanf("%d\n", &x);
    printf("Input the second number : \n");
    scanf("%d\n", &y);

    numbers(&sum, x, y);

    printf("The sum of %d and %d is %d", x, y, sum);
    return 0;
}