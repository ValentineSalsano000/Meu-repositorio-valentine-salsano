#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    float valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Converter km/h para m/s\n");
        printf("2 - Converter m/s para km/h\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira o valor em km/h: ");
                scanf("%f", &valor);
                printf("%.2f km/h = %.2f m/s\n", valor, valor / 3.6);
                break;
            case 2:
                printf("Insira o valor em m/s: ");
                scanf("%f", &valor);
                printf("%.2f m/s = %.2f km/h\n", valor, valor * 3.6);
                break;
            case 3:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    system("pause");
    return 0;
}
