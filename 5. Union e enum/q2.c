#include <stdio.h>

typedef union tipo
{
    char t[50];
} Tipo;

typedef struct produto
{
    char nome[50];
    float preco;
    Tipo tipo
} Produto;

void cadastar_produto(Produto *p)
{
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]s", p->nome);

    printf("Informe o preco do produto: ");
    scanf("%f", &p->preco);

    printf("Informe o tipo do produto: ");
    scanf(" %[^\n]s", p->tipo.t);
}

int main(void)
{
    Produto p;
    cadastar_produto(&p);

    printf("Nome: %s\n", p.nome);
    printf("Preco: %.2f\n", p.preco);
    printf("Tipo: %s", p.tipo.t);

    return 0;
}
