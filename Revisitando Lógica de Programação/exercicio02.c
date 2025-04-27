/*Exercício 2:
 Faça um programa que leia a idade de duas pessoas e imprima a soma das idades*/

#include <stdio.h>

int main() 
{
	int idade1, idade2;
	printf("Insira a idade da pessoa 1: ");
	scanf("%d", &idade1);
	printf("Insira a idade da pessoa 2: ");
	scanf("%d", &idade2);
	printf("A soma das idades é %d.\n", idade1 + idade2);
	return 0;
}
