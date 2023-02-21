#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qnt = 0;
    float *preco;
    int colunas = 100;

    printf("Informe a quantidade de frutas: ");
    scanf("%d", &qnt);

    char **matFrutas = (char **)malloc(qnt * sizeof(char *));
    for (int i = 0; i < qnt; i++)
    {
        matFrutas[i] = (char *)malloc(colunas * sizeof(char));
    }

    if (matFrutas == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }

    preco = (float *)malloc(qnt * sizeof(float));

    if (preco == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }

    // preencher
    for (int i = 0; i < qnt; i++)
    {
        printf("Informe o nome da fruta: ");
        scanf(" %[^\n]s", matFrutas[i]);
        printf("preco: ");
        scanf("%f", &preco[i]);
        printf("\n");
    }

    for (int i = 0; i < qnt; i++)
    {
        matFrutas[i] = (char *)realloc(matFrutas[i], sizeof(char));
    }

    // imprime
    for (int i = 0; i < qnt; i++)
    {
        printf("Nome: %s\tPreco: R$%.2f\n", matFrutas[i], preco[i]);
    }

    for (int i = 0; i < qnt; i++)
    {
        free(matFrutas[i]);
    }

    free(matFrutas);
    free(preco);

    return 0;
}