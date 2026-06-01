#include<stdio.h>

int main ()
{
	int num = 0;
	int num2 = 0;
	
	printf("Oi\n");
	
	printf("Digite o valor para o primeiro numero\n");
	scanf("%d", &num);
	
	printf("Digite o valor para o segundo numero\n");
	scanf("%d", &num2);
	
	printf ("O resultado de %d + %d sera de %d", num, num2, num + num2);
	
	
	return (0);
}