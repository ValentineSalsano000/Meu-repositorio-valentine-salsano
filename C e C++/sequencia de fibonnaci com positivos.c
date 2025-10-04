#include <stdio.h>
#include <stdlib.h>

int main () {
	int limite;
	int a = 0, b = 1, c;
	
	printf("Digite um numero positivo : \n");
	scanf("%d", &limite);
	
	if (limite < 0){
	printf("Numero invalido \n");
		
}
	
	printf("Sequencia de Fibonacci ate passar %d:\n", limite);
	printf("%d ", a);
    
  c = a + b;

    while (c <= limite) {
	printf("%d ", c);
    a = b;
    b = c;
    c = a + b;
    }

    printf("\n");
    return 0;
}
