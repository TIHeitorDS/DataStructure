#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int linhas, colunas;
    printf("Forneca a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("Forneca a quantidade de colunas: ");
    scanf("%d", &colunas);

    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    int **matriz2 = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        matriz2[i] = (int *)malloc(colunas * sizeof(int));

    }

    int **matriz3 = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        matriz3[i] = (int *)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Forneca os elementos da %d linha da matriz 1: ", i + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Forneca os elementos da %d linha da matriz 2: ", i + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz3[i][j] = pow(matriz[i][j], 2) + pow(matriz2[i][j], 2);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\t", matriz3[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            free(matriz[i][j]);
            free(matriz2[i][j]);
            free(matriz3[i][j]);
        }
    }

    free(matriz);
    free(matriz2);
    free(matriz3);
    return 0;
}