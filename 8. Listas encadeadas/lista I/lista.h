typedef struct listaNo ListaNo;
typedef struct lista Lista;

Lista *lst_cria(void);
void lst_insere(Lista *l, int v);
void lst_retira(Lista *l, int v);
int maiores(Lista *l, int v);
void lst_imprime(Lista *l);
int lst_vazia(Lista *l);