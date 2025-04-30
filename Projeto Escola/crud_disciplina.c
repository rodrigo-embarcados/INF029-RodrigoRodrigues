#include "crud.h"
#include "funcoesmenu.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3
#define max_disciplina 3

void listagem_disciplina(Disciplina lista_disciplina[], int qtd_disciplina) {
  int ao_menos_um = 0;
  printf("lista de diciplinas:\n");
  if (qtd_disciplina > 0) {
    for (int i = 0; i < qtd_disciplina; i++) {
      if (lista_disciplina[i].ativo != -1) {
        printf("\nNome: %sCodigo: [%d]\nSemestre: [%dº]\n",
               lista_disciplina[i].nome, lista_disciplina[i].codigo,
               lista_disciplina[i].semestre);
        ao_menos_um = 1;
      }
    }
    printf("\n");
  } else if (ao_menos_um == 0) {
    printf("Lista Vazia!!\n\n");
  }
}

int excluirDisciplina(Disciplina lista_disciplina[], int qtd_disciplina,
                      Aluno lista_aluno[], int qtd_aluno) {
  int excluirdisciplina;
  int i;
  int achou = 0;
  printf("Insira o código da disciplina que deseja excluir: \n");
  scanf("%d", &excluirdisciplina);
  fflush(stdin);
  for (i = 0; i < qtd_disciplina; i++) {
    if (lista_disciplina[i].codigo == excluirdisciplina) {
      lista_disciplina[i].ativo = -1;

      for (int j = 0; j < lista_disciplina[i].qtd_aluno; j++) {
        for (int k = 0; k < qtd_aluno; k++) {
          if (lista_disciplina[i].alunos[j] == lista_aluno[k].matricula) {
            for (int l = 0; l < lista_aluno[k].qtd_disciplina; l++) {
              if (excluirdisciplina == lista_aluno[k].disciplina[l]) {
                lista_aluno[k].disciplina[l] = -1;
                break;
              }
            }
          }
        }
      }

      achou = 1;
      printf("disciplina excluida com sucesso\n");
    }
  }
  if (achou == 0)
    printf("disciplina não encontrada\n");

  return qtd_disciplina;
}

int CAD_DisciplinaSemestre() {
  int semestre;
  do {

    printf("Digite o semestre da disciplina:\n");
    semestre = VerificadorNumeroInteiro();

    if (semestre <= 0) {
      printf("Valor Inválido!! \n\n");
    }

  } while (semestre <= 0);

  return semestre;
}

void menu_atualizar_disciplina(Disciplina lista_disciplina[],
                               Aluno lista_aluno[], int qtd_aluno,
                               int qtd_disciplina, char alfabeto[53],
                               int nums[10]) {
  int nameCheck;
  int codCheck;
  int sair_atualizacao = 0;
  int opcao_atualizacao;
  int i;
  int j;
  int cod_busca;
  printf("Insira o código da disciplina que deseja atualizar: \n");
  sair_atualizacao = 0;
  scanf("%d", &cod_busca);
  fflush(stdin);
  for (i = 0; i < qtd_disciplina; i++) {
    if (lista_disciplina[i].codigo == cod_busca &&
        lista_disciplina[i].ativo != -1) {
      int teste = i;
      while (!sair_atualizacao) {
        opcao_atualizacao = MenuAtualizacaoDisciplina();
        switch (opcao_atualizacao) {
        case 0:
          sair_atualizacao = 1;
          break;
        case 1:
          do {
            int flagName = 0;
            printf("Insira o novo nome da disciplina: \n");
            char name[15];
            fgets(name, 15, stdin);
            fflush(stdin);

            int tamName = strlen(name);
            tamName -= 1;
            for (int i = 0; i < tamName; i++) {

              int achou = 0;

              for (int j = 0; j < 53; j++) {

                if (name[i] == alfabeto[j]) {
                  achou = 1;
                  break;
                }
              }
              if (achou == 0) {
                flagName = 1;
                break;
              }
            }

            if (flagName == 0) {
              nameCheck = 1;
              strcpy(lista_disciplina[i].nome, name);
              break;
            } else {
              printf("Nome possui caracteres inválidos, digite "
                     "novamente\n");
            }

          } while (nameCheck == 0);

          printf("disciplina atualizada\n");
          break;

        case 2:

          do {
            int nmr1;
            int nmr2;
            int nmr3;
            int nmr[3];
            int jaTemCod = 0;
            int flagCod = 0;
            printf("Insira o novo cod do aluno: \n");
            int cod;
            scanf("%d", &cod);
            nmr1 = cod / 100;
            nmr2 = (cod % 100) / 10;
            nmr3 = ((cod % 100) % 10);

            if (cod > 0 && cod < 1000) {
              for (int i = 0; i < 3; i++) {
                int numAchou = 0;

                for (int j = 0; j < 11; j++) {
                  if (cod == nums[j]) {
                    numAchou = 1;
                    break;
                  }
                }
              }
            } else {
              flagCod = 1;
            }
            if (jaTemCod == 1) {
              printf("Código já cadastrado para outra disciplina\n");
            } else {
              if (flagCod == 0) {
                codCheck = 1;
                lista_disciplina[i].codigo = cod;
              } else {
                printf("Código inválido,digite 3 dígitos numéricos");
              }
            }

          } while (codCheck == 0);
          printf("disciplina atualizada\n");
          break;

        case 3:
          do {
            int flagName = 0;
            printf("Insira o novo professor: \n");
            char name[15];
            fgets(name, 15, stdin);
            fflush(stdin);

            int tamName = strlen(name);
            tamName -= 1;
            for (int i = 0; i < tamName; i++) {

              int achou = 0;

              for (int j = 0; j < 53; j++) {

                if (name[i] == alfabeto[j]) {
                  achou = 1;
                  break;
                }
              }
              if (achou == 0) {
                flagName = 1;
                break;
              }
            }

            if (flagName == 0) {
              nameCheck = 1;
              strcpy(lista_disciplina[i].professor, name);
              break;
            } else {
              printf("Nome possui caracteres inválidos, digite "
                     "novamente\n");
            }

          } while (nameCheck == 0);
          printf("disciplina atualizada\n");
          break;

        case 4:
          lista_disciplina[i].semestre = CAD_DisciplinaSemestre();
          break;

        case 5:
          printf("**Atenção** \nAo atualizar você resetará todos os alunos "
                 "cadastrados! Deseja continuar? [1] - SIM || [QUALQUER TECLA] "
                 "- NÃO.\n");
          if (VerificadorNumeroInteiro() == 1) {
            for (int j = 0; j < lista_disciplina[i].qtd_aluno; j++) {
              for (int k = 0; k < qtd_aluno; k++) {
                if (lista_disciplina[i].alunos[j] == lista_aluno[k].matricula) {
                  for (int l = 0; l < lista_aluno[k].qtd_disciplina; l++) {
                    if (cod_busca == lista_aluno[k].disciplina[l]) {
                      lista_aluno[k].disciplina[l] = -1;
                      break;
                    }
                  }
                }
              }
            }

            lista_disciplina[i].qtd_aluno = 0;
            CadastroAlunoDisciplina(i, lista_disciplina, lista_aluno,
                                    qtd_disciplina, qtd_aluno, 6);
          }
          break;

        case 6:
          ListaDisciplinaVagas(lista_disciplina, qtd_disciplina);
          break;

        case 7:
          ListaAlunoSubMatriculados(lista_aluno, qtd_aluno);
          break;

        default:
          printf("Opcão inválida\n\n\n");
        }
      }
    } else
      printf("Disciplia Inexistente!\n");
  }
}