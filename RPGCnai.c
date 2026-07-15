#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Verifica nivel
void verificarNivel(int *nivel, int *experiencia, int *ataque, int *defesa, int *vidaMaxima, int *vida)
{
	while(*experiencia >= (*nivel) * 100)
	{
		(*nivel)++;

		*ataque += 5;
		*defesa += 3;
		*vidaMaxima += 20;
		*vida = *vidaMaxima; // Recupera toda a vida

		printf("\n=================================\n");
		printf("       VOCÊ SUBIU DE NÍVEL!\n");
		printf("Agora você está no nível %d!\n", *nivel);
		printf("Ataque +5\n");
		printf("Defesa +3\n");
		printf("Vida Máxima +20\n");
		printf("Vida restaurada completamente!\n");
		printf("=================================\n");
	}
}
//

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

void inventariomenu(int inventario[], int *quantidadeItens, int *vida, int vidaMaxima);

void combate(int inventario[], int *quantidadeItens, int *vida, int *vidaMaxima, int *ataque, int *defesa, int *ouro, int *experiencia, int *nivel);
//Seletor aleatório de eventos na exploração
void explorarMapa(int inventario[], int *ouro, int *quantidadeItens, int *vida, int *vidaMaxima, int *ataque, int *defesa, int *experiencia, int *nivel)
{
	int escolhamapa = 0;
	escolhamapa = rand() % 5 + 1;

	if (escolhamapa == 1)
	{
		combate(inventario, quantidadeItens, vida, vidaMaxima, ataque, defesa, ouro, experiencia, nivel);
	}
	else if (escolhamapa == 2)
	{
		int ouroganho = 0;
		printf("Você encontrou um baú!\n");
		ouroganho = rand() % 150;
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


//Combate principal
void combate(int inventario[], int *quantidadeItens, int *vida, int *vidaMaxima, int *ataque, int *defesa, int *ouro, int *experiencia, int *nivel)
{
	char nomeInimigo[20];
	int vidaInimigo, ataqueInimigo;
	int escolha;
	int defendendo = 0;

	// Escolhe o inimigo
	int inimigo = rand() % 7;

	switch(inimigo)
	{
	case 0:
		sprintf(nomeInimigo, "Goblin LVL 1");
		vidaInimigo = 30;
		ataqueInimigo = 10;
		break;

	case 1:
		sprintf(nomeInimigo, "Esqueleto LVL 2");
		vidaInimigo = 50;
		ataqueInimigo = 18;
		break;

	case 2:
		sprintf(nomeInimigo, "Orc LVL 3");
		vidaInimigo = 80;
		ataqueInimigo = 24;
		break;

	case 3:
		sprintf(nomeInimigo, "Lobisomem LVL 4");
		vidaInimigo = 140;
		ataqueInimigo = 40;
		break;

	case 4:
		sprintf(nomeInimigo, "Necromante LVL 5");
		vidaInimigo = 200;
		ataqueInimigo = 50;
		break;

	case 5:
		sprintf(nomeInimigo, "Necromante Superior LVL 6");
		vidaInimigo = 350;
		ataqueInimigo = 80;
		break;

	case 6:
		sprintf(nomeInimigo, "Figura Misteriosa LVL...?");
		vidaInimigo = 480;
		ataqueInimigo = 100;
		break;
	}

	printf("\n=================================\n");
	printf("Um %s apareceu!\n", nomeInimigo);
	printf("=================================\n");

	while(*vida > 0 && vidaInimigo > 0)
	{
		printf("\nSua Vida: %d", *vida);
		printf("\nVida do %s: %d\n", nomeInimigo, vidaInimigo);

		printf("\n1 - Atacar");
		printf("\n2 - Defender");
		printf("\n3 - Fugir");
		printf("\n4 - Inventário");
		printf("\nEscolha: ");
		scanf("%d", &escolha);

		defendendo = 0;

		switch(escolha)
		{
		case 1:
		{
			int dano = *ataque;
			vidaInimigo -= dano;

			if(vidaInimigo < 0)
				vidaInimigo = 0;

			printf("\nVocê atacou dando %d de dano!\n", dano);
			break;
		}

		case 2:
			defendendo = 1;
			printf("\nVocê usou defesa e revidou!\n");
			int dano = *ataque / 2;
			vidaInimigo -= dano;
			break;

		case 3:
			if(rand() % 2 == 0)
			{
				printf("\nVocê conseguiu fugir!\n");
				return;
			}
			else
			{
				printf("\nVocê tentou fugir, mas falhou!\n");
			}
			break;

		case 4:
		{
			inventariomenu(inventario, quantidadeItens, vida, *vidaMaxima);

			if(*vida <= 0)
				return;
				
			break;
		}

		default:
			printf("\nOpção inválida!\n");
			continue;
		}

		// Turno do inimigo
		if(vidaInimigo > 0)
		{
			int dano = ataqueInimigo - *defesa;

			if(dano < 1)
				dano = 1;

			if(defendendo)
				dano /= 2;

			if(dano < 1)
				dano = 1;

			*vida -= dano;

			if(*vida < 0)
				*vida = 0;

			printf("%s atacou e causou %d de dano!\n", nomeInimigo, dano);
		}
	}

	if(*vida <= 0)
	{
		printf("\nVocê foi derrotado pelo %s...\n", nomeInimigo);
	}
	else
	{
		int recompensaOuro;
		int recompensaXP;

		if(inimigo == 0)//Gob
		{
			recompensaOuro = 30;
			recompensaXP = 15;
		}
		else if(inimigo == 1)//Skel
		{
			recompensaOuro = 65;
			recompensaXP = 30;
		}
		else if(inimigo == 2)//Orc
		{
			recompensaOuro = 100;
			recompensaXP = 60;
		}
		else if(inimigo == 3)//Lobisomem
		{
			recompensaOuro = 180;
			recompensaXP = 100;
		}
		else if(inimigo == 4)//Nec
		{
			recompensaOuro = 300;
			recompensaXP = 210;
		}
		else if(inimigo == 5)//NecEX
		{
			recompensaOuro = 500;
			recompensaXP = 300;
		}
		else//MisFig
		{
			recompensaOuro = 1800;
			recompensaXP = 1000;
		}

		printf("\nVocê derrotou o %s!\n", nomeInimigo);
		printf("Ganhou %d de ouro!\n", recompensaOuro);
		printf("Ganhou %d de experiência!\n", recompensaXP);

		*ouro += recompensaOuro;
		*experiencia += recompensaXP;

		verificarNivel(nivel, experiencia, ataque, defesa, vidaMaxima, vida);
	}
}
//

//CHEFE FINAL
void chefeFinal(int inventario[], int *quantidadeItens, int *vida, int *vidaMaxima, int *ataque, int *defesa, int *ouro, int *experiencia, int *nivel)
{
	if(*nivel < 5)
	{
		printf("\n=====================================\n");
		printf("Você precisa ser pelo menos nível 5\n");
		printf("para desafiar o Chefe Final!\n");
		printf("=====================================\n");
		return;
	}

	char nomeChefe[] = "Dragão das Sombras";
	int vidaChefe = 1300;
	int ataqueChefe = 180;
	int escolha;
	int defendendo;

	printf("\n=====================================\n");
	printf("      CHEFE FINAL, CONTEMPLE!\n");
	printf("        %s surgiu!\n", nomeChefe);
	printf("=====================================\n");

	while(*vida > 0 && vidaChefe > 0)
	{
		printf("\nSua Vida: %d/%d\n", *vida, *vidaMaxima);
		printf("Vida do %s: %d\n", nomeChefe, vidaChefe);

		printf("\n1 - Atacar");
		printf("\n2 - Defender");
		printf("\n3 - Fugir");
		printf("\n4 - Inventário");
		printf("\nEscolha: ");
		scanf("%d", &escolha);

		defendendo = 0;

		switch(escolha)
		{
		case 1:
		{
			int dano = *ataque;

			vidaChefe -= dano;

			if(vidaChefe < 0)
				vidaChefe = 0;

			printf("\nVocê causou %d de dano!\n", dano);
			break;
		}

		case 2:
		{
			defendendo = 1;

			int dano = *ataque / 2;

			vidaChefe -= dano;

			if(vidaChefe < 0)
				vidaChefe = 0;

			printf("\nVocê se defendeu e contra-atacou causando %d de dano!\n", dano);
			break;
		}

		case 3:
		{
			printf("\nVocê não pode fugir! Não agora!\n");
			break;
		}

		case 4:
		{
			inventariomenu(inventario, quantidadeItens, vida, *vidaMaxima);

			if(*vida <= 0)
				return;

			break;
		}

		default:
			printf("Opção inválida!\n");
			continue;
		}


		if(vidaChefe > 0)
		{
			int habilidade = rand() % 100;

			if(habilidade < 25)
			{
				int dano = ataqueChefe + 150 ;

				if(defendendo)
					dano /= 1;

				if(dano < 1)
					dano = 1;

				*vida -= dano;
				
				vidaChefe += dano;

				if(*vida < 0)
					*vida = 0;

				printf("\n%s usou SOULPIERCER!!\n", nomeChefe);
				printf("Você sofreu %d de dano e o chefe recuperou %d de vida!\n", dano, dano);
			}
			else
			{
				int dano = ataqueChefe - *defesa / 2;

				if(defendendo)
					dano /= 2;

				if(dano < 1)
					dano = 1;

				*vida -= dano;

				if(*vida < 0)
					*vida = 0;

				printf("%s atacou causando %d de dano!\n", nomeChefe, dano);
			}
		}
	}

	if(*vida <= 0)
	{
		printf("\n=====================================\n");
		printf("Você foi derrotado...\n");
		printf("GAME OVER\n");
		printf("=====================================\n");
	}
	else
	{
		printf("\n=====================================\n");
		printf("PARABÉNS!\n");
		printf("Você derrotou o %s!\n", nomeChefe);
		printf("O reino foi salvo!\n");
		printf("Você concluiu o jogo!\n");
		printf("=====================================\n");

		*ouro += 2000;
		*experiencia += 2000;

		printf("\nRecompensas recebidas:\n");
		printf("+2000 ouro\n");
		printf("+2000 experiência\n");

		verificarNivel(nivel, experiencia, ataque, defesa, vidaMaxima, vida);
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
		printf("===================================\n");
		printf("                LOJA               \n");
		printf("===================================\n");
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
		printf("10 - Armadura de Etherium (1000g)\n");
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
				*ataque += 20;
				printf("Espada de Titânio equipada! Ataque +20\n");
			}
			break;

		case 6:
			preco = 1000;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*ataque += 80;
				printf("Soulshadder equipada! Ataque +80\n");
			}
			break;

		case 7:
			preco = 80;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 1;
				printf("Escudo equipado! Defesa +1\n");
			}
			break;

		case 8:
			preco = 120;
			if(*ouro >= preco)
			{
				*ouro -= preco;
				*defesa += 5;
				printf("Armadura de Ferro equipada! Defesa +3\n");
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
			preco = 1000;
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

//Inventário
void inventariomenu(int inventario[], int *quantidadeItens, int *vida, int vidaMaxima)
{
	int i, opcao, acao;

	if (*quantidadeItens == 0)
	{
		printf("\nSeu inventário está vazio!\n");
		return;
	}

	printf("==================================\n");
	printf("            INVENTÁRIO            \n\n");

	for(i = 0; i < *quantidadeItens; i++)
	{
		printf("%d - ", i + 1);

		switch(inventario[i])
		{
		case 1:
			printf("Poção Pequena\n");
			break;

		case 2:
			printf("Poção Grande\n");
			break;

		case 3:
			printf("Poção MAX\n");
			break;
		}
	}

	printf("0 - Voltar\n");
	printf("\nEscolha um item: ");
	scanf("%d", &opcao);

	if(opcao == 0)
		return;

	if(opcao < 1 || opcao > *quantidadeItens)
	{
		printf("Item inválido!\n");
		return;
	}

	opcao--;

	printf("\n1 - Usar\n");
	printf("2 - Descartar\n");
	printf("Escolha: ");
	scanf("%d", &acao);

	if(acao == 1)
	{
		switch(inventario[opcao])
		{
		case 1:
			*vida += 15;
			if(*vida > vidaMaxima)
				*vida = vidaMaxima;

			printf("Você usou a Poção Pequena!\n");
			break;

		case 2:
			*vida += 50;
			if(*vida > vidaMaxima)
				*vida = vidaMaxima;

			printf("Você usou a Poção Grande!\n");
			break;

		case 3:
			*vida = vidaMaxima;

			printf("Você usou a Poção MAX!\n");
			break;
		}

		for(i = opcao; i < *quantidadeItens - 1; i++)
			inventario[i] = inventario[i + 1];

		(*quantidadeItens)--;
	}
	else if(acao == 2)
	{
		for(i = opcao; i < *quantidadeItens - 1; i++)
			inventario[i] = inventario[i + 1];

		(*quantidadeItens)--;

		printf("Item descartado!\n");
	}
	else
	{
		printf("Opção inválida!\n");
	}
}
//

//Descansar
void descansar(int *vida, int vidaMaxima)
{

	*vida += 10;

	if (*vida > vidaMaxima)
	{
		printf("Você esta toltamente recuperado!\n");
		*vida = vidaMaxima;
	}
	else
	{
		printf("Você recuperou 10 de vida!\n");
		printf("%d/%d\n", *vida, vidaMaxima);
	}
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
			explorarMapa(inventario, &ouro, &quantidadeItens, &vida, &vidaMaxima, &ataque, &defesa, &experiencia, &nivel);
			break;

		case ('4'):
			loja(&ouro, inventario, &quantidadeItens, &ataque, &defesa);
			break;

		case ('5'):
			inventariomenu(inventario, &quantidadeItens, &vida, vidaMaxima);
			break;

		case ('6'):
			descansar(&vida, vidaMaxima);
			break;

		case ('7'):
			chefeFinal(inventario, &quantidadeItens, &vida, &vidaMaxima, &ataque, &defesa, &ouro, &experiencia, &nivel);
			break;
			

		case ('0'):
			printf("See you next time, stranger.");
			break;

		default:
			printf("Insira uma escolha válida!\n");
		}

	} while (escolhamenu != '0');

}