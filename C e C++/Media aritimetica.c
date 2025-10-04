#include<stdio.h>
#include<stdlib.h>

int main (){
	float n1;
	float n2;
	float n3;
	float n4;
	float soma;
	
	printf("Digite o primeiro valor");
		scanf("%f", &n1);
	printf("Digite o segundo valor");
		scanf("%f", &n2);
	printf("Digite o terceiro valor");
		scanf("%f", &n3);
	printf("Digite o quarto valor");
		scanf("%f", &n4);	
			
	printf("A media aritimetica e \n %f", (n1+n2+n3+n4)/4);
	
	system("pause");
	return 0;
	
}
