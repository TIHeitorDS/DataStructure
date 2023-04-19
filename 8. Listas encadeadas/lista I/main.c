#include "lista.c"

int main(void)
{
    int maior = 0;
    Lista *l = lst_cria();
    lst_insere(l, 3);
    lst_insere(l, 4);
    lst_insere(l, 6);
    lst_insere(l, 7);
    lst_insere(l, 8);
    maior = maiores(l, 4);
    printf("quantidade de numeros de nos maiores que 4: %d.", maior);
    return 0;
}