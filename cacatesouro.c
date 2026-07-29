#include <stdio.h>

#define TAM 5
#define TESOUROS 3

typedef struct
{
	char nome[20];
	int tentativas;
} Jogador;

void initmapa(char mapa[TAM][TAM])
{
	int i, j;

	for (i = 0; i < TAM; i++)
	{
		for (j = 0; j < TAM; j++)
		{
			mapa[i][j] = '#';
		}
	}
}

void mostrarmapa(char mapa[TAM][TAM])
{
	int i, j;

	printf("\n   ");
	for (j = 0; j < TAM; j++)
	{
		printf("%d ", j);
	}

	printf("\n");

	for (i = 0; i < TAM; i++)
	{
		printf("%d  ", i);

		for (j = 0; j < TAM; j++)
		{
			printf("%c ", mapa[i][j]);
		}

		printf("\n");
	}
}

void posicionartesouros(char mapa[TAM][TAM])
{
	mapa[3][1] = 'T';
	mapa[4][0] = 'T';
	mapa[3][2] = 'T';
}

int procurartesouros(char mapa[TAM][TAM], int *encontrados)
{
	int linha, coluna;

	printf("\nLinha: ");
	scanf("%d", &linha);

	printf("Coluna: ");
	scanf("%d", &coluna);

	if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
	{
		printf("Posição inválida!\n");
		return 0;
	}

	if (mapa[linha][coluna] == 'T')
	{
		printf("VOCÊ ENCONTROU UM TESOURO!\n");
		mapa[linha][coluna] = 'X';
		(*encontrados)++;
	}
	else if (mapa[linha][coluna] == 'X' || mapa[linha][coluna] == 'O')
	{
		printf("Você já tentou essa posição.\n");
	}
	else
	{
		printf("Nenhum tesouro encontrado!\n");
		mapa[linha][coluna] = 'O';
	}

	return 1;
}

void salvar(Jogador jogador)
{
	FILE *arquivo = fopen("historico.txt", "a");

	if (arquivo == NULL)
	{
		printf("NAO ENCONTREI O ARQUIVO!!!!!!!!!!!\n");
		return;
	}

	fprintf(arquivo, "%s | %d tentativas\n", jogador.nome, jogador.tentativas);

	fclose(arquivo);
}

int main()
{
	char mapa[TAM][TAM];
	Jogador jogador;
	int encontrados = 0;

	printf("----- Bem-vindo ao caça ao tesouro -----\n");
	printf("Informe seu nome: ");
	scanf("%s", jogador.nome);

	jogador.tentativas = 0;

	initmapa(mapa);
	posicionartesouros(mapa);

	do
	{
		mostrarmapa(mapa);
		procurartesouros(mapa, &encontrados);
		jogador.tentativas++;

	} while (encontrados < TESOUROS);

	printf("\nParabéns, %s!\n", jogador.nome);
	printf("Você encontrou todos os %d tesouros em %d tentativas.\n", TESOUROS, jogador.tentativas);

	salvar(jogador);

	return 0;
}