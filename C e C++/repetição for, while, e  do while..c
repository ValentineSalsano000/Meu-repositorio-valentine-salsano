#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    printf("Usando for:\n");
    for (i = 1; i <= 100; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    printf("Usando while:\n");
    i = 1;
    while (i <= 100) {
        printf("%d ", i);
        i++;
    }
    printf("\n\n");

    
    printf("Usando do-while:\n");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 100);
    printf("\n");

    return 0;
}

