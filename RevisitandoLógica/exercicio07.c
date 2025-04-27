/*Exercício 7:
Faça um programa que verifique se um número é primo.*/

#include <stdio.h>

int main()
{
    
    int numero, Primo = 1, i = 2;
    printf("Insira um numero para verificar se o mesmo é primo: ");
    scanf("%d", &numero);
    if(numero <= 1)
    {
    	printf("Não existe primo menor que 2.\n");
    	return 0;
    }
    while(i * i <= numero)
    {
        if(numero % i == 0)
        {
            Primo = 0;
            break;
        }        
        i++;
    }
    if(Primo == 1) 
	    printf("%d é primo.\n", numero);
    else 
	    printf("%d não é primo.\n", numero);
    return 0;
}
