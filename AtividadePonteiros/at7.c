#include <stdio.h>

int main()
{
	int * p, *p2, *p3;

	int num, num2, num3;

	printf("Digite A: ");
	scanf("%d", &num);
	printf("Digite B: ");
	scanf("%d", &num2);
	printf("Digite C: ");
	scanf("%d", &num3);

	p = &num;

	p2 = &num2;
	
	p3 = &num3;
	
	printf("\nVariavel A: %d\n", num);
	printf("Endereco A: %x\n", &num);
	printf("Valor ponteiro A: %d\n\n", *p);


    printf("Variavel B: %d\n", num2);
	printf("Endereco B: %x\n", &num2);
	printf("Valor ponteiro B: %d\n\n", *p2);
	
	printf("Variavel C: %d\n", num3);
	printf("Endereco C: %x\n", &num3);
	printf("Valor ponteiro C: %d\n", *p3);
	
	return 0;

}