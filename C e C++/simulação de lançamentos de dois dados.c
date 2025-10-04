#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    int d1, d2;
    int i;

    printf("Digite o numero de lancamentos: ");
    scanf("%d", &n);

    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++) {
        d1 = (rand() % 6) + 1;
        d2 = (rand() % 6) + 1;

        printf("Lancamento %d: D1 = %d, D2 = %d -> ", i + 1, d1, d2);

        if (d1 > d2) {
            printf("D1 > D2\n");
        } else if (d1 < d2) {
            printf("D1 < D2\n");
        } else {
            printf("D1 = D2\n");
        }
    }

    return 0;
}

