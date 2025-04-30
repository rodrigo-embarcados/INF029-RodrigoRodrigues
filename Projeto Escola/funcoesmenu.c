#include <stdio.h>
#include <stdlib.h>

int VerificadorNumeroInteiro() {
  int numero;

  if (scanf("%d", &numero) == 1) {
    getchar();
    fflush(stdin);
    return numero;
  } else {
    getchar();
    fflush(stdin);
    return -1;
  }
}

int menuprincipal() {
  printf("Menu principal\n");
  printf("Selecione uma opção\n");
  printf("0 para sair: \n");
  printf("1 para opçoes de aluno: \n");
  printf("2 para opções de professor: \n");
  printf("3 para opções de disciplina: \n");

  return VerificadorNumeroInteiro();
}

int menuAluno() {

  printf("0 para voltar ao menu principal: \n");
  printf("1 para adicionar aluno: \n");
  printf("2 para excluir aluno: \n");
  printf("3 para atualizar aluno: \n");
  printf("4 para listar alunos: \n");

  return VerificadorNumeroInteiro();
}

int menuProfessor() {

  printf("0 para voltar ao menu principal: \n");
  printf("1 para adicionar professor: \n");
  printf("2 para excluir professor: \n");
  printf("3 para atualizar professor: \n");
  printf("4 para listar professores: \n");

  return VerificadorNumeroInteiro();
}

int menuDisciplina() {
  printf("0 - para voltar\n");
  printf("1 - listar de Displinas\n");
  printf("2 - especificar disciplina\n");
  printf("3 - para adicionar disciplina\n");
  printf("4 - para excluir uma disciplina\n");
  printf("5 - para atualizar uma nova disciplina\n");
  printf("6 - listar disciplinas com mais de 40 vagas\n");
  printf("7 - listar alunos matriculados em menos de 3 disciplinas\n");

  return VerificadorNumeroInteiro();
}

int MenuAtualizacaoDisciplina() {
  printf("0 - para voltar\n");
  printf("1 - para atualizar o nome\n");
  printf("2 - para atualizar o código\n");
  printf("3 - para atualizar o professor\n");
  printf("4 - para atualizar o semestre\n");
  printf("5 - para atualizar os alunos cadastrados\n");

  return VerificadorNumeroInteiro();
}