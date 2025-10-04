#include<stdlib.h>
#include<stdio.h>

int main() {
	int codigo, quantidade;
	float preco = 0.0, total;
	
	 printf("Cardapio:\n");
    printf("100 - Cachorro Quente (R$1.20)\n");
    printf("101 - Bauru Simples (R$1.30)\n");
    printf("102 - Bauru com Ovo (R$1.50)\n");
    printf("103 - Hamburguer (R$1.20)\n");
    printf("104 - Cheeseburguer (R$1.70)\n");
    printf("105 - Suco (R$2.20)\n");
    printf("106 - Refrigerante (R$1.00)\n\n");
	
	printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);
    
    switch(codigo) {
        case 100:
            preco = 1.20;
            break;
        case 101:
            preco = 1.30;
            break;
        case 102:
            preco = 1.50;
            break;
        case 103:
            preco = 1.20;
            break;
        case 104:
            preco = 1.70;
            break;
        case 105:
            preco = 2.20;
            break;
        case 106:
            preco = 1.00;
            break;
        default:
            printf("Código inválido!\n");
            return 1;
    }

   
    total = preco * quantidade;

    printf("Valor a pagar: R$ %.2f\n", total);

    return 0;
}
