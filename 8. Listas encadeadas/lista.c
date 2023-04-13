#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct listano // representa o nó da lista
{
    int info;
    ListaNo *prox; // aponta para a próxima estrutura do mesmo tipo
};

struct lista
{
    ListaNo *prim;
};

Lista *lst_cria()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->prim = NULL;

    return l;
}

void list_insere(Lista *l, int v)
{
    ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
    novo->info = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void list_imprime(Lista *l)
{
    for (ListaNo *p = l->prim; p != NULL; p = p->prox)
    {
        printf("Info = %d\n", p->info);
    }
}

void list_retira(Lista *l, int v)
{
    ListaNo *ant = NULL;
    ListaNo *p = l->prim;

    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }

    if (p != NULL)
    {
        if (ant == NULL)
        {
            l->prim = p->prox;
        }
        else
        {
            ant->prox = p->prox;
        }
        free(p);
    }
}
void list_libera(Lista *l)
{
    ListaNo *p = l->prim;

    while (p != NULL)
    {

        ListaNo *t = p->prox;

        free(p);

        p = t;
    }
    free(l);
}
