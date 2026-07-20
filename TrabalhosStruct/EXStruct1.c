#include <stdio.h>
#include <string.h>

//Criar uma struct Livro com:
//titulo, autor e preço
//Declarar 1 livro e preencher os campos e imprimir os dados

struct Livro
{
    char titulo[50];
    char autor[50];
    float preco;
};

int main()
{
    struct Livro lv1;
    
    scanf("%[^\n]", lv1.titulo);
    scanf("%s", lv1.autor);
    scanf("%f", &lv1.preco);
    
    printf("Titulo do livro: %s\n", lv1.titulo);
    printf("Autor do livro: %s\n", lv1.autor);
    printf("Preço: R$%.2f\n", lv1.preco);
    return (0);
}