#include <stdio.h>
#include <stdlib.h>

void feedback(int quantity, int *gender, int *view)
{
    int countF = 0, countM = 0;
    int xx = 0, xy = 0;

    for (int i = 0; i < quantity; i++)
    {
        if (gender[i] == 2 && view[i] == 1)
        {
            countF++;
        }
        else if (gender[i] == 1 && view[i] == 2)
        {
            countM++;
        }
    }

    xx = (countM * 100) / quantity;
    xy = (countF * 100) / quantity;
    printf("porcentagem de pessoas do sexo masculino que nao gostaram: %d%%.\n\n", xx);
    printf("porcentagem de pessoas do sexo feminino que gostaram: %d%%.", xy);
}

int main(void)
{
    int *genderArr, *viewArr;
    genderArr = (int *)malloc(5 * sizeof(int));
    viewArr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("Qual o genero do %d entrevistado? \n1. M \n2. F\ngenero: ", i + 1);
        scanf("%d", &genderArr[i]);

        printf("\nVoce gostou do novo produto? \n1 - sim\n2 - nao\nresponta: ");
        scanf("%d", &viewArr[i]);
    }

    feedback(5, genderArr, viewArr);

    free(genderArr);
    free(viewArr);

    return 0;
}