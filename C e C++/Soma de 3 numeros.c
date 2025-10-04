//soma de 3 numeros

#include<stdio.h>
#include<stdlib.h>
int main (){
	int x;
	int y;
	int z;
	int soma;
	
	printf("Digite o primeiro numero\n");
	scanf("%d",&x);
	printf("Digite o segundo numero\n");
	scanf("%d",&y);
	printf("Digite o terceiro numero\n");
	scanf("%d",&z);
	printf("A soma dos numeros e %d", x + y + z);
	
	system("pause");
	return 0;
}
