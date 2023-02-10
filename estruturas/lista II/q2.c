#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int maior = 0, menor = 0;

    for(int i = 0; i < n; i++) {
        if(pessoa[i].idade < pessoa[menor].idade) {
            menor = i;
        }

        if(pessoa[maior].idade < pessoa[i].idade) {
            maior = i;
        }
    }

    printf("Pessoa de maior idade: %s (%d anos).\n", pessoa[maior].nome, pessoa[maior].idade);
    printf("Pessoa de menor idade: %s (%d anos).", pessoa[menor].nome, pessoa[menor].idade);
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