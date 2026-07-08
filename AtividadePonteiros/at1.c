#include <stdio.h>

int main()
{
    int * ptr;
    
    int numero = 50;
    
    ptr = &numero;
    
    printf("Valor de numero: %d\n", numero);
    printf("Endereco de numero: %x\n", &numero);
    printf("Valor armazenado em ptr: %x\n", ptr);
	printf("Conteudo apontado por ptr: %d\n", *ptr);

	return 0;
	
}