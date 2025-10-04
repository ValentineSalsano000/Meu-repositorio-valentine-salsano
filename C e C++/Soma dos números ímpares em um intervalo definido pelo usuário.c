#include <stdlib.h>
#include <stdio.h>

int main() {
    int inicio, fim, soma = 0;
	int i;
	
    printf("Digite o valor inicial e valor final: ");
    scanf("%d %d", &inicio, &fim);

    if (inicio > fim) {
        printf("Intervalo de valores invalido\n");
        return 0;
    }

    for (i = inicio; i <= fim; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }

    printf("Soma dos impares neste intervalo: %d\n", soma);
    return 0;
}

