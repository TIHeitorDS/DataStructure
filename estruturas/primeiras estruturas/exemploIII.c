#include <stdio.h>
#include <stdlib.h>

typedef struct alunos {
    char nome[50];
    int matricula;
} Alunos;

int main() {
    int n;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);

    Alunos** vetor = (Alunos**) malloc(n * sizeof(Alunos*));

    for(int i = 0; i < n; i++) {
        printf("\n");
        printf("nome: ");
        scanf(" %[^\n]s", vetor[i]->nome);
        printf("Matricula: ");
        scanf("%d", &vetor[i]->matricula);

        printf("\n");
        printf("Nome: %s\nMatricula: %d", vetor[i]->nome, vetor[i]->matricula);
        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        free(vetor[i]);
    }

    free(vetor);

    return 0;
}