#include<stdio.h>

int main ()
{
	char nome [24];
	int placar = 0;
	char res;
	
	printf("=============================\n");
	printf("Bem vindo ao jogo da revisao!\n");
	printf("=============================\n");
	
	printf("Informe o seu nome: \n");
	scanf("%[^\n]", nome);
	
	printf("Pergunta 01 - Qual eh a diferenca entre os tipos de variaveis float e double?\n");
	printf("(A) Sao iguais, apenas mudando o nome\n");
	printf("(B) Ambos usam 4 bits de memoria\n");
	printf("(C) O double ocupa 8 bits enquanto o float ocupa 4 bits\n");
	printf("(D) Nenhuma das anteriores\n");
	
	scanf(" %c", &res);
	if (res == 'C' || res == 'c')
	{
		placar++;
	}
	
	printf("Pergunta 02 - Qual estrutura devo usar quando nao sei o numero de iteracoes do meu laco?\n");
	printf("(A) Estrutura FOR\n");
	printf("(B) Estrutura WHILE\n");
	printf("(C) Estrutura DO WHILE\n");
	printf("(D) Estrutura IF\n");
	
	scanf(" %c", &res);
	if (res == 'B' || res == 'b')
	{
		placar++;
	}
	
	printf("Pergunta 03 - Para que serve o metodo de Newthon-Ralphson?\n");
	printf("(A) Para dificultar a nossa VIDA.\n");
	printf("(B) Para calcular a distancia entre dois pontos\n");
	printf("(C) Para aproximar polinomios e encontrar suas raizes\n");
	printf("(D) Para usar o teclado do computador como input\n");
	
	scanf(" %c", &res);
	if (res == 'C' || res == 'c')
	{
		placar++;
	}
	
	printf("Pergunta 04 - Dada a proposicao P^Q, qual seria a tabela verdade?\n");
	printf("(A) ===============\n");
	printf("    = P | Q | P^Q =\n");
	printf("    = 0 | 0 |  0  =\n");
	printf("    = 0 | 1 |  0  =\n");
	printf("    = 1 | 0 |  0  =\n");
	printf("    = 1 | 1 |  1  =\n");
	printf("    ===============\n");
	
	printf("(B) ===============\n");
	printf("    = P | Q | P^Q =\n");
	printf("    = 0 | 0 |  1  =\n");
	printf("    = 0 | 1 |  0  =\n");
	printf("    = 1 | 0 |  0  =\n");
	printf("    = 1 | 1 |  1  =\n");
	printf("    ===============\n");
	
	printf("(C) ===============\n");
	printf("    = P | Q | P^Q =\n");
	printf("    = 0 | 0 |  0  =\n");
	printf("    = 0 | 1 |  1  =\n");
	printf("    = 1 | 0 |  1  =\n");
	printf("    = 1 | 1 |  0  =\n");
	printf("    ===============\n");
	
	printf("(D) ===============\n");
	printf("    = P | Q | P^Q =\n");
	printf("    = 0 | 0 |  0  =\n");
	printf("    = 0 | 1 |  0  =\n");
	printf("    = 1 | 0 |  1  =\n");
	printf("    = 1 | 1 |  1  =\n");
	printf("    ===============\n");
	
	scanf(" %c", &res);
	if (res == 'A' || res == 'a')
	{
		placar++;
	}
	
	printf("Pergunta 05 - Para que serve a biblioteca stdio.h?\n");
	printf("(A) Para podermos usar o mouse.\n");
	printf("(B) Para calcular somas matematicas\n");
	printf("(C) Para podermos usar o teclado\n");
	printf("(D) Para utilizarmos as funcoes de entrada e saida\n");
	
	scanf(" %c", &res);
	if (res == 'D' || res == 'd')
	{
		placar++;
	}
	
	printf("Parabens %s! Sua pontuacao eh de %d pontos!", nome, placar);
	
}