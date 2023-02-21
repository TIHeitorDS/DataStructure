#include <stdio.h>

typedef enum genero
{
    neutro,
    masculino,
    feminino
} Genero;

typedef struct pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Produto;

void cadastar_produto(Produto *p)
{
    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]s", p->nome);

    printf("Informe a idade da pessoa: ");
    scanf("%d", &p->idade);

    printf("Informe seu genero:\n1. masculino\n2. feminino");
    scanf("%d", (int *)&p->genero);
}

int main(void)
{
    Produto pessoa;
    cadastar_produto(&pessoa);

    switch (pessoa.genero)
    {
    case masculino:
        printf("\nNome: %s", pessoa.nome);
        printf("\nIdade: %d", pessoa.idade);
        printf("\nGenero: masculino");
        break;
    case feminino:
        printf("\nNome: %s", pessoa.nome);
        printf("\nIdade: %d", pessoa.idade);
        printf("\nGenero: feminino");
        break;
    default:
        break;
    }
    return 0;
}
