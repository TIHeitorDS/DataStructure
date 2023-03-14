#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 20
#define MAX_TURMAS 2

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma *turmas[MAX_TURMAS];

void inicializa()
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        turmas[i] = NULL;
    }
}

Turma *cria_turma(char id)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));

    if (turma == NULL)
    {
        exit(1);
    }

    turma->id = id;

    turma->vagas = MAX_VAGAS;

    for (int i = 0; i < MAX_VAGAS; i++)
    {
        turma->alunos[i] = NULL;
    }

    return turma;
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    turma->vagas -= 1; // diminui a quantidade de vagas da turma

    for (int j = 0; j < MAX_VAGAS; j++)
    {
        if (turma->alunos[j] == NULL)
        {
            turma->alunos[j] = (Aluno *)malloc(sizeof(Aluno)); // aloca o vetor Aluno

            for (int k = 0; k < 3; k++)
            {
                turma->alunos[j]->notas[k] = 0.0; // inicializa as notas com zero
                turma->alunos[j]->media = 0.0; // inicializa a media com zero
            }

            turma->alunos[j]->mat = mat;
            strcpy(turma->alunos[j]->nome, nome);

            break;
        }
    }
}

void lanca_notas(Turma *turma)
{
    float nota = 0, media = 0;
    for (int i = 0; i < MAX_VAGAS; i++)
    { // percorre o vetor de Alunos
        media = 0;
        if (turma->alunos[i] != NULL && turma->alunos[i]->notas[0] == 0.0)
        { // verifica se ha vagas preenchidas e se falta alunos receber as notas
            printf("\nMatricula: %d\tAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (int j = 0; j < 3; j++)
            { // preenche as notas de um aluno
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &nota);

                turma->alunos[i]->notas[j] = nota;

                media += nota;
            }
            turma->alunos[i]->media = media / 3;
        }
    }
}

void imprime_alunos(Turma *turma)
{
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d\tNome: %s\nMedia: %.1f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma **turmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Turma: %c\tVagas disponiveis: %d\n", turmas[i]->id, turmas[i]->vagas);
        printf("Lista de alunos matriculados: \n");
        for (int j = 0; j < MAX_VAGAS; j++)
        {
            if (turmas[i]->alunos[j] != NULL)
            {
                printf("%s\n", turmas[i]->alunos[j]->nome);
            }
        }
    }
}

Turma *procura_turma(Turma **turmas, int n, char id)
{ // essa função recebe o vetor turmas
    for (int j = 0; j < n; j++)
    {
        if (turmas[j]->id == id)
            return turmas[j]; // se o id que o usuario digitou for igual ao id de algum vetor, retorna ele
    }
    return NULL;
}

int main(void)
{
    Turma *t = (Turma *)malloc(sizeof(Turma)); // retorna a turma que o usuario procura

    int op, index = 0, mat = 0; // index vai controlar o limite do vetor turmas
    char id, *nome;
    nome = (char *)malloc(81 * sizeof(char));
    if (t == NULL || nome == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Heitor Claudino\tVersao: 1.5\n\n");
    while (op != 6)
    {
        printf("\nMenu:\n");
        printf("1 - Criar turma\n2 - Listar turmas\n3 - Matricular Aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        system("cls");
        switch (op)
        {
        case 1:
            if (index >= MAX_TURMAS)
            {
                printf("\nNao e possivel criar mais turmas!\n");
                break;
            }

            printf("Criando nova turma...\n");
            printf("Informe um id: ");
            scanf(" %c", &id);

            turmas[index] = cria_turma(id);

            printf("Turma %c criada com sucessso!\n", turmas[index]->id);
            index++;

            break;
        case 2:
            if (turmas[0] == NULL)
            {
                printf("\nNao ha turmas cadastradas!\n");
                break;
            }

            printf("Listando turmas...\n");

            for (int k = 0; k < index; k++)
            {
                printf("Turma %c - %d vagas disponiveis\n", turmas[k]->id, turmas[k]->vagas);
            }

            break;
        case 3:
            if (turmas[0] == NULL)
            {
                printf("\nNao ha turmas cadastradas!\n");
                break;
            }

            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            t = procura_turma(turmas, index, id);

            if (t != NULL && t->vagas != 0)
            {
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                printf("Digite o nome: ");
                scanf(" %[^\n]s", nome);

                matricula_aluno(t, mat, nome);
                printf("\nAluno matriculado com sucesso!");
            } 
            else if (t != NULL && t->vagas != 0) printf ("Nao ha mais vagas para esta turma!\n");
            else printf("\nTurma inexistente!\n");

            break;
        case 4:
            if (turmas[0] == NULL)
            {
                printf("\nNao ha turmas cadastradas!\n");
                break;
            }

            printf("Lancando notas...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            t = procura_turma(turmas, index, id);
            
            if (t != NULL && t->alunos[0] == NULL) printf("Nao ha alunos matriculados nesta turma!\n");
            else if (t != NULL) lanca_notas(t); 

            else printf("\nTurma inexistente!\n");

            break;
        case 5:
            if (turmas[0] == NULL)
            {
                printf("\nNao ha turmas cadastradas!\n");
                break;
            }

            printf("Listando alunos..\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            t = procura_turma(turmas, index, id);

            if (t != NULL && t->alunos[0] != NULL) imprime_alunos(t);
            else if (t != NULL && t->alunos[0] == NULL) printf("Nao ha alunos matriculados nesta turma!\n");
            else printf("\nTurma inexistente!\n");

            break;
        case 6:
            printf("Obrigado por usar este programa!");

            break;
        default:
            break;
        }
    }

    for (int i = 0; i < MAX_TURMAS; i++)
    {
        for (int j = 0; j < MAX_VAGAS; j++)
        {
            free(turmas[i]->alunos[j]);
        }
    }

    free(turmas);
    free(t);
    free(nome);

    return 0;
}
