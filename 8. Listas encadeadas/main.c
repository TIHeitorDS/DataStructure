#include <stdio.h>
#include <stdlib.h>

#include "lista.c"

int main(void)
{
    Lista *l = lst_cria();
    list_insere(l, 23);
    list_insere(l, 45);
    list_imprime(l);
    list_libera(l);

    return 0;
}