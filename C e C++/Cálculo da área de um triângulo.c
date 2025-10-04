#include <stdlib.h>
#include <stdio.h>

int main() {
    float base, altura, area;

    printf("Digite a base do triangulo: ");
    scanf("%f", &base);

    if (base <= 0) {
        printf("Base invalida. Deve ser maior que 0.\n");
        return 0;
    }

    printf("Digite a altura do triangulo: ");
    scanf("%f", &altura);

    if (altura <= 0) {
        printf("Altura invalida. Deve ser maior que 0.\n");
        return 0;
    }

    area = (base * altura) / 2;
    printf("Area do triangulo: %.2f\n", area);
    return 0;
}
