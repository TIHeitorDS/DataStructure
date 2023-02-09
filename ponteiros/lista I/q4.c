#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro) {
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    *perimetro = 6 * l;
}

int main() {
    float l, x, y;
    printf("Informe o lado do hexagono: ");
    scanf("%f", &l);
    calcula_hexagono(l, &x, &y);
    printf("Area: %f\nPerimetro: %f", x, y);
    return 0;
}