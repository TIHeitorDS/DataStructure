#include <stdio.h>
#include <stdlib.h>

int main () {
    int quantidadeFrutas;
    int colunas = 50;
    printf("Informe a quantidade de frutas: ");
    scanf("%d", &quantidadeFrutas);

    char **frutas = (char**) malloc(quantidadeFrutas * sizeof(char*));
    if (frutas == NULL) {
        exit(1);
    }
    for (int i = 0; i < quantidadeFrutas; i++) {
        frutas[i] = (char*) malloc(colunas * sizeof(char));
    }


    float *precos = (float*) malloc(quantidadeFrutas * sizeof(float));
    if (precos == NULL) {
        exit(1);
    }
    printf("Informe as frutas e seu valor: \n");
    for (int i = 0; i < quantidadeFrutas; i++) {
        scanf(" %[^\n]s", frutas[i]);
        scanf("%f", &precos[i]);
    }

    for (int i = 0; i < quantidadeFrutas; i++) {
        free(frutas[i]);
    }

    for (int i = 0; i < colunas; i++) {
        frutas[i] = (char*) realloc(frutas[i], colunas * sizeof(char));
    }

    free(frutas);
    free(precos);

    return 0;
}