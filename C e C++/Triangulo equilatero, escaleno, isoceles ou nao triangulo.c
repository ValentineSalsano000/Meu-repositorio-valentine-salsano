#include<stdio.h>
#include<stdlib.h>


int main () {
	int A, B, C;
	
printf ("Insira o valor de A : ");
scanf("%d", &A);
printf ("Insira o valor de B : ");
scanf("%d", &B);
printf ("Insira o valor de C : ");
scanf("%d", &C);
if (A<B+C && B<A+C && C<A+B){
		if (A==C && A==B){
			printf("Triangulo Equilatero \n");
			}
			else {
				if (A==B || B==C || A==C) {
					printf("Triangulo isoceles \n");
			}
		else printf("Triangulo escaleno \n");
}} else {
	printf ("Nao e um triangulo \n");
}
	system ("pause");
	return 0;
}
	





















