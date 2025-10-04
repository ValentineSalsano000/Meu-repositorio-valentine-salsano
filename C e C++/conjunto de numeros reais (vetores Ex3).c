#include <stdlib.h>
#include <stdio.h>

int main() {
    float reais[10];
    float quadrados[10];
	int i;
	
    printf("Digite 10 numeros reais:\n");
    for (i = 0; i < 10; i++) {
        scanf("%f", &reais[i]);
        quadrados[i] = reais[i] * reais[i];
    }

    printf("Valores originais e seus quadrados:\n");
    for (i = 0; i < 10; i++) {
        printf("Valor: %.2f  |  Quadrado: %.2f\n", reais[i], quadrados[i]);
    }

    return 0;
}

