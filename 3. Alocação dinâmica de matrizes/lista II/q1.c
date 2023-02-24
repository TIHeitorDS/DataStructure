#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, count = 0;
    char **mapa;

    printf("Informe a quantidade de linhas: ");
    scanf("%d", &m);
    printf("Informe a quantidade de colunas: ");
    scanf("%d", &n);

    if (m < 1 || n >= 1000) 
    {
        return printf("\nErro!");
    }

    mapa = (char **)malloc(m * sizeof(char *));

    for (int i = 0; i < m; i++)
    {
        mapa[i] = malloc(n * sizeof(char));
    }

    for (int i = 0; i < m; i++)
    {
        printf("Informe os caracteres da %d linha:\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%s", &mapa[i][j]);
        }
        printf("\n");
    }

    for (int linha = 0; linha < m; linha++)
    {
        for (int coluna = 0; coluna < n; coluna++)
        {
            if (linha == 0)
            {
                if (mapa[linha][coluna] == '#' && coluna - 1 < 0) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.')) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha + 1][coluna] == '.')) count++;
                else if (mapa[linha][coluna] == '#' && coluna + 1 == n) count++;
            } 
            else if (linha > 0 && linha < m - 1)
            {
                if ((mapa[linha][coluna] == '#' && coluna - 1 < 0 )|| (mapa[linha][coluna] == '#' && coluna + 1 == n)) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.')) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha + 1][coluna] == '.') || (mapa[linha][coluna] == '#' && mapa[linha - 1][coluna] == '.')) count++;
            }
            else if (linha == m - 1)
            {
                if ((mapa[linha][coluna] == '#' && coluna - 1 < 0) || (mapa[linha][coluna] == '#' && linha + 1  == m)) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.')) count++;
                else if ((mapa[linha][coluna] == '#' && mapa[linha - 1][coluna] == '.')) count++;
                else if ((mapa[linha][coluna] == '#' && coluna + 1 == n)) count++;
            }
            
        }
    }

    printf("\nQuantidade de quadrados do territorio que fazem parte da costa da Nlogonia: %d.", count);

    for (int i = 0; i < m; i++)
    {
        free(mapa[i]);
    }

    free(mapa);
    return 0;
}