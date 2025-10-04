#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    float a,b;

    do {
        printf("1 - Adicao\n");
        printf("2 - subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Sair\n");
        printf("\nEscolha uma opcao:\n");
		scanf("%d", &opcao);
		
		if (opcao >= 1 && opcao <= 4){
		printf("Digite o primeiro numero: ");
            scanf("%f", &a);
            printf("Digite o segundo numero: ");
            scanf("%f", &b);		
		}

    switch (opcao) {
            case 1:
                printf("Resultado: %.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case 2:
                printf("Resultado: %.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case 3:
                printf("Resultado: %.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case 4:
                if (b != 0) {
                    printf("Resultado: %.2f / %.2f = %.2f\n", a, b, a / b);
                } else {
                    printf("Erro: divisao por zero nao permitida!\n");
                }
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}    
