#include <stdio.h>

int main()
{
	int * p;
	int * p2;

	int num, num2;

	printf("Digite 1: ");
	scanf("%d", &num);
	printf("Digite 2: ");
	scanf("%d", &num2);

	p = &num;

	p2 = &num2;


	printf("Soma = %d\n", *p + *p2);

	return 0;

}