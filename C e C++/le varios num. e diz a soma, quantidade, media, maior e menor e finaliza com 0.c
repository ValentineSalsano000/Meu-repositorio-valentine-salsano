#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, soma = 0, quantidade = 0;
    int maior, menor;
    float media;

    printf("Digite numeros inteiros (0 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        soma += numero;
        quantidade++;

        if (quantidade == 1) {
            maior = menor = numero;
        } else {
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }
    }

    if (quantidade > 0) {
        media = (float)soma / quantidade;
        printf("\nResultado:\n");
        printf("Soma dos numeros: %d\n", soma);
        printf("Quantidade de numeros: %d\n", quantidade);
        printf("Media: %.2f\n", media);
        printf("Maior numero: %d\n", maior);
        printf("Menor numero: %d\n", menor);
    } else {
        printf("\nNenhum numero foi digitado.\n");
    }

    return 0;
}

