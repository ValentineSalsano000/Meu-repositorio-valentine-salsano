#include<stdio.h>
#include<stdlib.h>

int main () {
	int idade,tempoServico;
	
printf ("Digite sua idade : ");
	scanf("%d", &idade);
printf ("Digite seu tempo de serviço (em anos) : ");
	scanf("%d", &tempoServico);
	
	if (idade >= 65 || tempoServico >= 30 || (idade >= 60 && tempoServico >= 25)) {
printf("O trabalhador pode se aposentar.\n");
} else {
        printf("O trabalhador nao pode se aposentar ainda.\n");
    }

    return 0;
}		
