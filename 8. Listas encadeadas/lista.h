typedef struct listano ListaNo;
typedef struct lista Lista;

void list_insere(Lista *l, int v);
void list_imprime(Lista *l);
void list_retira(Lista *l, int v);
void list_libera(Lista *l);
