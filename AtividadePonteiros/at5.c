#include <stdio.h>

int main()
{
	int * p;
	int * p2;

	int num, num2, c;

    printf("Antes:\n");
	printf("A = ");
	scanf("%d", &num);
	printf("B = ");
	scanf("%d", &num2);

	p = &num;
	p2 = &num2;
	
	c = *p;
	*p = *p2;
	*p2 = c;
	
	printf("\nDepois:\n");
	printf("A = %d\n", num);
	printf("B = %d\n", num2);

	return 0;

}