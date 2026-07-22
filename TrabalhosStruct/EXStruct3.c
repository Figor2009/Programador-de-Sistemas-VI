#include <stdio.h>
#include <string.h>

struct Endereco
{
    char rua[50];
    int numero;
};

struct Pessoa
{
    char nome[50];
    int idade;
    struct Endereco end;
};

int main()
{   
    struct Pessoa pes;
    struct Endereco end;
    
    printf("Insira Nome e idade: \n");
    scanf("%[^\n]", pes.nome);
    scanf("%d", &pes.idade);
    printf("Insira Rua e número da residência: \n");
    scanf("%s", end.rua);
    scanf("%d", &end.numero);
    
    printf("Nome: %s\n", pes.nome);
    printf("Idade: %d\n", pes.idade);
    printf("ENDEREÇO\n");
    printf("Rua: %s\n", end.rua);
    printf("Número: %d\n", end.numero);
    
    return (0);
}