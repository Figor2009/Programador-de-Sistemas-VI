#include <stdio.h>

double soma (double a, double b)
{
    double resultado = 0;
    resultado = a + b;
    return (resultado);
}

double sub (double a, double b)
{
    double resultado = 0;
    resultado = a - b;
    return (resultado);
}

double mult (double a, double b)
{
    double resultado = 0;
    resultado = a * b;
    return (resultado);
}

double divisao (double a, double b)
{
    double resultado = 0;
    resultado = a / b;
    return (resultado);

}

int pot(int aint, int bint)
{
    int resultadoint = 1;

    for (int i = 0; i < bint; i++)
    {
        resultadoint *= aint;
    }
    return resultadoint;
}

double raiz (double a, double b)
{
    double resultado = 0;
    b = 1;
    
    for (int i = 0; i < 100; i++) {
		resultado = 0.5 * (b + (a/b));
		b = resultado;	
	}
    return (resultado);
}

int fats(int aint)
{
    int resultadoint = 1;
    
    for(int i = 1; i <= aint; i++)
    {
        resultadoint *= i;
    }
    return resultadoint;
}

int fatDuplo(int aint)
{
    int resultadoint = 1;

    for(int i = aint; i >= 2; i -= 2)
    {
        resultadoint *= i;
    }
    return resultadoint;
}

int MDC(int aint, int bint)
{
    int resultadoint;

    while (bint != 0)
    {
        resultadoint = aint % bint;
        aint = bint;
        bint = resultadoint;
    }
    return aint;
}

int MMC(int aint, int bint)
{
    return (aint * bint) / MDC(aint, bint);
}

int segGrau(double a, double b, double c, double *x1, double *x2)
{
    double delta;

    delta = (b * b) - (4 * a * c);

    if (delta == 0)
    {
        *x1 = -b / (2 * a);
        return 1;
    }
    else
    {
        double raizDelta = raiz(delta, 1);

        *x1 = (-b + raizDelta) / (2 * a);
        *x2 = (-b - raizDelta) / (2 * a);

        return 2;
    }
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double resultado = 0;
    double delta = 0;
    int aint = 0;
    int bint = 0;
    int resultadoint = 0;
    int escolha = 0;
    
    do{
        printf("|===========================|\n");
        printf("|        CALCULADORA        |\n");
        printf("|     escolha uma opcao     |\n");
        printf("|===========================|\n");
        printf("| 1 - Soma                  |\n");
        printf("| 2 - Subtracao             |\n");
        printf("| 3 - Multiplicacao         |\n");
        printf("| 4 - Divisao               |\n");
        printf("| 5 - Potenciacao           |\n");
        printf("| 6 - Raiz Quadrada         |\n");
        printf("| 7 - Fatorial Simples      |\n");
        printf("| 8 - Fatorial Duplo        |\n");
        printf("| 9 - MDC                   |\n");
        printf("| 10 - MMC                  |\n");
        printf("| 11 - Equacao do 2o Grau   |\n");
        printf("|                           |\n");
        printf("| 12 - Sair                 |\n");
        printf("|                           |\n");
        printf("|===========================|\n");
        
        scanf("%d", &escolha);
    	
    	switch (escolha){
    	    case (1):
    	        printf("Voce escolheu soma, insira o primeiro valor:\n");
    	        scanf("%lf", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%lf", &b);
    	        
    	        resultado = soma (a, b);
    	        
    	        printf("%lf + %lf = %.5lf\n", a, b, soma (a, b));
    	        break;
    	        
    	    case (2):
    	        printf("Voce escolheu subtracao, insira o primeiro valor:\n");
    	        scanf("%lf", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%lf", &b);
    	        
    	        resultado = sub (a, b);
    	        
    	        printf("%lf - %lf = %.5lf\n", a, b, sub (a, b));
    	        break;
    	        
    	    case (3):
    	        printf("Voce escolheu multiplicacao, insira o primeiro valor:\n");
    	        scanf("%lf", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%lf", &b);
    	        
    	        resultado = mult (a, b);
    	        
    	        printf("%lf x %lf = %.5lf\n", a, b, mult (a, b));
    	        break;
    	        
    	    case (4):
    	        printf("Voce escolheu divisao, insira o primeiro valor:\n");
    	        scanf("%lf", &a);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%lf", &b);
    	        
    	        if(b == 0)
    	        {
    	            printf("Nao eh possivel realizar uma divisao por zero.\n");
    	            
    	        }
    	        else
    	        {
        	        resultado = divisao (a, b);
        	        
        	        printf("%lf / %lf = %.5lf\n", a, b, divisao (a, b));
    	        }
    	        break;
    	        
    	    case (5):
    	        printf("Voce escolheu potenciacao, insira o valor da base:\n");
    	        scanf("%d", &aint);
    	        printf("Insira o valor do expoente:\n");
    	        scanf("%d", &bint);
    	        
    	        resultadoint = pot (aint, bint);
    	        
    	        printf("%d elevado a %d = %d\n", aint, bint, pot (aint, bint));
    	        break;
    	        
    	    case (6):
    	        printf("Voce escolheu raiz quadrada, insira o valor da raiz:\n");
    	        scanf("%lf", &a);
    	        
    	        c = a;
    	        
    	        if(a <= 0)
    	        {
    	            printf("Nao existem no conjunto de numeros reais.\n");
    	        }
    	        else
    	        {
        	        resultado = raiz (a, b);
        	        
        	        printf("A raiz quadrada de %lf eh igual a %.5lf\n", c, raiz (a, b));
    	        }
        	    break;
    	        
    	    case (7):
    	        printf("Voce escolheu fatoracao simples, insira o valor a ser fatorado:\n");
    	        scanf("%d", &aint);
    	        
    	        bint = aint;
    	        
    	        if (bint <= 0)
    	        {
    	            printf("O numero deve ser positivo");
    	        }
    	        else
    	        {
    	        resultadoint = fats (a);
    	        
    	        printf("O fatorial de %d eh %d\n", bint, fats (aint));
    	        }
    	        break;
    	        
    	    case (8):
    	        printf("Voce escolheu fatoracao dupla, insira o valor a ser fatorado:\n");
    	        scanf("%d", &aint);
    	        
    	        bint = aint;
    	        
    	        if (bint <= 0)
    	        {
    	            printf("O numero deve ser positivo");
    	        }
    	        else
    	        {
    	        resultadoint = fatDuplo (aint);
    	        
    	        printf("O fatorial duplo de %d eh %d\n", bint, fatDuplo (aint));
    	        }
    	        break;
    	        
    	    case (9):
    	        printf("Voce escolheu MDC, insira o primeiro valor:\n");
    	        scanf("%d", &aint);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &bint);
    	        
    	        if (aint == 0 || bint == 0)
    	        {
    	            printf("Nao eh possivel realizar uma divisao por zero.\n");
    	            
    	        }
    	        else
    	        {
        	        resultadoint = MDC(aint, bint);
        	        
        	        printf("O MDC entre %d e %d eh %d\n", aint, bint, resultadoint);
    	        }
    	        break;
    	        
    	    case (10):
    	        printf("Voce escolheu MMC, insira o primeiro valor:\n");
    	        scanf("%d", &aint);
    	        printf("Insira o segundo valor:\n");
    	        scanf("%d", &bint);
    	        
    	        if (aint == 0 || bint == 0)
    	        {
    	            printf("Nao existe MMC quando um dos numeros eh zero.\n");
    	            
    	        }
    	        else
    	        {
        	        resultadoint = MMC(aint, bint);
        	        printf("O MMC entre %d e %d eh %d\n", aint, bint, resultadoint);
    	        }
    	        break;
    	        
    	    case (11):
    	        printf("Voce escolheu a equacao de 2o grau, insira o valor y ao quadrado:\n");
    	        scanf("%lf", &a);
    	        printf("Insira o valor x:\n");
    	        scanf("%lf", &b);
    	        printf("Insira o terceiro valor:\n");
    	        scanf("%lf", &c);
    	        
    	        {
                    double x1 = 0, x2 = 0;
                    int resultadoEq = segGrau(a, b, c, &x1, &x2);
            
                    if (resultadoEq == -1)
                    {
                        printf("A equacao nao possui raizes reais.\n");
                    }
                    else if (resultadoEq == 1)
                    {
                        printf("A equacao possui uma raiz real:\n");
                        printf("x = %.5lf\n", x1);
                    }
                    else
                    {
                        printf("As raizes da equacao sao:\n");
                        printf("x1 = %.5lf\n", x1);
                        printf("x2 = %.5lf\n", x2);
                    }
                }
                break;
    	        
    	    case(12):
    	        printf("Adeus!\n");
    	        break;
    	        
    	    default:
    	        printf("Escolha invalida!");    
    	}
	} while (escolha != 12);
	return (0);
}