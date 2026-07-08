#include <stdio.h>

int main()
{
	int * p, *p2;

	int num, num2;

	printf("Numero 1: ");
	scanf("%d", &num);
	printf("Numero 2: ");
	scanf("%d", &num2);

	p = &num;

	p2 = &num2;

	*p = *p * 2;

	*p2 = *p2 / 2;

	printf("\nResultado\n");
	printf("Numero 1 = %d\n", *p);
	printf("Numero 2 = %d\n", *p2);

	return 0;

}