#include <stdio.h>

int main()
{
	int * p;

	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);

	p = &num;
	
	*p = (*p) * 2;

	printf("Dobro: %d\n", num);

	return 0;

}