#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct listaNo
{ // Estrutra que representa o nó da lista
    int info;
    ListaNo *prox;
};

struct lista
{ // Representa a lista em si
    ListaNo *prim;
};

Lista *lst_cria(void)
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void lst_insere(Lista *l, int v)
{
    ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
    novo->info = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void lst_retira(Lista *l, int v)
{
    ListaNo *ant = NULL;  // ponteiro para o elemento anterior
    ListaNo *p = l->prim; // ponteiro para percorrer a lista

    while (p != NULL && p->info != v) // procura o elemento na lista e guarda no anterior
    {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) // verifica se achou o elemento
    {
        if (ant == NULL) // retira elemento do início
        {
            l->prim = p->prox;
        }
        else // retira elemento do meio da lista
        {
            ant->prox = p->prox;
        }
        free(p);
    }
}

int maiores(Lista *l, int v)
{
    int count = 0;
    for (ListaNo *p = l->prim; p != NULL; p = p->prox)
    {
        if (p->info > v)
        {
            count++;
        }
    }
    return count;
}

void lst_imprime(Lista *l)
{
    for (ListaNo *p = l->prim; p != NULL; p = p->prox)
    {
        printf("info: %d\n", p->info);
    }
}

int lst_vazia(Lista *l)
{
    return l->prim == NULL;
}
