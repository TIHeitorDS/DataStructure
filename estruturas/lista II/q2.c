#include <stdio.h>
#include <stdlib.h> 

typedef struct pessoa {
    char nome[50];
    int numero_documento;
    int idade;
} Pessoa;

void preenche(Pessoa* pessoa, int n) {
    for(int i = 0; i < n; i++) {
        printf("Informe o nome do pessoa: ");
        scanf(" %[^\n]s", pessoa[i].nome);

        printf("Informe o numero do documento: ");
        scanf("%d", &pessoa[i].numero_documento);

        printf("Informe a idade: ");
        scanf("%d", &pessoa[i].idade);
    }
}

void imprime(Pessoa* pessoa, int n) {
    printf("\n");
    for(int j = 0; j < n; j++) {
        printf("nome da pessoa: %s\n", pessoa[j].nome);
        printf("numero do documento da pessoa: %d\n", pessoa[j].numero_documento);
        printf("idade da pessoa: %d\n", pessoa[j].idade);
    }

}

void altera_idade(Pessoa* pessoa, int n) {
    printf("\n");
    for(int k = 0; k < n; k++) {
        printf("Infome a nova idade: ");
        scanf("%d", &pessoa[k].idade);
    }
}

void maior_menor_idade(Pessoa* pessoa, int n) {
    int index = 0, key = 0;
    int idade = 0, menorIdade = 0;
    for(int l = 0; l < n; l++) {
        if(pessoa[l].idade > idade) {
            idade = pessoa[l].idade;
            index = l;
        } else {
            menorIdade = pessoa[l].idade;
            key = l;
        }
    }

    printf("nome e idade da pessoa mais velha: %s (%d anos).\n", pessoa[index].nome, idade);
    printf("nome e idade da pessoa mais nova: %s (%d anos).", pessoa[key].nome, menorIdade);
}

int main() {
    int n;
    printf("Informe a quantidade de pessoas: ");
    scanf("%d", &n);
    Pessoa* pessoa = (Pessoa*) malloc(n * sizeof(Pessoa));

    if(pessoa == NULL) {
        exit(1);
    }

    preenche(pessoa, n);
    imprime(pessoa, n);
    altera_idade(pessoa, n);
    maior_menor_idade(pessoa, n);

    free(pessoa);

    return 0;
}