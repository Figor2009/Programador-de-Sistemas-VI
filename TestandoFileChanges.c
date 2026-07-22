#include <stdio.h>

int main()
{
	FILE *arquivo;
	
	char palavra[50];
	double idade = 0.0;
	double total = 0.0;
	
	arquivo = fopen("Testing.txt", "a");
	
	if (arquivo == NULL)
	{
		printf("ERROR!");
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
		
		for (int i = 0; i < 2; i++)
		{
			printf("Escreva seu nome: \n");
			scanf("%s", palavra);
			printf("Escreva sua idade: \n");
			scanf("%lf", &idade);
			
			fprintf(arquivo, "%s\n%lf\n", palavra,idade);
		}
    }
	
	fclose(arquivo);
	
	arquivo = fopen("Testing.txt", "r");
	
	if (arquivo == NULL)
	{
		printf("ERROR!");
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
		
		for (int i = 0; i < 2; i++)
		{
			fscanf(arquivo,"%s\n%lf", palavra, &idade);
			printf("%s\n%lf\n", palavra, idade);
		}
    }
	fclose(arquivo);
	 
	return 0;
}