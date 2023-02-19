#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantityOfStudents = 10, quantityOfQuestions, aux = 0, aux2, count, q, approved = 0;
    float result;
    char *correctAnswer, *answerOfStudens;

    printf("Informe a quantidade de questoes: ");
    scanf("%d", &quantityOfQuestions);

    aux2 = quantityOfQuestions;

    correctAnswer = (char*) malloc(quantityOfQuestions * sizeof(char));
    answerOfStudens = (char*) malloc(quantityOfQuestions * quantityOfStudents * sizeof(char));

    if (correctAnswer == NULL || answerOfStudens == NULL) {
        printf("Memoria insuficiente!");
        exit(1);
    }

    for (int i = 0; i < quantityOfQuestions; i++) {
        printf("Informe a resposta correta da %d questao: ", i + 1);
        scanf("%s", (correctAnswer + i));
    }

    for (int j = 0; j < quantityOfStudents; j++) {
        printf("Informe as alternativas marcadas pelo %d estudante:\n", j + 1);
        for (int k = aux; k < aux2; k++) {
            scanf("%s", (answerOfStudens + k));
        }

        aux = aux2;
        aux2 += quantityOfQuestions;
    }

    aux = 0;
    aux2 = quantityOfQuestions;
    printf("\n");
    for (int l = 0; l < quantityOfStudents; l++) {
        result = 0;
        count = 0;
        q = 0;

        for (int m = aux; m < aux2; m++) {
            if (*(answerOfStudens + m) == *(correctAnswer + q)) {
                count++;
            }

            q++;
        }

        aux = aux2;
        aux2 += quantityOfQuestions;

        if (10 % quantityOfQuestions == 0) {
            result = (10 / quantityOfQuestions) * count;
        } else {
            if (count % quantityOfQuestions != 0) {
                result = ((float)10 / quantityOfQuestions) * (count % quantityOfQuestions);
            } else {
                result = (count / quantityOfQuestions) * 10;
            }
        } 

        if (result >= 6) {
            approved++;
        }

        printf("A nota do %d aluno e: %.1f\n", l + 1, result);
    }

    approved = (approved * 100) / quantityOfQuestions;
    printf("A porcentagem de alunos aprovados e: %%%d.", approved);

    free(correctAnswer);
    free(answerOfStudens);

    return 0;
}