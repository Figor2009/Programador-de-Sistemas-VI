#include <stdio.h>
#include <string.h>

//precisa ser declarada antes!
struct Endereco
{
    char rua[50];
    int numero;
};
//

struct Pessoa
{
    char nome[50];
    int idade;
    struct Endereco end;//ela é usada aqui!!!
};

int main()
{
    return (0);
}