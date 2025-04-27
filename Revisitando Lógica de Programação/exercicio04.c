/*Exercício 4:
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas **sem utilizar variável auxiliar***/

#include <stdio.h>

int main()
{
	int valor1, valor2;
	printf("Insira 2 valores inteiros: ");
	scanf("%d%d", &valor1, &valor2);
	valor1 = valor1 + valor2;
	valor2 = valor1 - valor2;
	valor1 = valor1 - valor2;
	return 0;
}
