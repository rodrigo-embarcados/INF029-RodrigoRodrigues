/* Exercício 01:
Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.*/

#include <stdio.h>

int main()
{
    char nome[8] = "Rodrigo";
    long matricula = 20232160034;
    float semestre = 2023.2;
    printf("Olá, meu nome é %s.\n", nome);
    printf("Sou aluno do curso de ADS, matricula %ld.\n", matricula);
    printf("Ingressei no semestre %.1f.\n", semestre);
    return 0;
}
