#include <stdio.h>

int main()
{
    FILE *entrada_q2, *saida;
    int vetor[10], media = 0, maior = 0, menor = 9999;

    entrada_q2 = fopen("entrada_q2.txt", "r");
    if (entrada_q2 == NULL)
    {
        printf("Erro ao ler o arquivo.");
        return 1;
    }
    saida = fopen("saida_q2.txt", "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    while (!(feof(entrada_q2)))
    {
        for (int i = 0; i < 10; i++)
        {
            fscanf(entrada_q2, "%d", &vetor[i]);
            if (vetor[i] < menor)
            {
                menor = vetor[i];
            }
            if (vetor[i] > maior)
            {
                maior = vetor[i];
            }
        
            media += vetor[i];
        }
    }

    fprintf(saida, "Menor numero: %d\nMaior numero: %d\nMedia dos elementos: %d", menor, maior, media / 10);

    fclose(saida);
    fclose(entrada_q2);

    return 0;
}