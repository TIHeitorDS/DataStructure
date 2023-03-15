#include <stdio.h>
#include <stdlib.h>

#include "contabancaria.h"

int main(void)
{
    char titular[81];
    int index = 0, opcao, numero, key = 0; // index vai controlar o vetor contabancaria; key seleciona o vetor que sera alterado pelo usuario
    float saldo, sacar, transfere;

    ContaBancaria **contabancaria = (ContaBancaria **)malloc(sizeof(ContaBancaria *));

    do
    {
        printf("\nInforme uma opcaoo:\n1. Criar conta\n2. Depositar\n3. Sacar\n4. Transferir\n5. Saldo\n6. Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            index++;
            contabancaria = (ContaBancaria **)realloc(contabancaria, index * sizeof(ContaBancaria *));
            printf("\nTitular: ");
            scanf(" %[^\n]s", titular);
            printf("Numero: ");
            scanf("%d", &numero);
            printf("Saldo: ");
            scanf("%f", &saldo);

            contabancaria[index - 1] = cria_conta(&titular[81], numero, saldo);
            break;
        case 2:
            printf("\nQual conta voce deseja alterar o saldo? ");
            scanf("%d", &key);
            printf("Informe o valor do novo saldo: ");
            scanf("%f", &saldo);

            deposita(contabancaria[key - 1], saldo);
            break;
        case 3:
            printf("\nQual conta voce deseja sacar: ");
            scanf("%d", &key);
            printf("Insira o valor para sacar: ");
            scanf("%f", &sacar);

            sacar_saldo(contabancaria[key - 1], sacar);
            break;
        case 4:
            printf("Insira o valor para transferir: ");
            scanf("%f", &transfere);

            transfere_saldo(contabancaria, transfere);
            break;
        case 5:
            printf("Qual conta voce deseja ver o saldo: ");
            scanf("%d", &key);

            ver_saldo(contabancaria[key - 1]);
            break;
        default:
            break;
        }

    } while (opcao != 6);

    exclui_conta(contabancaria);
    return 0;
}