/*Exercício 8:
Faça um programa que calcula o fatorial de um número.*/

#include <stdio.h>

int main()
{
    long long int fatorial = 1;
    int i = 1, numero;
    printf("Insira um numero para calcular seu fatorial: ");
    scanf("%d", &numero);
    if (numero >= 0)
    {
        while(i <= numero)
	    {
            fatorial *= i;
            i++;
        }
        printf("O fatorial de %d é: %lld\n", numero, fatorial);
    }
    else
    	printf("Nao existe fatorial de numero menor que zero!\n");
    return 0;
}
