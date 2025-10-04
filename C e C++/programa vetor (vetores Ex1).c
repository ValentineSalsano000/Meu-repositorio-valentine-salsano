#include <stdlib.h>
#include <stdio.h>

int main() {
    int A[6];
    int soma;
    int i;

    A[0] = 1;
    A[1] = 0;
    A[2] = 5;
    A[3] = -2;
    A[4] = -5;
    A[5] = 7;

    soma = A[0] + A[1] + A[5];
    printf("Soma de A[0], A[1] e A[5] = %d\n", soma);

    A[4] = 100;

    printf("Valores atuais do vetor A:\n");
    i = 0;
    while (i < 6) {
        printf("A[%d] = %d\n", i, A[i]);
        i++;
    }

    return 0;
}

