#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int tentativas;
} Jogador;

void inicializarTabuleiro(char tabuleiro [8][8])
{
    int i, j = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabuleiro[i][j] = '~';
        }
    }
}

void mostrarTabuleiro(char tabuleiro [8][8])
{
    int i, j;

	printf("\n   ");
	for (j = 0; j < 8; j++)
	{
		printf("%d ", j);
	}

	printf("\n");

	for (i = 0; i < 8; i++)
	{
		printf("%d  ", i);

		for (j = 0; j < 8; j++)
		{
			printf("%c ", tabuleiro[i][j]);
		}

		printf("\n");
	}
}

void posicionarNavios(char tabuleiro [8][8])
{
    tabuleiro[1][2] = 'N';
    tabuleiro[3][5] = 'N';
    tabuleiro[6][1] = 'N';
}

int realizarAtaque(char tabuleiro [8][8], int *destruidos)
{
    int i, j, linha, coluna = 0;
    printf("\nInsira a linha para atacar: ");
    scanf("%d", &linha);
    printf("\nAgora insira a coluna: ");
    scanf("%d", &coluna);

    
    if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8)
    {
        printf("Posição não encontrada");
        return 0;
    }
    if (tabuleiro[linha][coluna] == 'N')
	{
		printf("ACERTOU!\n");
		tabuleiro[linha][coluna] = 'X';
		(*destruidos)++;
	}
	else if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O')
	{
		printf("Você já tentou essa posição.\n");
	}
	else
	{
		printf("Nenhum tesouro encontrado!\n");
		tabuleiro[linha][coluna] = 'O';
	}
    
    return 1;
}

void salvarResultado(Jogador jogador)
{
    FILE *arquivo = fopen("historico.txt", "a");

	if (arquivo == NULL)
	{
		printf("Cade o arquivo??\n");
		return;
	}

	fprintf(arquivo, "%s | %d tentativas\n", jogador.nome, jogador.tentativas);

	fclose(arquivo);
}

void lerResultado(Jogador jogador)
{
    FILE *arquivo = fopen("historico.txt", "r");

	if (arquivo == NULL)
	{
		printf("Cade o arquivo??\n");
		return;
	}
    else
    {
        printf("Arquivo aberto com sucesso!\n");

	    char linha[256];

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            printf("%s", linha);
        }
	    fclose(arquivo);
    }
}

int main()
{
    char tabuleiro [8][8];
    Jogador jogador;
    int destruidos = 0;
    int * nd;

    nd = &destruidos;

    printf("===============================\n");
    printf("          Batalha Naval        \n");
    printf("- - - - - - - - - - - - - - - -\n");
    lerResultado(jogador);
    printf("- - - - - - - - - - - - - - - -\n");
    printf("Insira seu nome: ");
    scanf("%s", jogador.nome);
    printf("%s, prepare-se para a batalha.\n", jogador.nome);
    printf("===============================\n");

    jogador.tentativas = 0;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    do{
        mostrarTabuleiro(tabuleiro);
        realizarAtaque(tabuleiro, &destruidos);
        jogador.tentativas++;

    } while (destruidos < 3);

    printf("\nParabéns!\n");
	printf("Você encontrou todos os navios em %d tentativas.\n", jogador.tentativas);

    salvarResultado(jogador);
    

    return 0;
}