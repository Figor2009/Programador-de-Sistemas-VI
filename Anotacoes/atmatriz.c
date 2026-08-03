#include <stdio.h>

int main()
{
	//     //EX1
	// 	int num[3][3];

	// 	for(int i = 0; i < 3; i++)
	// 	{
	// 		for(int j = 0; j < 3; j++)
	// 		{
	// 			printf("Digite a posição %d de %d: ", i, j);
	// 			scanf("%d", &num[i][j]);
	// 		}
	// 	}
	// 	for(int i = 0; i < 3; i++)
	// 	{
	// 		for(int j = 0; j < 3; j++)
	// 		{
	// 			printf("%d ", num[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	//COMO Q EU FIZ ISSO
	// 	return 0;

	//EX2
	// 	int num[4][4];
	// 	int resultado = 0;

	// 	for(int i = 0; i < 4; i++)
	// 	{
	// 		for(int j = 0; j < 4; j++)
	// 		{
	// 			printf("Digite o número %d: ", i);
	// 			scanf("%d", &num[i][j]);
	// 		}
	// 	}
	// 	for(int i = 0; i < 4; i++)
	// 	{
	// 		for(int j = 0; j < 4; j++)
	// 		{
	// 			resultado = resultado + num[i][j];
	// 		}
	// 	}
	// 	printf("%d", resultado);
	// 	return 0;

	//EX3
	//     int num[5][5];
	// 	int maior = -9999;
	//     int linMai = 0;
	//     int colMai = 0;
	// 	int menor = 9999;
	// 	int linMen = 0;
	//     int colMen = 0;

	// 	for(int i = 0; i < 5; i++)
	// 	{
	// 		for(int j = 0; j < 5; j++)
	// 		{
	// 			printf("Digite o número %d de %d: ", i, j);
	// 			scanf("%d", &num[i][j]);
	// 		}
	// 	}
	// 	for(int i = 0; i < 5; i++)
	// 	{
	// 		for(int j = 0; j < 5; j++)
	// 		{
	// 			if(num[i][j] >= maior)
	// 			{
	// 			    maior = num[i][j];
	// 			    linMai = i;
	// 			    colMai = j;
	// 			}
	// 			if(num[i][j] <= menor)
	// 			{
	// 			    menor = num[i][j];
	// 			    linMen = i;
	// 			    colMen = j;
	// 			}
	// 		}
	// 	}
	// 	printf("%d Menor \n", menor);
	// 	printf("%dx%d Posição \n", linMen, colMen);
	// 	printf("%d Maior \n", maior);
	// 	printf("%dx%d Posição \n", linMai, colMai);
	// 	return 0;

	//EX4
	int num[3][4];
	int resultado = 0;


	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("\nDigite o número %d de %d: ", i, j);
			scanf("%d", &num[i][j]);
		}
	}
	for(int i = 0; i < 3; i++)
	{
		resultado = resultado + num[i][j];

		for(int j = 0; j < 4; j++)
		{
			resultado = num[i][j] + num[i][j];
			printf("%d ", resultado);
		}
	}
	return 0;
}