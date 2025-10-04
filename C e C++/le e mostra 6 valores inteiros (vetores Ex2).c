#include <stdlib.h>
#include <stdio.h>

int main() {
    int valores[6];
	int i;
	
    printf("Digite 6 numeros inteiros:\n");
    for (i = 0; i < 6; i++) {
        scanf("%d", &valores[i]);
    }

    printf("Valores lidos:\n");
    for (i = 0; i < 6; i++) {
        printf("%d\n", valores[i]);
    }

    return 0;
}

