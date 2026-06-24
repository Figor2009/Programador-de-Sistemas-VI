#include <stdio.h>

int soma (int a, int b)
{
    int resultado = 0;
    resultado = a + b;
    return (resultado);
}

int sub (int a, int b)
{
    int resultado = 0;
    resultado = a - b;
    return (resultado);
}

int mult (int a, int b)
{
    int resultado = 0;
    resultado = a * b;
    return (resultado);
}

int divisao (int a, int b)
{
    int resultado = 0;
    resultado = a / b;
    return (resultado);

}

int main()
{
    int a = 0;
    int b = 0;
    int escolha = 0;
    int resultado = 0;
    
    do{
        printf("|===========================|\n");
        printf("|        CALCULADORA        |\n");
        printf("|     escolha uma opcao     |\n");
        printf("|                           |\n");
        printf("| 1 - Soma                  |\n");
        printf("| 2 - Subtracao             |\n");
        printf("| 3 - Multiplicacao         |\n");
        printf("| 4 - Divisao               |\n");
        printf("|                           |\n");
        printf("| 5 - Sair                  |\n");
        printf("|                           |\n");
        printf("|===========================|\n");
        
        scanf("%d", &escolha);
    	
    	switch (escolha){
    	    case (1):
    	        printf("Voce escolheu soma, insira o primeiro valor:\n");
    	        scanf("%d", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &b);
    	        
    	        resultado = soma (a, b);
    	        
    	        printf("%d + %d = %d\n", a, b, soma (a, b));
    	        break;
    	        
    	    case (2):
    	        printf("Voce escolheu subtracao, insira o primeiro valor:\n");
    	        scanf("%d", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &b);
    	        
    	        resultado = sub (a, b);
    	        
    	        printf("%d - %d = %d\n", a, b, sub (a, b));
    	        break;
    	        
    	    case (3):
    	        printf("Voce escolheu multiplicacao, insira o primeiro valor:\n");
    	        scanf("%d", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &b);
    	        
    	        resultado = mult (a, b);
    	        
    	        printf("%d x %d = %d\n", a, b, mult (a, b));
    	        break;
    	        
    	    case (4):
    	        printf("Voce escolheu divisao, insira o primeiro valor:\n");
    	        scanf("%d", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &b);
    	        
    	        if(b == 0)
    	        {
    	            printf("Nao eh possivel realizar uma divisao por zero.\n");
    	            
    	        }
    	        else
    	        {
        	        resultado = divisao (a, b);
        	        
        	        printf("%d / %d = %d\n", a, b, divisao (a, b));
    	        }
    	        break;
    	        
    	    case(5):
    	        printf("Adeus!\n");
    	        break;
    	        
    	    default:
    	        printf("Escolha invalida!");
    	}
	} while (escolha != 5);
	return (0);
}