#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

typedef struct circulo {
    Ponto p;
    float r;
} Circulo;

void captura(Ponto* pp) {
    printf("Digite as cordenas dos pontos (x, y): ");
    scanf("%f %f", &pp->x, &pp->y);
}

float distancia(Ponto* p, Ponto* q) {
    float d = sqrt((q->x - p->x) * (q->x - p->x) + (q->y - p->y) * (q->y - p->y));

    return d;
}

int interior(Circulo* c, Ponto* p) {
    float d = distancia(&c->p, p);

    return (d < c -> r);
}

int main() {
    Ponto p;
    float d;

    captura(&p);

    return 0;
}
