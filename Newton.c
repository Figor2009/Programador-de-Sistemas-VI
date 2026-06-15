#include<stdio.h>

int main ()
{
	double xk = 0.0;
	double x = 0.0;
	double raiz = 0.0;
	
	printf("Digite a raiz\n");
	scanf("%lf", &x);
	
	xk = x;
	
	for (int i = 0; i < 1000; i++) {
		raiz = 0.5 * (xk + (x/xk));
		xk = raiz;	
	}
	printf("A raiz e de: %lf\n", raiz);	
	return (0);
}