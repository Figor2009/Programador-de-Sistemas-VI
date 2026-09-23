#include <stdio.h>
#include <stdlib.h>
#include <C:\msys64\mingw64\include\libpq-fe.h>

int main()
{
	const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=admin";
	int escolha;
	int codigo;
	char produto[15];
    int quantidade = 0;
    double preco = 0.0;
	PGresult *res = NULL;
	int tam = 0;
	char *sql2;

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");
	
    // Libera os resultados e encerra
	do{
        printf("|===========================|\n");
        printf("|          ESTOQUE          |\n");
        printf("|     escolha uma opcao     |\n");
        printf("|                           |\n");
        printf("| 1 - Inserir               |\n");
        printf("| 2 - Selecionar            |\n");
        printf("| 3 - Deletar               |\n");
        printf("| 4 - Atualizar             |\n");
        printf("|                           |\n");
        printf("| 5 - Sair                  |\n");
        printf("|                           |\n");
        printf("|===========================|\n");
        
        scanf("%d", &escolha);
		
		switch(escolha) {
			case(1):
				printf("informe o nome: ");
				scanf("%s",produto);
				printf("informe a quantidade: ");
				scanf("%d",&quantidade);
				printf("informe o valor: ");
				scanf("%lf",&preco);
				
				char *sql = malloc(256 * sizeof(char));
				
				sprintf(sql,"INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ('%s', %d, %2.lf);", produto, quantidade, preco); 
				res = PQexec(conn, sql);

				if (PQresultStatus(res) != PGRES_COMMAND_OK) {
					fprintf(stderr, "Erro no INSERT: %s\n", PQerrorMessage(conn));
					PQclear(res);
					PQfinish(conn);
					return 1;
				}

				printf("Insercao realizada com sucesso!\n");
				free(sql);
				PQclear(res);
				//PQfinish(conn);
				break;
			
			case(2):
				PGresult *res = PQexec(conn, "SELECT * FROM estoque;");

				if (PQresultStatus(res) != PGRES_TUPLES_OK) {
					fprintf(stderr, "Erro na consulta: %s\n", PQerrorMessage(conn));
					PQclear(res);
					PQfinish(conn);
					return 1;
				}

				// Obtém o número de linhas e colunas
				int linhas = PQntuples(res);
				int colunas = PQnfields(res);

				printf("Total de linhas: %d\n", linhas);
				printf("Total de colunas: %d\n\n", colunas);

				// Imprime o nome das colunas
				for (int j = 0; j < colunas; j++) {
					printf("%-20s", PQfname(res, j));
				}
				printf("\n------------------------------------------------------------------------\n");

				// Percorre dinamicamente todas as linhas e colunas
				for (int i = 0; i < linhas; i++) {
					for (int j = 0; j < colunas; j++) {
						printf("%-20s", PQgetvalue(res, i, j));
					}
					printf("\n");
				}

				// Libera os resultados e encerra
				PQclear(res);
				//PQfinish(conn);
				break;
				
			case(3):
				printf("informe o id: ");
				scanf("%d",&codigo);
				
				tam = snprintf(NULL,0,"DELETE FROM estoque WHERE codigo = %d;", codigo); 
				tam = tam+1;
				char *sql2 = malloc(tam*sizeof(char));
				
				sprintf(sql2,"DELETE FROM estoque WHERE codigo = %d;", codigo); 
				res = PQexec(conn, sql2);
				
				if (PQresultStatus(res) != PGRES_COMMAND_OK) {
					fprintf(stderr, "Erro no DELETE: %s\n", PQerrorMessage(conn));
					PQclear(res);
					PQfinish(conn);
					return 1;
				}

				printf("Delete realizado com sucesso!\n");
				free(sql);
				PQclear(res);
				//PQfinish(conn);
				break;
				
			case(5):
    	        printf("Adeus!\n");
    	        break;
    	        
    	    default:
    	        printf("Escolha invalida!");
		}
	} while (escolha != 5);		
/*	CREATE TABLE estoque
(
	codigo SERIAL PRIMARY KEY,
	produto VARCHAR(255),
	quantidade INT,
	preco_unitario NUMERIC(10,2)
);

select * from estoque;


delete from estoque where codigo  = 1*/
}