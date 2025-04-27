/*Exercício 10:
Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.*/

#include <stdio.h>

typedef struct
{
    char nome [20];
    int  idade;
    char sexo;
    long  cpf;
} 
Pessoa;

int main()
{
    Pessoa vetor[5];
    for(int i = 0; i < 5; i++)
    {
        printf("Insira o nome da Pessoa %d: ", i + 1);
        scanf("%19s", vetor[i].nome);
        printf("Insira a idade da Pessoa %d: ", i + 1);
        scanf("%d", &vetor[i].idade);
        printf("Insira o sexo da Pessoa %d: ", i + 1);
        getchar();
        scanf("%c", &vetor[i].sexo);
        printf("Insira o cpf da Pessoa %d: ", i + 1);
        scanf("%ld", &vetor[i].cpf);
        printf("\n");
    }
    printf("Eis os dados inseridos:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("\tO nome da pessoa %d é: %s.\n", i + 1, vetor[i].nome);
        printf("\tA idade da pessoa %d é: %d.\n", i + 1, vetor[i].idade);
        printf("\tO sexo da pessoa %d é: %c.\n", i + 1, vetor[i].sexo);
        printf("\tO cpf da pessoa %d é: %ld.\n", i + 1, vetor[i].cpf);
        printf("\n");
    }
    return 0;
}
