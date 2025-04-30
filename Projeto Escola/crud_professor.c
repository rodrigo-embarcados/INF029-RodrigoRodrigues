#include "crud.h"
#include "funcoesmenu.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ListaProfessorPorSexo(Professor lista_professor[], int qtd_professor,
                           char sexo);
int MenuListaProfessorPorSexo();

void PadronizarNomeProfessor();

int adicionarProfessor(int qtd_professor, Professor lista_professor[],
                       int qtd_aluno, Aluno lista_aluno[]) {
  Professor novoProfessor;
  int sexoCheck = 0;
  int passarData = 0;
  int cpfCheck = 0;
  int matriculaCheck = 0;
  int nameCheck = 0;
  char alfabeto[53] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f',
                       'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K',
                       'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q',
                       'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V',
                       'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', ' '};

  int arrayMeses[13] = {0,   31,  59,  90,  120, 151, 181,
                        211, 242, 272, 303, 334, 364};

  char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  // Matrícula <

  printf("Digite o número de mátricula\n");
  do {
    int jaTem = 0;
    int matriculaJaExiste = 0;
    int matricula = 0;
    scanf("%d", &matricula);
    fflush(stdin);
    getchar();
    for (int i = 0; i < qtd_professor; i++) {
      if (matricula == lista_professor[i].matricula) {
        printf("Número de matrícula já utilizado, digite outro: ");
        matriculaJaExiste = 1;
        break;
      }
    }

    if (!matriculaJaExiste) {
      if (matricula < 1) {
        printf("Digite um número maior que zero\n");
      } else {
        novoProfessor.matricula = matricula;
        matriculaCheck = 1;
      }
    }

  } while (matriculaCheck == 0);

  // > Matricula

  // Sexo <

  printf("Insira o sexo do professor(M para masculino, F para feminino): \n");
  do {

    scanf("%s", &novoProfessor.sexo);
    getchar();
    fflush(stdin);

    if (novoProfessor.sexo == 'f' || novoProfessor.sexo == 'F' ||
        novoProfessor.sexo == 'M' || novoProfessor.sexo == 'm') {
      sexoCheck = 1;
    } else {
      printf("Valor digitado para sexo inválido, digite (M para masculino, F "
             "para feminino)\n");
    }

  } while (sexoCheck == 0);

  // > Sexo

  // Data de Nascimento <

  do {
    int dayChek = 0;
    int monthChek = 0;
    int yearChek = 0;
    printf("Insira o dia de nascimento do professor: \n");

    do {
      scanf("%d", &novoProfessor.data_nascimento.dia);
      fflush(stdin);
      getchar();
      if (novoProfessor.data_nascimento.dia > 0 &&
          novoProfessor.data_nascimento.dia < 32) {
        dayChek = 1;
      }
      if (dayChek == 0) {
        printf("Digite um dia válido \n");
      }

    } while (dayChek == 0);

    printf("Insira o mes de nascimento do professor: \n");
    scanf("%d", &novoProfessor.data_nascimento.mes);
    getchar();
    fflush(stdin);
    if (novoProfessor.data_nascimento.mes < 13 &&
        novoProfessor.data_nascimento.mes > 0) {

      if (novoProfessor.data_nascimento.mes == 1 ||
          novoProfessor.data_nascimento.mes == 3 ||
          novoProfessor.data_nascimento.mes == 5 ||
          novoProfessor.data_nascimento.mes == 7 ||
          novoProfessor.data_nascimento.mes == 8 ||
          novoProfessor.data_nascimento.mes == 10 ||
          novoProfessor.data_nascimento.mes == 12) {

        if (novoProfessor.data_nascimento.dia < 32 &&
            novoProfessor.data_nascimento.dia > 0) {
          monthChek = 1;
        }
      } else if (novoProfessor.data_nascimento.mes == 4 ||
                 novoProfessor.data_nascimento.mes == 6 ||
                 novoProfessor.data_nascimento.mes == 9 ||
                 novoProfessor.data_nascimento.mes == 11) {

        if (novoProfessor.data_nascimento.dia < 31 &&
            novoProfessor.data_nascimento.dia > 0) {
          monthChek = 1;
        }
      }
    }

    printf("Insira o ano de nascimento do professor: \n");
    do {
      scanf("%d", &novoProfessor.data_nascimento.ano);
      getchar();
      fflush(stdin);
      if (novoProfessor.data_nascimento.ano > 1899 &&
          novoProfessor.data_nascimento.ano < 2024) {
        yearChek = 1;
      } else {
        printf("Digite um ano valido(entra 1900 e 2023)\n");
      }

    } while (yearChek == 0);

    if (novoProfessor.data_nascimento.mes == 2) {

      if (novoProfessor.data_nascimento.dia == 29) {
        if ((novoProfessor.data_nascimento.ano % 4 == 0 &&
             novoProfessor.data_nascimento.ano % 100 != 0) ||
            (novoProfessor.data_nascimento.ano % 400 == 0)) {
          monthChek = 1;
        } else {

          printf("Dia inválido para o mês de fevereiro (entre dia 1 e 28 para "
                 "anos não bissextos e para "
                 "anos bissextos até 29)\n");
        }
      } else if (novoProfessor.data_nascimento.dia > 0 &&
                 novoProfessor.data_nascimento.dia < 29) {
        monthChek = 1;
      }
    }

    if (dayChek == 1 && monthChek == 1 && yearChek == 1) {
      passarData = 1;
    } else {
      printf("Datas inválidas\n");
      passarData = 0;
    }

  } while (passarData == 0);

  novoProfessor.dias = (2023 - novoProfessor.data_nascimento.ano) * 365;

  novoProfessor.dias -= arrayMeses[novoProfessor.data_nascimento.mes];

  novoProfessor.dias += novoProfessor.data_nascimento.dia;

  //  > Data de Nascimento

  // Nome <

  do {
    int flagName = 0;
    printf("Insira o nome do professor: \n");
    char name[40];
    fgets(name, 40, stdin);
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
      strcpy(novoProfessor.nome, name);
      break;
    } else {
      printf("Nome possui caracteres inválidos, digite novamente\n");
    }

  } while (nameCheck == 0);

  // > Nome

  // CPF <

  do {
    int jaTemCpf = 0;
    int flagCpf = 0;
    printf("Insira o CPF do professor: \n");
    char cpf[40];
    fgets(cpf, 40, stdin);

    int ln = strlen(cpf);
    ln -= 1;

    if (ln == 14) {
      for (int i = 0; i < 14; i++) {
        int numAchou = 0;

        for (int j = 0; j < 11; j++) {
          if (cpf[i] == nums[j]) {
            numAchou = 1;
            break;
          }
        }

        if (numAchou == 0) {
          if (cpf[i] == '.' && (i == 3 || i == 7)) {

          } else if (cpf[i] == '-' && i == 11) {

          } else {
            flagCpf = 1;
            break;
          }
        }
      }
    } else {
      flagCpf = 1;
    }

    for (int i = 0; i < qtd_professor; i++) {
      for (int i = 0; i < qtd_professor; i++) {
        if (strcmp(lista_professor[i].cpf, cpf) == 0) {
          jaTemCpf = 1;
          break;
        }
      }
    }
    for (int i = 0; i < qtd_aluno; i++) {
      for (int i = 0; i < qtd_aluno; i++) {
        if (strcmp(lista_aluno[i].cpf, cpf) == 0) {
          jaTemCpf = 1;
          break;
        }
      }
    }
    if (jaTemCpf == 1) {
      printf("Cpf já cadastrado para outro professor ou aluno!\n");
    } else {
      if (flagCpf == 0) {

        bool digitoverificador = validarCpf(cpf);
        if (digitoverificador == true) {
          cpfCheck = 1;
          strcpy(novoProfessor.cpf, cpf);
        } else {
          printf("Este cpf não é válido por conta do digito verificador! "
                 "\nDigite novamente: \n");
        }
      } else {
        printf("Cpf inválido. Digite no modelo(XXX.XXX.XXX-XX)\n");
      }
    }

  } while (cpfCheck == 0);

  // > CPF

  system("clear");
  printf("Professor cadastrado com sucesso!\n\n");
  novoProfessor.ativo = 1;
  lista_professor[qtd_professor] = novoProfessor;
  qtd_professor++;
  PadronizarNomeProfessor(lista_professor, qtd_professor);
  return qtd_professor;
}
//////////////////// atualizar
void atualizarProfessor(Professor lista_professor[], int qtd_professor) {
  char alfabeto[53] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f',
                       'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K',
                       'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q',
                       'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V',
                       'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', ' '};
  char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  Professor novoprofessor;
  int sairAtualizar = 0;
  system("clear");

  do {
    int matriculaCheck = 0;
    int sairOpcoes = 0;
    int nameCheck = 0;
    int opcaoAtualizar;
    int cpfCheck = 0;
    int sexoCheck = 0;

    int i;
    int lugarprofessor;
    int achou = 0;

    int sairTudo = 0;
    while (achou == 0) {
      int procurarMatricula = 0;
      int sairProcura = 0;

      printf("Digite o número de mátricula que deseja fazer atualizações\n");
      scanf("%d", &procurarMatricula);
      getchar();
      fflush(stdin);
      for (i = 0; i < qtd_professor; i++) {
        if (lista_professor[i].matricula == procurarMatricula) {
          lugarprofessor = i;
          achou = 1;
          break;
        }
      }

      if (achou == 0) {
        system("clear");
        printf("Matricula não encontrada\n");
        printf("Se deseja procurar outra matrícula digite 1 se não digite 0\n");
        while (sairProcura != 1) {
          scanf("%d", &sairProcura);
          getchar();
          fflush(stdin);
          if (sairProcura != 1 && sairProcura != 0) {
            printf("Número inválido digite 1 para procurar outra matrícula ou "
                   "0 para sair\n");
          } else if (sairProcura == 0) {
            sairProcura = 1;
            achou = 1;
            sairTudo = 1;

          } else if (sairProcura == 1) {
          }
        }
      } else if (achou == 1) {
        system("clear");
        printf("Matricula encontrada\n");
      }
    }

    if (sairTudo == 1) {
      system("clear");
      printf("Atualização cancelada\n");
      printf("Escolha outra opção\n");

      break;
    }

    printf("\n\nnome: %s \n\n", lista_professor[lugarprofessor].nome);
    printf("cpf: %s \n\n\n", lista_professor[lugarprofessor].cpf);
    if (lista_professor[lugarprofessor].data_nascimento.mes < 10) {
      printf("%d/0%d/%d\n\n",
             lista_professor[lugarprofessor].data_nascimento.dia,
             lista_professor[lugarprofessor].data_nascimento.mes,
             lista_professor[lugarprofessor].data_nascimento.ano);
    } else {
      printf("%d/%d/%d\n\n\n",
             lista_professor[lugarprofessor].data_nascimento.dia,
             lista_professor[lugarprofessor].data_nascimento.mes,
             lista_professor[lugarprofessor].data_nascimento.ano);
    }
    if (lista_professor[lugarprofessor].sexo == 'f' ||
        lista_professor[lugarprofessor].sexo == 'F') {
      printf("sexo: Feminino\n\n\n\n");
    } else {
      printf("Sexo: Masculino\n\n\n\n");
    }
    printf("O que deseja atualizar \n");
    do {
      printf("0 - Para sair ou trocar de professor\n");
      printf("1 - Para atualizar nome\n");
      printf("2 - Para atualizar cpf\n");
      printf("3 - Para atualizar matrícula\n");
      printf("4 - Para atualizar sexo\n");
      printf("5 - Para atualizar disciplina\n");
      scanf("%d", &opcaoAtualizar);
      getchar();
      fflush(stdin);
      switch (opcaoAtualizar) {
      case 0:
        system("clear");
        sairOpcoes = 1;
        sairAtualizar = 1;
        break;
      case 1:
        do {
          int flagName = 0;
          printf("Insira o nome do professor: \n");
          char name[40];
          fgets(name, 40, stdin);
          name[strcspn(name, "\n")] = '\0';
          getchar();

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
            strcpy(novoprofessor.nome, name);
            break;
          } else {
            printf("Nome possui caracteres inválidos, digite novamente\n");
          }

        } while (nameCheck == 0);
        strcpy(lista_professor[lugarprofessor].nome, novoprofessor.nome);
        system("clear");
        printf("Nome atualizado\n\n");
        printf("Para atualizar outro pârametro ou sair,\ndigite:\n");

        break;
      case 2:
        do {
          int jaTemCpf = 0;
          int flagCpf = 0;
          printf("Insira o CPF do professor: \n");
          char cpf[40];
          fgets(cpf, 40, stdin);
          int ln = strlen(cpf);
          ln -= 1;

          if (ln == 14) {
            for (int i = 0; i < 14; i++) {
              int numAchou = 0;

              for (int j = 0; j < 11; j++) {
                if (cpf[i] == nums[j]) {
                  numAchou = 1;
                  break;
                }
              }

              if (numAchou == 0) {
                if (cpf[i] == '.' && (i == 3 || i == 7)) {

                } else if (cpf[i] == '-' && i == 11) {

                } else {
                  flagCpf = 1;
                  break;
                }
              }
            }
          } else {
            flagCpf = 1;
          }

          for (int i = 0; i < qtd_professor; i++) {
            for (int i = 0; i < qtd_professor; i++) {
              if (strcmp(lista_professor[i].cpf, cpf) == 0) {
                jaTemCpf = 1;
                break;
              }
            }
          }
          if (jaTemCpf == 1) {
            printf("Cpf já cadastrado para outro professor\n");
          } else {
            if (flagCpf == 0) {
              bool digitoverificador = validarCpf(cpf);
              if (digitoverificador == true) {
                cpfCheck = 1;
                strcpy(novoprofessor.cpf, cpf);
              } else {
                printf("Este cpf não é válido por conta do digito verificador! "
                       "\nDigite novamente: \n");
              }
            } else {
              printf("Cpf inválido. Digite no modelo(XXX.XXX.XXX-XX)\n");
            }
          }

        } while (cpfCheck == 0);
        strcpy(lista_professor[lugarprofessor].cpf, novoprofessor.cpf);
        system("clear");
        printf("Cpf atualizado\n\n");
        printf("Para atualizar outro pârametro ou sair,\ndigite:\n");
        break;
      case 3:
        system("clear");
        printf("Digite o novo número de matricula\n");
        do {
          int jaTem = 0;
          int matriculaJaExiste = 0;
          int matricula = 0;

          scanf("%d", &matricula);
          getchar();
          fflush(stdin);
          if (lista_professor[lugarprofessor].matricula == matricula) {

            printf("Novo número de matricula não pode ser igual a anterior, "
                   "Digite outro número\n\n");
          } else {

            for (int i = 0; i < qtd_professor; i++) {
              if (matricula == lista_professor[i].matricula) {
                printf("Número de matrícula já está em uso,digite outro:\n");
                matriculaJaExiste = 1;
                break;
              }
            }
          }

          if (matriculaJaExiste == 0) {
            if (matricula < 1) {
              printf("Digite um número maior que zero\n");
            } else if (lista_professor[lugarprofessor].matricula != matricula) {
              novoprofessor.matricula = matricula;
              matriculaCheck = 1;
            }
          }

        } while (matriculaCheck == 0);
        lista_professor[lugarprofessor].matricula = novoprofessor.matricula;
        system("clear");
        printf("Matricula atualizado\n\n");
        printf("Para atualizar outro pârametro ou sair,\ndigite:\n");
        break;
      case 4:
        printf("Insira o sexo do professor(M para masculino, F para feminino): "
               "\n");
        do {

          scanf("%s", &novoprofessor.sexo);
          getchar();
          fflush(stdin);

          if (novoprofessor.sexo == 'f' || novoprofessor.sexo == 'F' ||
              novoprofessor.sexo == 'M' || novoprofessor.sexo == 'm') {
            sexoCheck = 1;
          } else {
            printf("Valor digitado para sexo inválido, digite (M para "
                   "masculino, F "
                   "para feminino)\n");
          }

        } while (sexoCheck == 0);
        lista_professor[lugarprofessor].sexo = novoprofessor.sexo;
        system("clear");
        printf("Sexo atualizado\n\n");
        printf("Para atualizar outro pârametro ou sair,\ndigite:\n");
        break;

      case 5:
        break;
      default:
        printf("Opção inválida");
        break;
      }
    } while (sairOpcoes == 0);

  } while (!sairAtualizar);
}

///////listagem
int compararDataNascimento(const void *a, const void *b) {
  Professor *profA = (Professor *)a;
  Professor *profB = (Professor *)b;

  // Compara anos de nascimento
  if (profA->data_nascimento.ano != profB->data_nascimento.ano) {
    return profA->data_nascimento.ano - profB->data_nascimento.ano;
  } else {
    // Compara meses de nascimento
    if (profA->data_nascimento.mes != profB->data_nascimento.mes) {
      return profA->data_nascimento.mes - profB->data_nascimento.mes;
    } else {
      // Compara dias de nascimento
      return profA->data_nascimento.dia - profB->data_nascimento.dia;
    }
  }
}

void listagens_professor(Professor lista_professor[], int qtd_professor,
                         int qtdTotalProfessor) {
  if (qtd_professor == 0) {
    printf("Nenhum professor cadastrado para listar, selecione outra opção\n");
  } else {
    int sairlistas = 0;
    int opçãoLista = 0;
    int listar_mes;
    do {

      int opcaoListar;
      int ordem[qtd_professor];
      printf("Digite um número\n");
      printf("0 - para sair \n");
      printf("1 - para listar por ordem alfabética\n");
      printf("2 - para listar por data de nascimento\n");
      printf("3 - para listar por sexo\n");
      printf("4 - para listar os aniversariantes de um mês\n");
      printf(
          "5 - para listar de acordo com uma busca a partir de 3 caracteres\n");
      scanf("%d", &opcaoListar);
      getchar();
      system("clear");
      switch (opcaoListar) {
      case 0:
        system("clear");
        sairlistas = 1;
        break;
      case 1:
        for (int i = 1; i < qtdTotalProfessor; i++) {
          Professor aux;
          aux = lista_professor[i];

          int j = i - 1;

          while (j >= 0 && strcmp(lista_professor[j].nome, aux.nome) > 0) {
            lista_professor[j + 1] = lista_professor[j];
            j = j - 1;
          }
          lista_professor[j + 1] = aux;
        }
        int sair = 0;
        int i = 0;
        while (sair < qtd_professor) {

          if (lista_professor[i].ativo == 1) {
            printf(
                "--------------------------------------------------------\n");
            printf("Matricula : %d\n\n", lista_professor[i].matricula);
            printf("nome : %s\n\n", lista_professor[i].nome);
            if (lista_professor[i].sexo == 'f' ||
                lista_professor[i].sexo == 'F') {
              printf("sexo: feminino\n\n");
            } else {
              printf("sexo: masculino\n\n");
            }
            printf("cpf : %s\n", lista_professor[i].cpf);
            printf("data de nascimento : %d/%d/%d\n\n",
                   lista_professor[i].data_nascimento.dia,
                   lista_professor[i].data_nascimento.mes,
                   lista_professor[i].data_nascimento.ano);
            printf("---------------------------------------------------------"
                   "\n\n\n");
            sair++;
          }
          i++;
        }
        break;
      case 2:

        qsort(lista_professor, qtdTotalProfessor, sizeof(Professor),
              compararDataNascimento);
        printf("Lista de Professor ordenada por data de nascimento:\n\n");
        for (int i = 0; i < qtdTotalProfessor; i++) {
          if (lista_professor[i].ativo == 1) {
            printf("%s - %d/%d/%d\n\n\n", lista_professor[i].nome,
                   lista_professor[i].data_nascimento.dia,
                   lista_professor[i].data_nascimento.mes,
                   lista_professor[i].data_nascimento.ano);
          }
        }

        break;
      case 3:
        switch (MenuListaProfessorPorSexo()) {
        case 0:
          ListaProfessorPorSexo(lista_professor, qtd_professor, 'M');
          break;

        case 1:
          ListaProfessorPorSexo(lista_professor, qtd_professor, 'F');
          break;

        default:
          printf("opçao inválida");
        }

        break;
      case 4:

        printf("Insira o mês que deseja verificar os aniversariantes:\n");
        scanf("%d", &listar_mes);
        getchar();
        if (listar_mes < 1 || listar_mes > 12) {
          while (listar_mes < 1 || listar_mes > 12) {
            printf(
                "Insira um mês válido, maior que 0 e menor ou igual a 12: \n");
            scanf("%d", &listar_mes);
          }
        }
        int flagTem = 0;
        system("clear");
        printf("Lista de professores que fazem aniversário este mês: \n\n\n");
        for (int i = 0; i < qtdTotalProfessor; i++) {
          if (lista_professor[i].data_nascimento.mes == listar_mes &&
              lista_professor[i].ativo == 1) {
            printf(
                "--------------------------------------------------------\n");
            printf("Nome do(s) aniversariante(s): %s \n",
                   lista_professor[i].nome);
            printf(
                "Data de nascimento do professores aniversariante: %d/%d/%d \n",
                lista_professor[i].data_nascimento.dia,
                lista_professor[i].data_nascimento.mes,
                lista_professor[i].data_nascimento.ano);
            printf(
                "---------------------------------------------------------\n");
            flagTem = 1;
          }
        }
        if (flagTem == 0) {
          system("clear");
          printf("Não há nenhum aniversariante neste mês\n\n");
        }

        break;
      case 5:
        ListarInputProfessor(lista_professor, qtdTotalProfessor);
        break;
      default: 
        printf("opçao inválida");
        break;
      }

    } while (sairlistas == 0);
  }
}

//excluir professores

int excluirProfessor(Professor lista_professor[], int qtd_professor) {
  int excluiu = 0;
  int sucesso = 0;
  if (qtd_professor == 0) {
    system("clear");
    printf("Nenhum professor cadastrado\n");
    printf("Impossível excluir\n\n");

  } else {
    do {
      int matricula;
      int achou = 0;

      int lugarprofessor;
      printf("Digite o número de matricula que deseja excluir\n\n");
      if (scanf("%d", &matricula) == 1) {

        for (int i = 0; i < qtd_professor; i++) {
          if (lista_professor[i].matricula == matricula) {
            achou = 1;
            lista_professor[i].matricula = -1;
            lista_professor[i].ativo = -1;
            strcpy(lista_professor[i].cpf, "");
            break;
          }
        }

        if (achou == 0) {
          printf("Matricula não encontrada \n\n");
        } else {

          system("clear");
          printf("Mátricula excluída\n\n");
          sucesso = 1;
          excluiu = 1;
        }

      } else {
        printf("Valor digitado inválido\n\n");
        getchar();
      }

    } while (excluiu == 0);
  }

  if (sucesso == 1) {
    return qtd_professor - 1;
  } else {

    return qtd_professor;
  }
}

int MenuListaProfessorPorSexo() {

  printf("Digite um número\n");
  printf("0 - para masculino \n");
  printf("1 - para feminino\n");

  return VerificadorNumeroInteiro();
}

void ListaProfessorPorSexo(Professor lista_professor[], int qtd_Professor,
                           char sexo) {
  int ExisteAoMenosUm = 0;
  for (int i = 0; i < qtd_Professor; i++) {

    if (lista_professor[i].ativo != -1) {
      if (lista_professor[i].sexo == 'f' && sexo == 'F' ||
          lista_professor[i].sexo == 'F' && sexo == 'F') {
        ExisteAoMenosUm = 1;
        printf("---------------------------------------------\n");
        printf("Matricula : %d\n", lista_professor[i].matricula);
        printf("nome : %s\n", lista_professor[i].nome);
        printf("sexo: feminino\n\n");
        printf("cpf : %s\n", lista_professor[i].cpf);
        printf("data de nascimento : %d/%d/%d\n\n",
               lista_professor[i].data_nascimento.dia,
               lista_professor[i].data_nascimento.mes,
               lista_professor[i].data_nascimento.ano);
        printf("--------------------------------------------\n\n\n");
      }

      else if (lista_professor[i].sexo == 'M' && sexo == 'M' ||
               lista_professor[i].sexo == 'm' && sexo == 'M') {
        ExisteAoMenosUm = 1;
        printf("---------------------------------------------\n");
        printf("Matricula : %d\n", lista_professor[i].matricula);
        printf("nome : %s\n", lista_professor[i].nome);
        printf("sexo: masculino\n\n");
        printf("cpf : %s\n", lista_professor[i].cpf);
        printf("data de nascimento : %d/%d/%d\n\n",
               lista_professor[i].data_nascimento.dia,
               lista_professor[i].data_nascimento.mes,
               lista_professor[i].data_nascimento.ano);
        printf("--------------------------------------------\n\n\n");
      }
    }
  }
  if (!ExisteAoMenosUm) {
    printf("---------------------------------------------\n");
    printf("Lista Vazia!!\n");
    printf("---------------------------------------------\n\n\n");
  }
}