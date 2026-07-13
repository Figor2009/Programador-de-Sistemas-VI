#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Criação de personagem
void criarPersonagem(char nome[])
{
	printf("Digite o nome do herói: ");
	scanf(" %49[^\n]", nome);

	printf("Personagem criado com sucesso!\n");
}
//

//Status
void mostrarStatus(char nome[], int vida, int vidaMaxima, int ataque, int defesa, int nivel, int experiencia, int ouro)
{
	printf("\nNome: %s\n", nome);
	printf("\nVida: %d/%d\n", vida, vidaMaxima);
	printf("Ataque: %d\n", ataque);
	printf("Defesa: %d\n", defesa);
	printf("\nNível: %d\n", nivel);
	printf("Experiência: %d\n", experiencia);
	printf("\nOuro: %d\n", ouro);
}
//

//EXPLORAÇÃO GERAL

//Seletor aleatório de eventos na exploração
void explorarMapa (int inventario[], int *ouro, int *quantidadeItens, int *vida)
{
	int escolhamapa = 0;
	escolhamapa = rand() % 5 + 1;

	if (escolhamapa == 1)
	{
		printf("WIP Encontar monstro\n");
	}
	else if (escolhamapa == 2)
	{
		int ouroganho = 0;
		printf("Você encontrou um baú!\n");
		ouroganho = rand() % 400 + 100;
		printf("+%d moedas de ouro!\n", ouroganho);
		*ouro += ouroganho;
	}
	else if (escolhamapa == 3)
	{
		int escolhapocao = 0;
		escolhapocao = rand() % 3 + 1;
		if (*quantidadeItens < 20)
		{
			if (escolhapocao == 1)
			{
				printf("Você encontrou uma Poção Pequena!\n");
				printf("Poção Pequena adicionada ao inventário!\n");

				inventario[*quantidadeItens] = 1;
			}
			else if (escolhapocao == 2)
			{
				printf("Você encontrou uma Poção Grande!\n");
				printf("Poção Grande adicionada ao inventário!\n");

				inventario[*quantidadeItens] = 2;
			}
			else
			{
				printf("Você encontrou uma Poção MAX!!(Sortudo...)\n");
				printf("Poção MAX adicionada ao inventário!\n");

				inventario[*quantidadeItens] = 3;
			}

			(*quantidadeItens)++;
		}
		else
		{
			printf("Você encontrou uma poção, porém seu inventário já estava cheio!\n");
		}
	}
	else if (escolhamapa == 4)
	{
		int danoarmadilha = 0;
		printf("Você caiu em uma armadilha! Gyahahahaha!!!\n");
		danoarmadilha = rand() % 30 + 1;
		printf("Perdeu %d de vida\n", danoarmadilha);
		*vida -= danoarmadilha;

		if (*vida < 0)
		{
			*vida = 0;
		}
	}
	else
	{
		printf("... mas nada aconteceu...\n");
	}
}


//

//Loja
void loja(int *ouro, int inventario[], int *quantidadeItens, int *ataque, int *defesa)
{
	int opcao;
	int preco = 0;

	do
	{
		printf("-----------------------------------\n");
		printf("                LOJA               \n");
		printf("-----------------------------------\n");
		printf("\n");
		printf("Seu ouro: %d\n", *ouro);
		printf("\n");
		printf("       POÇÕES (Curam sua vida)     \n");
		printf("1 - Poção Pequena (20g)\n");
		printf("2 - Poção Grande (40g)\n");
		printf("3 - Poção MAX (100g)\n");
		printf("\n");
		printf("     ESPADAS (Aumentam seu dano)   \n");
		printf("4 - Espada de Ferro (100g)\n");
		printf("5 - Espada de Titânio (300g)\n");
		printf("6 - Espada de Soulshadder (1000g)\n");
		printf("\n");
		printf("   ARMADURA (Aumentam sua defesa)  \n");
		printf("7 - Molde para Escudo (80g)\n");
		printf("8 - Armadura de Ferro (120g)\n");
		printf("9 - Armadura de Titânio (250g)\n");
		printf("10 - Armadura de Etherium (700g)\n");
		printf("\n");
		printf("11 - Sair da loja\n");

		printf("\nEscolha: ");
		scanf("%d", &opcao);

		switch(opcao)
		{
		case 1:
			preco = 20;
			if(*ouro >= preco && *quantidadeItens < 20)
			{
				*ouro -= preco;
				inventario[*quantidadeItens] = 1;
				(*quantidadeItens)++;
				printf("Poção Pequena comprada!\n");
			}
			break;

		case 2:
			preco = 40;
			if(*ouro >= preco && *quantidadeItens < 20)
			{
				*ouro -= preco;
				inventario[*quantidadeItens] = 2;
				(*quantidadeItens)++;
				printf("Poção Grande comprada!\n");
			}
			break;

		case 3:
			preco = 100;
			if(*ouro >= preco && *quantidadeItens < 20)
			{
				*ouro -= preco;
				inventario[*quantidadeItens] = 3;
				(*quantidadeItens)++;
				printf("Poção MAX comprada!\n");
			}
			break;

		case 4:
			preco = 100;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*ataque += 5;
				printf("Espada de Ferro equipada! Ataque +5\n");
			}
			break;

		case 5:
			preco = 300;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*ataque += 25;
				printf("Espada de Titânio equipada! Ataque +25\n");
			}
			break;

		case 6:
			preco = 1000;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*ataque += 60;
				printf("Soulshadder equipada! Ataque +60\n");
			}
			break;

		case 7:
			preco = 80;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 3;
				printf("Escudo equipado! Defesa +3\n");
			}
			break;

		case 8:
			preco = 120;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 5;
				printf("Armadura de Ferro equipada! Defesa +5\n");
			}
			break;

		case 9:
			preco = 250;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 10;
				printf("Armadura de Titânio equipada! Defesa +10\n");
			}
			break;

		case 10:
			preco = 700;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 40;
				printf("Armadura de Etherium equipada! Defesa +40\n");
			}
			break;

		case 11:
			printf("Saindo da loja...\n");
			break;

		default:
			printf("Opção inválida!\n");
		}

		if(opcao != 11)
		{
			if(*ouro < preco)
				printf("Você não possui ouro suficiente!\n");

			if(*quantidadeItens >= 20 && opcao >=1 && opcao <=3)
				printf("Inventário cheio!\n");
		}

		printf("\n");
	} while(opcao != 11);
}
//

int main()
{
	//escolha do menu
	char escolhamenu;
	//

	srand(time(NULL));

	//status do personagem
	char nome[50] = "InsiraUmNome";

	int vida = 100;
	int vidaMaxima = 100;

	int ataque = 10;
	int defesa = 5;

	int nivel = 1;
	int experiencia = 0;

	int ouro = 50;

	int inventario[20];
	int quantidadeItens = 0;
	//

	do {
		printf("=================================================\n");
		printf("        RPG DE TEXTO - A JORNADA DO HERÓI\n");
		printf("=================================================\n");
		printf("\n1 - Criar Personagem\n");
		printf("2 - Ver Status\n");
		printf("3 - Explorar Mapa\n");
		printf("4 - Loja\n");
		printf("5 - Inventário\n");
		printf("6 - Descansar\n");
		printf("7 - Enfrentar Chefe Final\n");
		printf("0 - Sair\n");
		printf("\nEscolha: ");

		scanf("%s", &escolhamenu);

		switch (escolhamenu) {
		case ('1'):
			criarPersonagem(nome);
			break;

		case ('2'):
			mostrarStatus(nome, vida, vidaMaxima, ataque, defesa, nivel, experiencia, ouro);
			break;

		case ('3'):
			explorarMapa(inventario, &ouro, &quantidadeItens, &vida);
			break;

		case ('4'):
			loja(&ouro, inventario, &quantidadeItens, &ataque, &defesa);
			break;

		case ('5'):
			break;

		case ('6'):
			break;

		case ('7'):
			break;

		case ('0'):
			printf("See you next time, stranger.");
			break;

		default:
			printf("Insira uma escolha válida!\n");
		}

	} while (escolhamenu != '0');

}








