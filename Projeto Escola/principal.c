#include "crud.h"
#include "funcoesmenu.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_aluno_qtd_disciplinas 10
#define max_professor 30
#define max_disciplina 30
#define max_aluno 30
#define TAM 3


void SalvarDisciplina(Disciplina *lista, int qtd_disciplina) {
  FILE *arq_disciplina;
  arq_disciplina = fopen("EscolaDisciplina.txt", "w+");
  for (int i = 0; i < qtd_disciplina; i++) {
    fprintf(arq_disciplina, ";%d;", lista[i].TAM_ALUNO_POR_DISCIPLIA);
    fprintf(arq_disciplina, ";%d;", lista[i].ativo);
    fprintf(arq_disciplina, ";%d;", lista[i].semestre);
    fprintf(arq_disciplina, ";%d;", lista[i].codigo);
    fprintf(arq_disciplina, ";%d;", lista[i].qtd_aluno);
    fprintf(arq_disciplina, ";%s;", lista[i].nome);
    fprintf(arq_disciplina, ";%s;", lista[i].professor);
    for (int j = 0; j < lista[i].qtd_aluno; j++)
      fprintf(arq_disciplina, ";%d;", lista[i].alunos[j]);
    puts("\n");
  }
  fclose(arq_disciplina);
}

int main() {
  int codCheck;
  int qtdTotalProfessor;
  int semestreCheck;
  int nameCheck;
  int qtdTotalAlunos = 0;
  Aluno aluno;
  Aluno lista_aluno[max_aluno];
  Professor professor;
  Professor lista_professor[max_professor];
  int qtd_aluno = 0;
  int qtd_professor = 0;
  int qtd_disciplina = 0;
  int key_lista_disciplina = 0;
  Disciplina lista_disciplina[max_disciplina];
  Disciplina disciplina;
  int sair = 0;
  printf("Bem vindo ao Projeto escola\n\n");
  while (!sair) {
    int disciplina_procurada;
    int achou;
    int i;
    int verificacao;
    int excluir;
    int matricula_antiga;
    int matricula_atualizada;
    int entrada_menu = 0;
    int sair_professor = 0;
    int opcao_disciplina = 0;
    int sair_disciplina = 0;
    int sair_aluno = 0;
    int opcao_aluno = 0;
    int opcao_professor = 0;

    char alfabeto[53] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f',
                         'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K',
                         'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q',
                         'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V',
                         'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', ' '};

    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    entrada_menu = menuprincipal();
    system("clear");

    switch (entrada_menu) {

    case 0:
      SalvarDisciplina(lista_disciplina, qtd_disciplina);
      sair = 1;

      break;

    case 1:
      while (!sair_aluno) {
        opcao_aluno = menuAluno();
        system("clear");

        switch (opcao_aluno) {
        case 0:
          sair_aluno = 1;

          break;
        case 1:
          if (qtd_aluno < max_aluno) {
            qtdTotalAlunos = adicionarAluno(qtdTotalAlunos, lista_aluno,
                                            qtd_professor, lista_professor);

            qtd_aluno++;
          } else {
            printf("Numero máximo de alunos (%d) atingido! \n \n \n",
                   max_aluno);
          }
          break;
        case 2:
          qtd_aluno = excluirAluno(lista_aluno, qtd_aluno);
          break;
        case 3:
          atualizarAluno(lista_aluno, qtd_aluno);
          break;
        case 4:
          listagens(lista_aluno, qtd_aluno, qtdTotalAlunos);

          break;

        default:
          printf("Opcão inválida\n\n");
          break;
        }
      }
      break;
    case 2:

      while (!sair_professor) {

        opcao_professor = menuProfessor();
        system("clear");

        switch (opcao_professor) {
        case 0:
          sair_professor = 1;
          break;
        case 1:
          if (qtd_professor < max_professor) {
            qtdTotalProfessor = adicionarProfessor(
                qtdTotalProfessor, lista_professor, qtd_aluno, lista_aluno);

            qtd_professor++;
          } else {
            printf("Numero máximo de alunos (%d) atingido! \n \n \n",
                   max_aluno);
          }
          break;
        case 2:
          qtd_professor = excluirProfessor(lista_professor, qtd_professor);
          break;
        case 3:
          atualizarProfessor(lista_professor, qtd_professor);
          break;
        case 4:
          listagens_professor(lista_professor, qtd_professor,
                              qtdTotalProfessor);
          break;
        default:
          printf("Opcão inválida\n\n\n");
          break;
        }
      }
      break;
    case 3:

      // DISCIPLINA <

      while (!sair_disciplina) {
        opcao_disciplina = menuDisciplina();
        system("clear");
        int cod;
        switch (opcao_disciplina) {
        case 0:
          sair_disciplina = 1;
          break;
        case 1:
          listagem_disciplina(lista_disciplina, qtd_disciplina);
          break;
        case 2:
          ListaDisciplinaDadosCadastros(lista_disciplina, lista_aluno,
                                        qtd_disciplina, qtd_aluno);
          break;

        case 3:
          qtd_disciplina = CadastroDisciplinaNoSistema(
              lista_disciplina, qtd_disciplina, lista_professor, qtd_professor,
              max_disciplina, lista_aluno, qtd_aluno);

          break;

        case 4:
          excluirDisciplina(lista_disciplina, qtd_disciplina, lista_aluno,
                            qtd_aluno);
          break;

        case 5:
          menu_atualizar_disciplina(lista_disciplina, lista_aluno, qtd_aluno,
                                    qtd_disciplina, alfabeto[53], nums[10]);
          break;

        case 6:
          ListaDisciplinaVagas(lista_disciplina, qtd_disciplina);
          break;

        case 7:
          ListaAlunoSubMatriculados(lista_aluno, qtd_aluno);
          break;
        }
      }
    }
  }
  printf("O programa foi encerrado \nObrigado!!!!");
}

// Funções

void CAD_DisciplinaProfessor(Professor lista_professor[],
                             Disciplina lista_disciplina[], int QtdProfessor,
                             int qtd_disciplina, int key_lista_disciplina) {
  int matricula = 1;
  int i = QtdProfessor;
  do {
    if (QtdProfessor == 0) {
      printf("Não Foi Encontrado Nenhum Professor Cadastrado!! \n");
      printf("Cadastre Um Professor e adicione a Disciplina na Opção "
             "Atualizar!! \n");
      strcpy(lista_disciplina[key_lista_disciplina].professor,
             "Não Cadastrado");
      return;
    }

    do {
      if (matricula <= 0) {
        printf("Valor Inválido!!\n");
      }
      printf("Digite o Número da Matrícula do Professor: \n");
      matricula = VerificadorNumeroInteiro();
    } while (matricula <= 0);

    for (i = 0; i < QtdProfessor; i++) {
      if (lista_professor[i].matricula == matricula) {
        break;
      }
    }

    if (QtdProfessor == i) {
      printf("O Número de Matrícula não foi encontrado!\n");
      printf("Deseja parar por aqui? [1] - Sim | [Qualquer Tecla] - Não\n");
      if (VerificadorNumeroInteiro() == 1) {
        printf("Adicione Posteriormente Um Professor a Disciplina na Opção "
               "atualizar!! \n");
        strcpy(lista_disciplina[key_lista_disciplina].professor,
               "Não Cadastrado");
        return;
      }
    } else {
      strcpy(lista_disciplina[key_lista_disciplina].professor,
             lista_professor[i].nome);

      lista_disciplina[key_lista_disciplina].checkprofessor = '1';
    }
  } while (strcmp(lista_professor[i].nome,
                  lista_disciplina[key_lista_disciplina].professor) != 0);
}

void CadastroAlunoDisciplina(int key_disciplina, Disciplina lista_disciplina[],
                             Aluno lista_aluno[], int qtd_disciplina,
                             int qtd_aluno, int tamanho_maximo_disciplina) {
  int definitive_key_aluno = 0;
  int definitive_key_disciplina = 0;
  int fim = 0;
  int key_aluno = 1;
  int matricula_aluno = 0;

  if (qtd_aluno <= 0) {
    printf("Nenhum Aluno no Sistema!\nCadastre um Aluno e Adicione a "
           "Disciplina na Opção Atualizar\n");
    return;
  }

  do {
    do {
      printf("Digite o código do aluno que deseja incluir na disciplina: ");
      key_aluno = VerificadorNumeroInteiro();
      matricula_aluno = key_aluno;
      if (key_aluno == -1) {
        printf("\nValor Invalido!!");
      } else if ((key_aluno = BuscaSequencialInteira(
                      lista_aluno, lista_disciplina, qtd_aluno, matricula_aluno,
                      -2, '1')) == -2) {
        printf("\nAluno não encontrado!!\n");
        printf("Cadastrar mais alunos em disciplinas? [Sim] - 1 || [Não] - "
               "QUALQUER TECLA:\n");
        if ((fim = VerificadorNumeroInteiro()) != 1) {
          return;
        }
      }

      for (int i = 0;
           i < lista_disciplina[key_disciplina].qtd_aluno && key_aluno != -1;
           i++) {
        if (lista_disciplina[key_disciplina].alunos[i] == matricula_aluno) {
          printf("Disciplina já incluida na disciplina!!\n");
          key_aluno = -1;
        }
      }

    } while (key_aluno < 0);

    // Filtradores <

    /* Verifica a existencia de um aluno inativo na disciplina e
    resgata sua localização na memoria caso nescessário. */
    // <
    definitive_key_disciplina = lista_disciplina[key_disciplina].qtd_aluno;

    for (int i = 0; i < lista_disciplina[key_disciplina].qtd_aluno &&
                    lista_disciplina[key_disciplina].TAM_ALUNO_POR_DISCIPLIA ==
                        lista_disciplina[key_disciplina].qtd_aluno;
         i++) {
      for (int j = 0; j < qtd_aluno; j++) {
        if (lista_disciplina[key_disciplina].alunos[i] ==
            lista_aluno[j].matricula) {
          if (lista_aluno[j].ativo == -1) {
            definitive_key_disciplina = i;
            break;
          }
        }
      }
      if (definitive_key_disciplina !=
          lista_disciplina[key_disciplina].qtd_aluno) {
        break;
      }
    }

    definitive_key_aluno = lista_aluno[key_aluno].qtd_disciplina;

    for (int i = 0;
         i < lista_aluno[key_aluno].qtd_disciplina &&
         max_aluno_qtd_disciplinas == lista_aluno[key_aluno].qtd_disciplina;
         i++) {
      for (int j = 0; j < qtd_disciplina; j++) {
        if (lista_disciplina[j].codigo ==
            lista_aluno[key_aluno].disciplina[i]) {
          if (lista_disciplina[j].ativo == -1) {
            definitive_key_aluno = i;
            break;
          }
        }
      }
      if (definitive_key_aluno != lista_aluno[key_aluno].qtd_disciplina) {
        break;
      }
    }
    // >

    if (lista_aluno[key_aluno].qtd_disciplina >= tamanho_maximo_disciplina) {
      printf("Limite de disciplinas no aluno atingido!! \n");
      return;
    } else if (lista_disciplina[key_disciplina].qtd_aluno >=
                   lista_disciplina[key_disciplina].TAM_ALUNO_POR_DISCIPLIA &&
               definitive_key_disciplina ==
                   lista_disciplina[key_disciplina].qtd_aluno) {
      printf("Limite de alunos na disciplina atingido!! \n");
      return;
    }
    // Filtradores >

    lista_disciplina[key_disciplina].alunos = NULL;
    lista_disciplina[key_disciplina].alunos = (int *)realloc(
        lista_disciplina[key_disciplina].alunos,
        lista_disciplina[key_disciplina].TAM_ALUNO_POR_DISCIPLIA * sizeof(int));

    lista_aluno[key_aluno].disciplina[definitive_key_aluno] =
        lista_disciplina[key_disciplina].codigo;

    lista_disciplina[key_disciplina].alunos[definitive_key_disciplina] =
        matricula_aluno;

    lista_aluno[key_aluno].qtd_disciplina++;
    lista_disciplina[key_disciplina].qtd_aluno++;

    printf("Cadastrar mais alunos em disciplinas? [Sim] - 1 || [Não] - "
           "QUALQUER TECLA:");
    fim = VerificadorNumeroInteiro();

  } while (fim == 1);
}

int BuscaSequencialInteira(Aluno lista_aluno[], Disciplina lista_disciplina[],
                           int tamanho, int key, int valor_de_retorno,
                           char option) {
  if (option == '1') {
    for (int i = 0; i < tamanho; i++) {
      if (lista_aluno[i].matricula == key) {
        return i;
      }
    }
    return valor_de_retorno;
  } else {
    for (int i = 0; i < tamanho; i++) {
      if (lista_disciplina[i].codigo == key)
        return i;
    }
    return valor_de_retorno;
  }
}
void CadastroQuantidadeVagas(Disciplina lista_disciplina[],
                             int key_lista_disciplina) {
  int qtd_vagas;

  do {
    printf("Digite a Quantidade de Vagas Disponíveis: ");
    qtd_vagas = VerificadorNumeroInteiro();

    if (qtd_vagas < 1) {
      printf("Valor inválido!!\n");
      continue;
    }
  } while (qtd_vagas < 1);

  lista_disciplina[key_lista_disciplina].TAM_ALUNO_POR_DISCIPLIA = qtd_vagas;

  printf("Quantidade de Vagas Disponíveis na Disciplina Cadastradas!\n");
}

void ListaDisciplinaDadosCadastros(Disciplina lista_disciplina[],
                                   Aluno lista_aluno[], int qtd_disciplina,
                                   int qtd_aluno) {
  if (qtd_disciplina <= 0) {
    printf("Não Existe Disciplinas\n");
    return;
  }

  int key_lista_aluno;
  int input_codigo_disciplina = -1;
  int key_lista_disciplina;

  printf("digite o código da disciplina a ser encontrada\n");
  input_codigo_disciplina = VerificadorNumeroInteiro();

  key_lista_disciplina =
      BuscaSequencialInteira(lista_aluno, lista_disciplina, qtd_disciplina,
                             input_codigo_disciplina, -2, '2');

  if (lista_disciplina[key_lista_disciplina].ativo == -1 ||
      key_lista_disciplina < 0) {
    printf("Código não encontrado.\n");
    return;
  }

  system("clear");

  printf("Nome: %sProfessor: ", lista_disciplina[key_lista_disciplina].nome);
  printf("%s", lista_disciplina[key_lista_disciplina].professor);
  printf("Código: [%d] \nSemestre [%d]\n",
         lista_disciplina[key_lista_disciplina].codigo,
         lista_disciplina[key_lista_disciplina].semestre);

  printf("\nAlunos da disciplina: \n");

  if (lista_disciplina[key_lista_disciplina].qtd_aluno == 0) {
    printf("Lista Vazia!!\n");
  }

  for (int i = 0; i < lista_disciplina[key_lista_disciplina].qtd_aluno; i++) {
    key_lista_aluno = BuscaSequencialInteira(
        lista_aluno, lista_disciplina, qtd_aluno,
        lista_disciplina[key_lista_disciplina].alunos[i], -2, '1');
    if (lista_aluno[key_lista_aluno].ativo != -1) {
      printf("\n");
      printf("Nome: %sMatrícula: [%d] \nCPF: %s\n", lista_aluno[i].nome,
             lista_aluno[i].matricula, lista_aluno[i].cpf);
    }
  }
  printf("\n");
}
void ListaDisciplinaVagas(Disciplina lista_disciplina[], int qtd_disciplina) {
  int exist = 0;
  if (qtd_disciplina <= 0) {
    printf("Não Existe disciplinas!\n");
    return;
  }

  for (int i = 0; i < qtd_disciplina; i++) {
    if (lista_disciplina[i].ativo != -1 &&
        lista_disciplina[i].TAM_ALUNO_POR_DISCIPLIA > 40) {
      printf("\nNome: %sProfessor: ", lista_disciplina[i].nome);
      if (lista_disciplina[i].checkprofessor == '1')
        printf("%s", lista_disciplina[i].professor);
      else
        printf("Não Cadastrado.\n");
      printf("Código: [%d] \nSemestre: [%d]\nVagas: [%d]\n",
             lista_disciplina[i].codigo, lista_disciplina[i].semestre,
             lista_disciplina[i].TAM_ALUNO_POR_DISCIPLIA);
      exist = 1;
    }
  }

  if (exist <= 0) {
    printf("Não Existe disciplinas!\n");
  }
}

void ListaAlunoSubMatriculados(Aluno lista_aluno[], int qtd_aluno) {
  int cont_disciplina = 0;
  int exist = 0;
  if (qtd_aluno <= 0) {
    printf("Não Existe Alunos!\n");
    return;
  }

  for (int i = 0; i < qtd_aluno; i++) {
    if (lista_aluno[i].ativo != -1) {
      for (int j = 0; j < lista_aluno[i].qtd_disciplina; j++) {
        if (lista_aluno[i].disciplina[j] != -1) {
          cont_disciplina++;
          if (cont_disciplina >= 3)
            break;
        }
      }

      if (cont_disciplina < 3) {
        printf("Nome: %sMatrícula: %d \nCpf: %sNascimento: %d/%d/%d \nSexo: "
               "%c\n\n",
               lista_aluno[i].nome, lista_aluno[i].matricula,
               lista_aluno[i].cpf, lista_aluno[i].data_nascimento.dia,
               lista_aluno[i].data_nascimento.mes,
               lista_aluno[i].data_nascimento.ano, lista_aluno[i].sexo);
        exist = 1;
      }
    }
  }

  if (exist <= 0) {
    printf("Não Existe disciplinas!\n");
  }
}

int CadastroDisciplinaNoSistema(Disciplina lista_disciplina[],
                                int qtd_disciplina, Professor lista_professor[],
                                int qtd_professor, int max_qtd_disciplina,
                                Aluno lista_aluno[], int qtd_aluno) {
  int key_lista_disciplina = qtd_disciplina;

  if (qtd_disciplina == max_disciplina) {
    key_lista_disciplina =
        VerificadorDisciplinaInativa(lista_disciplina, qtd_disciplina);
  }

  if (key_lista_disciplina == qtd_disciplina &&
      qtd_disciplina >= max_disciplina) {
    printf("Tamanho Maximo Atingido! \n");
    return qtd_disciplina;
  }

  CadastroNomeDisciplina(key_lista_disciplina, lista_disciplina);

  CadastroCodigoDisciplina(lista_disciplina, qtd_disciplina,
                           key_lista_disciplina);

  lista_disciplina[key_lista_disciplina].semestre = CAD_DisciplinaSemestre();

  CAD_DisciplinaProfessor(lista_professor, lista_disciplina, qtd_professor,
                          qtd_disciplina, key_lista_disciplina);

  CadastroQuantidadeVagas(lista_disciplina, key_lista_disciplina);

  lista_disciplina[key_lista_disciplina].qtd_aluno = 0;
  CadastroAlunoDisciplina(key_lista_disciplina, lista_disciplina, lista_aluno,
                          qtd_disciplina, qtd_aluno, max_aluno_qtd_disciplinas);

  printf("disciplina cadastrada com sucesso!!\n");
  lista_disciplina[key_lista_disciplina].ativo = 1;
  qtd_disciplina++;

  return qtd_disciplina;
}

void CadastroNomeDisciplina(int key_lista_disciplina,
                            Disciplina lista_disciplina[]) {
  int i = 0;
  char name[15];
  do {
    i = 0;
    printf("digite o nome da disciplina a ser cadastrada\n");
    fgets(name, 15, stdin);
    fflush(stdin);

    while (name[i] != '\0') {
      if (name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 ||
          name[i] == ' ' || name[i] == '\n') {
        i++;
      } else
        break;
    }
    if (name[i] != '\0') {
      printf("Nome possui caracteres inválidos, digite novamente\n");
      continue;
    }
  } while (name[i] != '\0');

  strcpy(lista_disciplina[key_lista_disciplina].nome, name);
}

int VerificadorDisciplinaInativa(Disciplina lista_disciplina[],
                                 int qtd_disciplina) {

  int key_lista_disciplina;
  int i = 0;
  while (i < qtd_disciplina) {
    if (lista_disciplina[i].ativo == -1) {
      key_lista_disciplina = i;
      break;
    } else {
      key_lista_disciplina = qtd_disciplina;
    }
    i++;
  }
  return key_lista_disciplina;
}

void CadastroCodigoDisciplina(Disciplina lista_disciplina[], int qtd_disciplina,
                              int key_lista_disciplina) {
  int i = 0;
  printf("digite o código da disciplina a ser cadastrado\n");
  do {
    i = 0;
    int cod;

    cod = VerificadorNumeroInteiro();
    if (cod <= 0) {
      printf("Número Inválido!\n");
      continue;
    }

    while (i < qtd_disciplina) {
      if (cod == lista_disciplina[i].codigo && lista_disciplina[i].ativo != -1)
        break;
      i++;
    }

    if (i != qtd_disciplina) {
      printf("código já utilizado, digite outro: ");
    } else {
      lista_disciplina[key_lista_disciplina].codigo = cod;
    }
  } while (i != qtd_disciplina);
}