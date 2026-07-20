#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[50];
    int idade;
    float nota;
};

int main()
{
    struct Aluno a1;
    a1.idade = 17;
    a1.nota = 9.5;
    strcpy(a1.nome, "Igor");
    
    scanf("%[^\n]", a1.nome);
    scanf("%d", &a1.idade);
    scanf("%f", &a1.nota);
    
    printf("Hi my name is %s\n", a1.nome);
    printf("I am %d years old\n", a1.idade);
    printf("And my grade is %.1f\n", a1.nota);
    return (0);
}