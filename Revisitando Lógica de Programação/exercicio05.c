/*Exercício 5:
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor*/

#include <stdio.h>

int main()
{
	int idade;
	printf("Insira a idade de uma pessoa e será informado se ela é maior ou menor: ");
	scanf("%d", &idade);
	if(idade < 18)
		printf("A pessoa é menor de idade.\n");
	else
		printf("A pessoa é maior de idade.\n");
	return 0;
}
