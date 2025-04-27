/*Exercício 3:
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas*/

#include <stdio.h>

int main()
{
	int valor1, valor2, temp;
	printf("Insira dois valores inteiros: ");
	scanf("%d%d", &valor1, &valor2);
	temp = valor1;
	valor1 = valor2;
	valor2 = temp;
	return 0;
}
