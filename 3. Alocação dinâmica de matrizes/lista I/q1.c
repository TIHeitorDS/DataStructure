#include <stdio.h>
#include <stdlib.h>

int main () {
    int tamanho = 10;
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = i;
        printf("%d ", *(vetor + i));
    }

    return 0;
}