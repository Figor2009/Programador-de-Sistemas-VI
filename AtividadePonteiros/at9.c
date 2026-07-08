#include <stdio.h>

int main()
{
	double * p;

	double num;

	printf("Digite seu salario: ");
	scanf("%lf", &num);

    printf("\nSalario: %.2lf\n", num);
    
	p = &num;

    *p = *p + (*p * 0.1);
	
	printf("\nNovo salario: %.2lf\n", num);
	
	return 0;

}