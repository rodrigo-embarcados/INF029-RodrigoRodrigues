// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "RodrigoRodrigues20232160034.h" // Substitua pelo seu arquivo de header renomeado

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}
//Funções implementadas

char tira_acento_letra(uint8_t byte_ms)
{
  switch (byte_ms)
  {
    case 0xA1:
    case 0xA0:
    case 0xA2:
    case 0xA3:
      return 'a'; // á à â ã
    case 0xA9:
    case 0xAA:
      return 'e'; // é ê
    case 0xAD:
      return 'i'; // í
    case 0xB3:
    case 0xB4:
    case 0xB5:
      return 'o'; // ó ô õ
    case 0xBA:
    case 0xBC:
      return 'u'; // ú ü
    case 0xA7:
      return 'c'; // ç
    case 0x81:
    case 0x80:
    case 0x82:
    case 0x83:
      return 'A'; // Á À Â Ã
    case 0x89:
    case 0x8A:
      return 'E'; // É Ê
    case 0x8D:
      return 'I'; // Í
    case 0x93:
    case 0x94:
    case 0x95:
      return 'O'; // Ó Ô Õ
    case 0x9A:
    case 0x9C:
      return 'U'; // Ú Ü
    case 0x87:
      return 'C'; // Ç
  }
  return 0;
}
char *tira_acento_string(char *texto)
{
  char atual;
  uint8_t byte_ms;
  for (int i = 0; texto[i] != '\0'; i++)
  {
    atual = texto[i];
    if ((uint8_t)atual == 0xC3)
    {
      byte_ms = (uint8_t)texto[i + 1];
      texto[i] = tira_acento_letra(byte_ms);
      for (int j = i + 1; texto[j] != '\0'; j++)
      {
        texto[j] = texto[j + 1];
      }
      i++;
    }
  }
  return texto;
}
int checaBissexto(char *ano) 
{
  int ano_int = atoi(ano);
  return (ano_int % 4 == 0 && ano_int % 100 != 0) || (ano_int % 400 == 0);
}
int checaData(char *dia, char *mes, char *ano) 
{
  int dia_int = atoi(dia), mes_int = atoi(mes), ano_int = atoi(ano);   
  if(ano_int < 0 || mes_int < 1 || mes_int > 12 || dia_int < 1) return 0;
    int diasNoMes;
    switch(mes_int) 
    {
      case 2:
        diasNoMes = checaBissexto(ano) ? 29 : 28;
        break;
      case 4: case 6: case 9: case 11:
        diasNoMes = 30;
        break;
      default:
        diasNoMes = 31;
    }
    return dia_int <= diasNoMes;
}
void separa_data(char *data, char *sDia, char *sMes, char *sAno)
{
  int pos = 0, i = 0;
  if(strlen(data) >= 6)
  {
    while(data[pos] != '/')
    {
      if(pos < 2)
      {
        sDia[i] = data[pos];
        pos++;
        i++;
      }
    }
    pos++;
    i = 0;
    while(data[pos] != '/')
    {
      if(pos < 5)
      {
        sMes[i] = data[pos];
        pos++;
        i++;
      }
    }
    pos++;
    i = 0;
    while(data[pos] != '\0')
    {
      if(pos < 10)
      {
        sAno[i] = data[pos];
        pos++;
        i++;
      }
    }
    sDia[2] = '\0';
    sMes[2] = '\0';
    sAno[4] = '\0';
  }
}
int dias_no_mes(int mes, int ano)
{
    int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            return 29;
    }
    return dias[mes - 1];
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
// quebrar a string data em strings sDia, sMes, sAno
// printf("%s\n", data);
int q1(char data[])
{
  int datavalida = 1;
  char sDia[3], sMes[3], sAno[5];
  int pos = 0;
  for(int i = 0; i < 5; i++)
  {
    if (i < 2)
    {
      sDia[i] = '\0';
      sMes[i] = '\0';
    }
    sAno[i] = '\0';
  }
  if(strlen(data) >= 6)
  {
    int i = 0;
    while(data[pos] != '/')
    {
      if(pos < 2)
      {
        sDia[i] = data[pos];
        pos++;
        i++;
      }
      else
      {
        datavalida = 0;
        break;
      }
    }
    pos++;
    i = 0;
    while(data[pos] != '/')
    {
      if(pos < 5)
      {
        sMes[i] = data[pos];
        pos++;
        i++;
      }
      else
      {
        datavalida = 0;
        break;
      }
    }
    pos++;
    i = 0;
    while(data[pos] != '\0')
    {
      if(pos < 10)
      {
        sAno[i] = data[pos];
        pos++;
        i++;
      }
      else
      {
        datavalida = 0;
        break;
      }
    }
  }
  else datavalida = 0;
  if(checaData(sDia, sMes, sAno) == 0) datavalida = 0;
  if(datavalida) return 1;
  else return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;

  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }
  else
  {
    // verifique se a data final não é menor que a data inicial
    char sDia1[3], sMes1[3], sAno1[5];
    char sDia2[3], sMes2[3], sAno2[5];
    int iDia1, iMes1, iAno1;
    int iDia2, iMes2, iAno2;
    separa_data(datainicial, sDia1, sMes1, sAno1);
    separa_data(datafinal, sDia2, sMes2, sAno2);
    iDia1 = atoi(sDia1);
    iMes1 = atoi(sMes1);
    iAno1 = atoi(sAno1);
    iDia2 = atoi(sDia2);
    iMes2 = atoi(sMes2);
    iAno2 = atoi(sAno2);
    if(iAno1 > iAno2)
    {
      dma.retorno = 4;
      return dma;
    }
    else if(iAno1 == iAno2)
    {
      if(iMes1 > iMes2)
      {
        dma.retorno = 4;
        return dma;
      }
      else if(iMes1 == iMes2)
      {
        if(iDia1 > iDia2)
        {
          dma.retorno = 4;
          return dma;
        }
      }
    }
    // calcule a distancia entre as datas
    dma.qtdAnos = iAno2 - iAno1;
    dma.qtdMeses = iMes2 - iMes1;
    dma.qtdDias = iDia2 - iDia1;
    if (dma.qtdMeses < 0)
    {
      dma.qtdAnos--;
      dma.qtdMeses += 12;
    }
    if (dma.qtdDias < 0)
    {
      dma.qtdMeses--;
      int mes_ant = iMes2 - 1;
      int ano_ref = iAno2;
      if (mes_ant == 0)
      {
          mes_ant = 12;
          ano_ref--;
      }
      dma.qtdDias += dias_no_mes(mes_ant, ano_ref);
    }
    // se tudo der certo
    dma.retorno = 1;
    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  uint8_t byte_ms;
  char atual;
  for(int i = 0; i < strlen(texto); i++)
  {
    atual = texto[i];
    if((uint8_t)atual == 0xC3)
    {
      byte_ms = (uint8_t)texto[i + 1];
      atual = tira_acento_letra(byte_ms);
      i += 1;
    }
    if(isCaseSensitive == 1)
    {
      if(atual == c) qtdOcorrencias++;
    }
    else
    {
      if (c >= 'a' && (atual == c || atual + 32 == c)) qtdOcorrencias++;
      else if (c <= 'Z' && (atual == c || atual - 32 == c)) qtdOcorrencias++;
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int achou, cont = 0;
  strTexto = tira_acento_string(strTexto);
  for (int i = 0; i < strlen(strTexto) - strlen(strBusca); i++)
  {
    achou = 1;
    if (strTexto[i] == strBusca[0])
    {
      int j = 1;
      while (j < strlen(strBusca))
      {
        if (strTexto[i + j] == strBusca[j])
        {
          j++;
          continue;
        }
        else
        {
          achou = 0;
          break;
        }
      }
      if (achou)
      {
        posicoes[cont++] = i + 1;
        posicoes[cont++] = i + strlen(strBusca);
      }
      i++;
    }
  }
  int qtdOcorrencias = cont / 2;
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int inv = 0;
  while(num != 0)
	{
		inv = inv * 10 + num % 10;
		num /= 10;
	}
  num = inv;
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias;
  return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5])
{
  int achou;
  return achou;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++)
  {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sDia[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++)
  {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++)
  {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4)
  {                 // testa se tem 2 ou 4 digitos
    sAno[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}