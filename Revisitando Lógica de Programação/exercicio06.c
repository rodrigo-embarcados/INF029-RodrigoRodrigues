/*Exercício 6:
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor*/

#include <stdio.h>

int main()
{
	int idade;
	printf("Insira uma idade de uma pessoa para saber se ela é maior ou menor. Digite -1 para sair: ");	
	scanf("%d", &idade);
	while(idade != -1)
	{
		if(idade < 18)
			printf("A pessoa é menor de idade.\n");
		else
			printf("A pessoa é maior de idade.\n");
		printf("Insira uma nova idade. Digite -1 para sair: ");
		scanf("%d", &idade);
	}
	printf("\n");
	return 0;
}
