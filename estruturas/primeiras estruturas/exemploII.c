#include <stdio.h>
#include <stdlib.h>

typedef struct alunos {
    char nome[50];
    int matricula;
    float IRA;
} Alunos;

void print(Alunos* aluno, int quant) {
    for(int i = 0; i < quant; i++) {
       printf("Nome: %s\n", aluno[i].nome);
       printf("Matricula: %d\n", aluno[i].matricula);
       printf("IRA: %.2f\n", aluno[i].IRA);
       printf("\n");
    }
}

int main () {
    int qtd_alunos;
    printf("INforme a quantidade de alunos: ");
    scanf("%d", &qtd_alunos);

    Alunos* vetor_alunos = (Alunos*) malloc(qtd_alunos * sizeof(Alunos));
    if(vetor_alunos == NULL) {
        exit(1);
    }

    for(int i = 0; i < qtd_alunos; i++) {
       printf("Digite o nome do %d aluno: ", i + 1);
       scanf(" %[^\n]s", vetor_alunos[i].nome);
       printf("Digite o numero da matricula do %d aluno: ", i + 1);
       scanf("%d", &vetor_alunos[i].matricula);
       printf("Digite o IRA do %d aluno: ", i + 1);
       scanf("%f", &vetor_alunos[i].IRA); 
    }

    printf("\n");
    print(vetor_alunos, qtd_alunos);
    free(vetor_alunos);

    return 0;
}