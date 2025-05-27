// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>

//renomeie o arquivo do include abaixo para trabalho1.h
#include "RodrigoRodrigues20232160034.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();
void testQ7();

int main()
{
    //testSomar();
    //testFatorial();
    //testQ1();
    testQ2();
    //testQ3();
    //testQ4();
    //testQ5();
    //testQ6();
    //testQ7();
}

void testSomar()
{
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == -4);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
    printf("%d\n", somar(-2, 8) == 6);
    printf("%d\n", somar(1000, 99) == 1099);

}

void testFatorial()
{
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/1/15");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"1/9/2016");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"//2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1//20");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/R/2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/12/19");
    printf("%d\n",q1(str) == 1); 
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 1);
    printf("%d\n", dma.qtdMeses == 1);
    printf("%d\n", dma.qtdAnos == 0);
}

void testQ3()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3); //0
    printf("%d\n", q3(str, 'b', 0) == 0); //1
    printf("%d\n", q3(str, 'l', 1) == 0); //2
    printf("%d\n", q3(str, 'l', 0) == 1); //3
    printf("%d\n", q3(str, 'L', 0) == 1); //4

// Adicionadas    
    strcpy(str,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'c', 0) == 3); //5
    printf("%d\n",q3(str, 'C', 0) == 3); //6
    printf("%d\n",q3(str, 'c', 1) == 1); //7
    printf("%d\n",q3(str, 'C', 1) == 2); //8
    printf("%d\n",q3(str, 'R', 0) == 0); //9
    printf("%d\n",q3(str, 'e', 0) == 3); //10
    printf("%d\n",q3(str, 'E', 1) == 2); //11
    printf("%d\n",q3(str, 'S', 1) == 0); //12

    // Teste 1
    strcpy(str, "João correu com José na praça.");
    printf("%d\n", q3(str, 'o', 0) == 5); //13
    printf("%d\n", q3(str, 'O', 0) == 5); //14
    printf("%d\n", q3(str, 'o', 1) == 5); //15
    printf("%d\n", q3(str, 'O', 1) == 0); //16
    printf("%d\n", q3(str, 'a', 0) == 4); //17
    printf("%d\n", q3(str, 'a', 1) == 4); //18

    // Teste 2
    strcpy(str, "Música é a alma da vida.");
    printf("%d\n", q3(str, 'a', 0) == 6); //19
    printf("%d\n", q3(str, 'a', 1) == 6); //20
    printf("%d\n", q3(str, 'u', 0) == 1); //21
    printf("%d\n", q3(str, 's', 0) == 1); //22
    printf("%d\n", q3(str, 'S', 1) == 0); //23

    // Teste 3
    strcpy(str, "Árvore, àrvore, ârvore, ãrvore!");
    printf("%d\n", q3(str, 'a', 0) == 4); //24
    printf("%d\n", q3(str, 'A', 0) == 4); //25
    printf("%d\n", q3(str, 'a', 1) == 3); //26
    printf("%d\n", q3(str, 'A', 1) == 1); //27
    printf("%d\n", q3(str, 'r', 0) == 8); //28

    // Teste 4
    strcpy(str, "Época de férias: verão, música e diversão!");
    printf("%d\n", q3(str, 'e', 0) == 6); //29
    printf("%d\n", q3(str, 'E', 1) == 1); //30
    printf("%d\n", q3(str, 'a', 0) == 5); //31
    printf("%d\n", q3(str, 'i', 0) == 3); //32
    printf("%d\n", q3(str, 'o', 0) == 3); //33

    // Teste 5
    strcpy(str, "Fácil ou difícil?");
    printf("%d\n", q3(str, 'i', 0) == 4); //34
    printf("%d\n", q3(str, 'i', 1) == 4); //35
    printf("%d\n", q3(str, 'f', 0) == 2); //36
    printf("%d\n", q3(str, 'f', 1) == 1); //37
    printf("%d\n", q3(str, 'l', 0) == 2); //38
}

void testQ4()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);

//adicionadas
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27); 
}

void testQ5()
{
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
}

void testQ6()
{
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
}

void testQ7()
{
    char matrix[8][10] = {
        { 'Q', 'M', 'J', 'D', 'L', 'A', 'Z', 'F', 'C', 'R' },
        { 'N', 'B', 'Y', 'G', 'P', 'S', 'K', 'H', 'E', 'X' },
        { 'V', 'O', 'W', 'U', 'T', 'I', 'Z', 'A', 'L', 'C' },
        { 'M', 'Q', 'B', 'D', 'N', 'F', 'R', 'J', 'G', 'E' },
        { 'H', 'S', 'K', 'T', 'U', 'X', 'W', 'O', 'P', 'Y' },
        { 'C', 'Z', 'A', 'I', 'L', 'M', 'V', 'G', 'N', 'B' },
        { 'D', 'F', 'E', 'H', 'S', 'K', 'J', 'Q', 'R', 'T' },
        { 'U', 'X', 'Y', 'W', 'V', 'O', 'P', 'N', 'M', 'L' }
    };
    char stringBusca [6] = { 'F', 'E', 'H', 'S', 'K'};
    printf("%d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "KJQRT");
    printf("%d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "AATOK");
    printf("%d\n", q7(matrix, stringBusca) == 0);
    strcpy(stringBusca, "LTBON");
    printf("%d\n", q7(matrix, stringBusca) == 1);

}