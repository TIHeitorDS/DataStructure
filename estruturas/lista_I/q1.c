#include <stdio.h>

typedef struct funcionarios {
    char nome[50], cargo[100];
    float salario;
} Funcionarios;

int main() {
    int n;
    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &n);

    Funcionarios funcionario[n];

    for(int i = 0; i < n; i++) {
    printf("Informe o nome do %d funcionario: ", i + 1);
    scanf(" %[^\n]", funcionario[i].nome);

    printf("Informe o salario do %d funcionario: ", i + 1);
    scanf("%f", &funcionario[i].salario);

    printf("Informe o cargo do %d funcionario: ", i + 1);
    scanf(" %[^\n]", funcionario[i].cargo);
    }

    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Informe o nome do %d funcionario: %s\n", i + 1, funcionario[i].nome);
        printf("Informe o salario do %d funcionario: %f\n", i + 1, funcionario[i].salario);
        printf("Informe o cargo do %d funcionario: %s\n", i + 1, funcionario[i].cargo);
        printf("\n");
    }

    return 0;
}