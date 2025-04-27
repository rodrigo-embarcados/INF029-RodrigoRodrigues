/*Exercício 9:
Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.*/

#include <stdio.h>

int main()
{
    int numeros[10], primos[10], primo, j, soma = 0, cont = 0;
    printf("Insira 10 números para saber quais deles são números primos.\n");
    for(int i = 0; i < 10; i++)
    {
	printf("\tInsira o %dº número: ", i + 1);
	scanf("%d", &numeros[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        j = 2;
	primo = 1;
	if(numeros[i] <= 1)
		continue;
        while(j * j <= numeros[i])
	{
	    if(numeros[i] % j == 0)
	    {	    
	        primo = 0;
	        break;
	    }
	    j++;
	}
	if(primo == 1)
	{
	    primos[cont] = numeros[i];
	    cont++;
	}
    }
    for(int i = 0; i < cont; i++)
	soma += primos[i];
    printf("Os números inseridos que são primos, são: {");
    for(int i = 0; i < cont; i++)
	printf(i < cont - 1 ? "%d, " : "%d}.\n", primos[i]);
    printf("A soma desses números é: %d.\n", soma);
}
