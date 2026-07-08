#include <stdio.h>

int main()
{
	int * p;
	int * p2;

	int num, num2;

	printf("Digite A: ");
	scanf("%d", &num);
	printf("Digite B: ");
	scanf("%d", &num2);

	p = &num;

	p2 = &num2;

	if (*p > *p2) {
		printf("Maior valor: %d\n", num);
	}
	else
	{
		printf("Maior valor: %d\n", num2);
	}

	return 0;

}