#include <stdlib.h>
#include <stdio.h>

int main() {
    double salario = 2000.0;
    double percentualAumento = 0.015;
    int anoInicial = 1996;
    int anoFinal;
    int ano;

    printf("Digite o ano final para calcular o salario (>= 1996): ");
    scanf("%d", &anoFinal);

    if (anoFinal < 1996) {
        printf("Ano invalido! O ano deve ser maior ou igual a 1996.\n");
        return 0;
    }

    salario += salario * percentualAumento;

    for (ano = 1997; ano <= anoFinal; ano++) {
        percentualAumento *= 2;
        salario += salario * percentualAumento;
    }

    printf("Salario final em %d: R$ %.2f\n", anoFinal, salario);
    return 0;
}

