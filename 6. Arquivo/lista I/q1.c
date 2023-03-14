#include <stdio.h>

int main()
{
    char nome[50];
    float nota1, nota2, nota3, media = 0;

    FILE *e, *s;
    e = fopen("entrada_q3.txt", "r"); // le o arquivo entrada_q3
    if (e == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.");
        return 1;
    }
    s = fopen("saida_q3.txt", "w"); // cria/escreve o arquivo saida_q3
    if (s == NULL)
    {
        printf("Erro ao abrir o arquivo de saida.");
        return 1;
    }

    while (!(feof(e))) // repete enquanto não chegar ao final do arquivo
    {
        fscanf(e, "%s %f\t%f\t%f", nome, &nota1, &nota2, &nota3); // lendo a string formatada no arquivo de entrada
        media = (nota1 + nota2 + nota3) / 3;
        fprintf(s, "%s\t%.1f %s\n", nome, media, (media >= 7)? "aprovado." : "reprovado."); // escrevendo uma string formatada no arquivo de saida
    }

    fclose(e);
    fclose(s);

    return 0;
}