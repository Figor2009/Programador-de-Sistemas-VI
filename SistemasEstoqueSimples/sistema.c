#include<stdio.h>
#include<windows.h>
#include <C:\msys64\mingw64\include\libpq-fe.h>

#define MAX_SIZE_DESCRICAO  25
#define MAX_SIZE_V_STRUCT 1000

typedef struct Estoque
{
	char produto[MAX_SIZE_DESCRICAO];
	int codigo;
	int quantidade;
	double preco_unitario;
}estq;

#include "MinhasFuncoes.h"

int main()
{
	system("color 07");
	system("chcp 65001");
	system("cls");
	
	const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";
	int escolha = 0;
	estq deposito[MAX_SIZE_V_STRUCT];
	
	BarraDeCarregamento();
	/*INICIALIZO MEU VETOR DE ESTRUTURA TODO NULO*/
	NullStruct(deposito);
	
	PGconn *conn = PQconnectdb(conninfo);

	if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

	printf("Conectado ao banco com sucesso!\n");

	do
	{
		Menu();
		scanf("%d",&escolha);
		switch(escolha)
		{
			/*CADASTRO DE PRODUTOS NO ARQUIVO*/
			case 1:
				system("cls");
				CadastroDeProdutos(deposito);
			break;
			/*LISTAR PRODUTOS DO ARQUIVO*/
			case 2:
				system("cls");
				ListarProdutos(deposito);
			break;
			/*BUSCAR PRODUTOS DO ARQUIVO POR CODIGO*/
			case 3:
				system("cls");
				BuscarProdutos(deposito);
			break;
			/*ALTERAR QUANTIDADE DE PRODUTOS DO ESTOQUE POR CODIGO*/
			case 4:
				system("cls");
				AlterarQuantidadeProdutos(deposito);
			break;
			/*CALCULAR VALOR TOTAL DE PRODUTOS NO ESTOQUE*/
			case 5:
				system("cls");
				CalcularValorTotalEstoque(deposito);
			break;
			/*ORDENAR MINHAS LISTAGEM POR FILTROS */
			case 6:
				system("cls");
				FiltrarOrdenar(deposito);
			break;
			/*APAGAR MEU BANCO DE DADOS */
			case 7:
				system("cls");
				ApagarOsDadosDoSistema(deposito);
				system("cls");
				printf("\nEXCLUSAO CONCLUIDA\n");
			break;
			/*FINALIZAR O SISTEMA*/
			case 8:
				system("cls");
				printf("Sistema Finalizado\n");
				Som(L"Windows Shutdown.wav",500);
			break;
			
			default:
				system("cls");
				printf("\nATENCAO: Escolha uma das opcoes disponiveis no menu!\n\n");
		}
		
	}while(escolha != 8);
	
	return(0);
}

