#include <stdio.h>
#include <stdlib.h>

int main() {
    int hora_chegada, min_chegada, hora_partida, min_partida;
    int chegada_total, partida_total, diferenca;
    int horas_pagar;
    float preco;

    printf("Digite a hora e minutos de chegada (hora minuto): ");
    scanf("%d %d", &hora_chegada, &min_chegada);

    printf("Digite a hora e minutos de partida (hora minuto): ");
    scanf("%d %d", &hora_partida, &min_partida);

    chegada_total = hora_chegada * 60 + min_chegada;
    partida_total = hora_partida * 60 + min_partida;

    if (partida_total <= chegada_total) {
        partida_total += 24 * 60; 
    }

    diferenca = partida_total - chegada_total;
    
    horas_pagar = (diferenca + 59) / 60; 
  
    if (horas_pagar <= 2) {
        preco = horas_pagar * 1.00;
    } else if (horas_pagar <= 4) {
        preco = 2 * 1.00 + (horas_pagar - 2) * 1.40;
    } else {
        preco = 2 * 1.00 + 2 * 1.40 + (horas_pagar - 4) * 2.00;
    }

    printf("Valor a pagar: R$ %.2f\n", preco);

    return 0;
}

