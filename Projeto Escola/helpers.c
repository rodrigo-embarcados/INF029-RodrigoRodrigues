#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_Linha_ARQ 100
typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int matricula;
  int ativo;
  char sexo;
  char nome[50];
  Data data_nascimento;
  char cpf[40];
  int dias;
  int disciplina[10];
  int qnt_disciplinas;
} Aluno;

typedef struct {
  int ativo;
  int matricula;
  char sexo;
  char nome[50];
  Data data_nascimento;
  char cpf[40];
  int disciplina[10];
  int qtd_disciplinas;
} Professor;

void stringaluno(int numero, char texto[]) { sprintf(texto, "%d", numero); }

int recuperar(Aluno lista_aluno[]) {
  FILE *arq;
  char linha[TAM_Linha_ARQ];
  int qtd_aluno = 0;
  arq = fopen("escola.txt", "r");
  fgets(linha, TAM_Linha_ARQ, arq);
  while (!feof(arq)) {

    fgets(linha, TAM_Linha_ARQ, arq);
  }
  return qtd_aluno;
}

void salvar(Aluno lista_aluno[], int qtd_aluno) {
  FILE *arq;
  arq = fopen("escola.txt", "w+");
  for (int i = 0; i < qtd_aluno; i++) {
    char texto[80];
    stringaluno(lista_aluno[i].matricula, texto);
    fputs(texto, arq);
    fputs(";", arq);
    fputs(lista_aluno[i].nome, arq);
    fputs(";", arq);
    fputc(lista_aluno[i].sexo, arq);
    fputs(";", arq);
    char dia[10], mes[10], ano[10];
    stringaluno(lista_aluno[i].data_nascimento.dia, dia);
    stringaluno(lista_aluno[i].data_nascimento.mes, mes);
    stringaluno(lista_aluno[i].data_nascimento.ano, ano);
    fprintf(arq, "%s;%s;%s", dia, mes, ano);
    fputs(";", arq);
    fputs(lista_aluno[i].cpf, arq);
    fputs(";", arq);
    char situ[10];
    stringaluno(lista_aluno[i].ativo, situ);
    fputs(situ, arq);
    fputs(";", arq);
    if (i < qtd_aluno - 1) {
      fputs("\n", arq);
    }
  }
  fclose(arq);
}

void PadronizarNome(Aluno listaaluno[], int QtdAluno) {
  for (int i = 0; i < QtdAluno; i++) {
    int j = 0;
    while (listaaluno[i].nome[j] != '\0') {
      if (listaaluno[i].nome[j] <= 122 && listaaluno[i].nome[j] >= 97) {
        listaaluno[i].nome[j] = (listaaluno[i].nome[j] - 32);
      }

      j++;
    }
  }
}

void PadronizarNomeProfessor(Professor lista_professor[], int qtd_professor) {
  for (int i = 0; i < qtd_professor; i++) {
    int j = 0;
    while (lista_professor[i].nome[j] != '\0') {
      if (lista_professor[i].nome[j] <= 122 &&
          lista_professor[i].nome[j] >= 97) {
        lista_professor[i].nome[j] = (lista_professor[i].nome[j] - 32);
      }
      j++;
    }
  }
}

void ListarInputProfessor(Professor lista_professor[], int qtdTotalProfessor) {
  char word[50];
  int sair = 0;
  system("clear");
  printf("Digite até 3 letras iniciais que deseja procurar:\n");
  do {
    char word[50];
    fgets(word, 50, stdin);
    fflush(stdin);

    int j = 0;
    while (word[j] != '\0') {
      if (word[j] <= 122 && word[j] >= 97) {
        word[j] = (word[j] - 32);
      }

      j++;
    }

    int achou = 0;
    if (strlen(word) < 4) {
      if (strlen(word) < 4) {
        printf("Procura deve ter no minimo 3 letras, digite novamente:\n");
      }
    } else {

      for (int i = 0; i < qtdTotalProfessor; i++) {
        char aux[40];
        int cont = 0;
        strcpy(aux, lista_professor[i].nome);
        int len = strlen(aux);
        int l = 0;
        for (int j = 0; j < len; j++) {
          if (strlen(word) - 1 == cont && lista_professor[i].ativo == 1) {

            printf(
                "-------------------------------------------------------\n\n");
            printf("%s", lista_professor[i].nome);
            printf("%d\n", lista_professor[i].matricula);
            printf("%s\n", lista_professor[i].cpf);
            printf("-------------------------------------------------------\n");
            achou = 1;
            sair = 1;
            break;
          }

          if (aux[j] == word[l]) {
            cont++;
            l++;
          } else {
            l = 0;
            cont = 0;
          }
        }
      }
      if (achou == 0) {
        sair = 1;
        system("clear");
        printf("Nenhum professor encontrado\n");
      }
    }

  } while (sair == 0);
}

void ListarInputAluno(Aluno listaaluno[], int qntTotal) {
  char word[50];
  int sair = 0;
  system("clear");
  printf("Digite no mínimo 3 letras iniciais que deseja procurar:\n");
  do {
    char word[50];
    fgets(word, 50, stdin);
    fflush(stdin);

    int j = 0;
    while (word[j] != '\0') {
      if (word[j] <= 122 && word[j] >= 97) {
        word[j] = (word[j] - 32);
      }

      j++;
    }

    int achou = 0;
    if (strlen(word) < 4) {
      if (strlen(word) < 4) {
        printf("Procura deve ter no minimo 3 letras, digite novamente:\n");
      }
    } else {

      for (int i = 0; i < qntTotal; i++) {
        char aux[40];
        int cont = 0;
        strcpy(aux, listaaluno[i].nome);
        int len = strlen(aux);
        int l = 0;
        for (int j = 0; j < len; j++) {
          if (strlen(word) - 1 == cont && listaaluno[i].ativo == 1) {

            printf(
                "-------------------------------------------------------\n\n");
            printf("%s", listaaluno[i].nome);
            printf("%d\n", listaaluno[i].matricula);
            printf("%s\n", listaaluno[i].cpf);
            printf("-------------------------------------------------------\n");
            achou = 1;
            sair = 1;
            break;
          }

          if (aux[j] == word[l]) {
            cont++;
            l++;
          } else {
            l = 0;
            cont = 0;
          }
        }
      }
      if (achou == 0) {
        sair = 1;
        system("clear");
        printf("Nenhum aluno encontrado\n");
      }
    }

  } while (sair == 0);
}
bool validarCpf(char cpf[]) {
  char stringcpf[40];
  int validou = 0;
  int digito[11];
  int validando1 = 0;
  int validando2 = 0;
  strcpy(stringcpf, cpf);
  int pos = 0;

  for (int i = 0; stringcpf[i] != '\0'; i++) {
    if (isdigit(stringcpf[i])) {
      digito[pos] =
          stringcpf[i] - '0'; // Convertendo caractere numerico para inteiro
      pos++;
    }
  }

  int j = 10;
  for (int i = 0; i < 9; i++) {

    validando1 += digito[i] * j;
    j--;
  }
  validando1 *= 10;
  validando1 %= 11;
  if (validando1 == digito[9]) {
    int j = 11;
    for (int i = 0; i < 10; i++) {

      validando2 += digito[i] * j;
      j--;
    }
    validando2 *= 10;
    validando2 %= 11;
    if (validando2 == digito[10]) {
      validou = 1;
      return true;
    }
    return false;
  }
  return false;
}