#include <stdio.h>
#include <string.h>

//Criar um vetor com 5 alunos:
//ler os dados via scanf e depois imprimir

struct Aluno
{
	char nome[50];
	int idade;
	float nota;
};

int main()
{
	struct Aluno turma[5];

	for (int i = 0; i < 5; i++) {
	    printf("Insira os dados de nome, idade e nota do Aluno %d: ", i + 1);
		scanf("%s", turma[i].nome);
		scanf("%d", &turma[i].idade);
		scanf("%f", &turma[i].nota);
	}

    printf("LISTA DE ALUNOS")
	for (int i = 0; i < 5; i++) {
	    printf("Nome: %s\n", turma[i].nome);
		printf("Idade: %d\n", turma[i].idade);
		printf("Nota: %.1f\n", turma[i].nota);
		printf("==========================\n");
	}
	return (0);
}