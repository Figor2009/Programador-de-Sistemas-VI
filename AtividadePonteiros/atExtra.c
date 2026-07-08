#include <stdio.h>

int main()
{
	int *p, *p2, *p3, *p4;

	int num, num2, num3, num4;

	printf("Numero 1: ");
	scanf("%d", &num);
	printf("Numero 2: ");
	scanf("%d", &num2);
	printf("Numero 3: ");
	scanf("%d", &num3);
	printf("Numero 4: ");
	scanf("%d", &num4);

	p = &num;

	p2 = &num2;
	
	p3 = &num3;

	p4 = &num4;

    int maior = *p;

    if (*p2 > maior)
        maior = *p2;
    if (*p3 > maior)
        maior = *p3;
    if (*p4 > maior)
        maior = *p4;

    int menor = *p;

    if (*p2 < menor)
        menor = *p2;
    if (*p3 < menor)
        menor = *p3;
    if (*p4 < menor)
        menor = *p4;

    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Soma: %d\n", *p + *p2 + *p3 + *p4);
    
	return 0;

}