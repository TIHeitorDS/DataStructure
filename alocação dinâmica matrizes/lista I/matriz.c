#include <stdio.h>
#include <stdlib.h>

float ** novaMatriz (int linhas, int colunas) {
    float **matriz = (float **) malloc(linhas * sizeof(float*));

    for (int linha = 0; linha < linhas; linha++) {
        matriz[linha] = (float *) malloc(colunas * sizeof(float));
    }

    return matriz;

}

int main () {
    int linhas = 5;
    int colunas = 5;

    float ** matriz = novaMatriz (linhas, colunas);


    printf("Informe os valores para matriz \n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Valores da matriz\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.0lf ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int linha = 0; linha < linhas; linha++) {
        free(matriz[linha]);
    }

    free(matriz);

    return 0;
}