#include <stdio.h>
#include <stdlib.h>

int main () {
    int m, n, count = 0;
    char **mapa;

    printf("Informe a quantidade de linhas: ");
    scanf("%d", &m);
    printf("Informe a quantidade de colunas: ");
    scanf("%d", &n);

    mapa = (char**) malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        mapa[i] = malloc(n * sizeof(char));
    }

    for (int i = 0; i < m; i++) {
        printf("Informe os caracteres da %d linha:\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%s", &mapa[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mapa[0][j] == '#' && mapa[0][j + 1] == '.' || mapa[0][j] == '.' && mapa[0][j + 1] == '#') {
                count++;
            }

            if(mapa[0][j] == mapa[0][j + 1]) {
                if(mapa[0][j + 1] != mapa[1][j + 1] && mapa[0][j + 1] == mapa[1][j + 2]) {
                    count++;
                }
            }
        }
    }

    printf("%d", count);

    for (int i = 0; i < m; i++) {
        free(mapa[i]);
    }

    free(mapa);

    return 0;
}