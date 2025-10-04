#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float valor;

    while (1) {
        printf("Digite um valor positivo (0 ou negativo para sair): ");
        scanf("%f", &valor);

        if (valor <= 0) {
            break;
        }

        printf("Valor: %.2f\n", valor);
        printf("Quadrado: %.2f\n", valor * valor);
        printf("Cubo: %.2f\n", valor * valor * valor);
        printf("Raiz quadrada: %.2f\n\n", sqrt(valor));
    }

    return 0;
}
