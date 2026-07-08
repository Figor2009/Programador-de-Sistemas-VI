#include <stdio.h>

int main()
{
    int * p;
    
    int idade = 20;
    
    p = &idade;
    
    printf("Valor inicial: %d\n", idade);
    
    *p = 25;
    
    printf("Valor final: %d\n", idade);

	return 0;
	
}