#include <stdlib.h>
#include <stdio.h>

int main() {
    float notas[10][3];
    int i, j;
    int pior1 = 0, pior2 = 0, pior3 = 0;

    printf("Digite as notas dos 10 alunos (3 por aluno):\n");
    for (i = 0; i < 10; i++) {
        printf("Aluno %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("Prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    for (i = 0; i < 10; i++) {
        int pior = 0;
        for (j = 1; j < 3; j++) {
            if (notas[i][j] < notas[i][pior]) {
                pior = j;
            }
        }

        if (pior == 0) pior1++;
        else if (pior == 1) pior2++;
        else pior3++;
    }

    printf("\nNumero de alunos cuja pior nota foi:\n");
    printf("Prova 1: %d\n", pior1);
    printf("Prova 2: %d\n", pior2);
    printf("Prova 3: %d\n", pior3);

    return 0;
}

