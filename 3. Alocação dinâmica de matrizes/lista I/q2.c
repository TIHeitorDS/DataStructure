#include <stdio.h>
#include <stdlib.h>

int main () {
    int linhas = 3;
    int colunas = 3;

    int **matriz = (int **) malloc(linhas * sizeof(int));

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", (matriz[i][j] = i * 3 + j));
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;


}