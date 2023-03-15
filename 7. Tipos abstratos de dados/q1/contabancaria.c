#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contabancaria.h"

struct contaBancaria
{
    char titular[81];
    int numero;
    float saldo;
};

ContaBancaria *cria_conta(char *titular, int numero, float saldo)
{
    ContaBancaria *contBanc = (ContaBancaria *)malloc(sizeof(ContaBancaria));

    strcpy(contBanc->titular, titular);
    contBanc->numero = numero;
    contBanc->saldo = saldo;

    return contBanc;
};

void deposita(ContaBancaria *contabancaria, float saldo)
{
    contabancaria->saldo = saldo;
}

void sacar_saldo(ContaBancaria *contabancaria, float saldo)
{
    if (contabancaria->saldo >= saldo)
    {
        contabancaria->saldo -= saldo;
        printf("valor sacado: %.1f\tsaldo disponivel: %.1f\n", saldo, contabancaria->saldo);
    }
    else 
    {
        printf("Saldo insuficiente para sacar!\n");
    }
}

void transfere_saldo(ContaBancaria **contabancaria, float transfere)
{
    int index, key;
    printf("De qual conta voce deseja transferir o saldo? ");
    scanf("%d", &key);
    printf("Dara qual conta voce deseja transferir? ");
    scanf("%d", &index);
    if (contabancaria[key - 1]->saldo >= transfere)
    {
        contabancaria[index - 1]->saldo += transfere;
        contabancaria[key - 1]->saldo -= transfere;
    }
    else
    {
        printf("Nao e possivel realizar a transferencia porque o saldo e insuficiente!\n");
    }
}

void ver_saldo(ContaBancaria *contabancaria)
{
    printf("Saldo disponivel: %.1f\n", contabancaria->saldo);
}

void exclui_conta(ContaBancaria **contabancaria)
{
    free(contabancaria);
}