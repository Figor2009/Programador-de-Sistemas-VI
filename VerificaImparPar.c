#include<stdio.h>

int main(){
	
	int num = 0;
	
	printf("Insira um numero: ");
	scanf("%d", &num);
	
	if (num % 2 == 0) {
		printf("O numero eh par\n");
	}
	else {
		printf("O numero eh impar\n");
	}
	return(0);
}