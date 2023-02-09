#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {
    int carga_horaria;
    char nome[50];
} Disciplina;

typedef struct aluno {
    char nome[50];
    int matricula;
    Disciplina disciplina;
} Aluno;

int main () {
    Aluno aluno;

    printf("Informe o nome: ");
    scanf("%[^\n]", aluno.nome);

    printf("Informe a matricula: ");
    scanf("%d", &aluno.matricula);

    printf("Infomre a carga horaria: ");
    scanf("%d", &aluno.disciplina.carga_horaria);

    printf("Informe a disciplina: ");
    scanf("%[^\n]", aluno.disciplina.nome);
    

    return 0;
}