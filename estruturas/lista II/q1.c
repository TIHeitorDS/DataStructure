#include <stdio.h>
#include <stdlib.h>

typedef struct funcionarios {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

void preenche(Funcionario** funcionario, int n) {
    for(int i = 0; i < n; i++) {
        printf("Informe o nome do funcionario: ");
        scanf(" %[^\n]s", funcionario[i]->nome);

        printf("Informe o salario do funcionario: ");
        scanf("%f", &funcionario[i]->salario);

        printf("Informe o identificador do funcionario: ");
        scanf("%d", &funcionario[i]->identificador);

        printf("Informe o cargo do funcionario: ");
        scanf(" %[^\n]s", funcionario[i]->cargo);
    }
}

void imprime(Funcionario** funcionario, int n) {
    printf("\n");
    for(int j = 0; j < n; j++) {
        printf("Nome do funcionario: %s\n", funcionario[j]->nome);
        printf("Salario do funcionario: %f\n", funcionario[j]->salario);
        printf("Identificador do funcionario: %d\n", funcionario[j]->identificador);
        printf("Cargo do funcionario: %s\n", funcionario[j]->cargo);
    }
}

void altera_salario(Funcionario** funcionario, int n) {
    printf("\n");
    for(int k = 0; k < n; k++) {
        printf("Infome o novo valor do salario: ");
        scanf("%f", &funcionario[k]->salario);
    }
}

void maior_menor_salario(Funcionario** funcionario, int n) {
    int maior = 0, menor = 0;

    for(int i = 0; i < n; i++) {
        if(funcionario[i]->salario < funcionario[menor]->salario) {
            menor = i;
        }

        if(funcionario[maior]->salario < funcionario[i]->salario) {
            maior = i;
        }
    }

    printf("Cargo com maior salario: %s (R$%f).\n", funcionario[maior]->cargo, funcionario[maior]->salario);
    printf("Cargo com menor salario: %s (R$%f).", funcionario[menor]->cargo, funcionario[menor]->salario);
}

int main() {
    int n;
    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &n);
    Funcionario** funcionario = (Funcionario**) malloc(n * sizeof(Funcionario*));

    for(int j = 0; j < funcionario; j++) {
        funcionario[j] = (Funcionario*) malloc(n * sizeof(Funcionario));
    }

    if(funcionario == NULL) {
        exit(1);
    }

    preenche(funcionario, n);
    imprime(funcionario, n);
    altera_salario(funcionario, n);
    maior_menor_salario(funcionario, n);

    for(int i = 0; i < n; i++) {
        free(funcionario[i]);
    }

    free(funcionario);

    return 0;
}