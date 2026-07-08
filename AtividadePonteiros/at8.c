#include <stdio.h>

int main()
{
	int * p, *p2;

	int num, num2;

	printf("Digite A: ");
	scanf("%d", &num);
	printf("Digite B: ");
	scanf("%d", &num2);

	p = &num;

	p2 = &num2;
    
	printf("\nSoma: %d\n", *p + *p2);
	printf("Subtracao: %d\n", *p - *p2);
	printf("Multiplicacao: %d\n", *p * *p2);
	printf("Divisao: %d\n", *p / *p2);
	
	return 0;

}