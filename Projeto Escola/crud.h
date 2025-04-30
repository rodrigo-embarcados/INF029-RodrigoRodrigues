#define max_aluno_qtd_disciplinas 10
typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct Aluno {
  int matricula;
  int ativo;
  char sexo;
  char nome[50];
  Data data_nascimento;
  char cpf[40];
  int dias;
  int disciplina[max_aluno_qtd_disciplinas];
  int qtd_disciplina;
} Aluno;

typedef struct Professor {
  int ativo;
  int matricula;
  char sexo;
  char nome[50];
  Data data_nascimento;
  int dias;
  char cpf[40];
} Professor;

typedef struct Disciplina {
  int ativo;
  char nome[15];
  int codigo;
  int semestre;
  char professor[50];
  char checkprofessor;
  int TAM_ALUNO_POR_DISCIPLIA;
  int *alunos;
  int qtd_aluno;
} Disciplina;

int adicionarAluno();
int adicionarProfessor();
void atualizarAluno();
void listagens();
int excluirAluno();
int excluirDisciplina(Disciplina lista_disciplina[], int qtd_disciplina,
                      Aluno lista_aluno[], int qtd_aluno);
void listagem_disciplina();
int excluirProfessor();
void listagens_professor();
void atualizarProfessor();
void menu_atualizar_disciplina();
void ListarInputProfessor();
void ListarInputAluno();

void CAD_DisciplinaProfessor(Professor lista_professor[],
                             Disciplina lista_disciplina[], int QtdProfessor,
                             int qtd_disciplina, int key_lista_disciplina);

int BuscaSequencialInteira(Aluno lista_aluno[], Disciplina lista_disciplina[],
                           int tamanho, int key, int valor_de_retorno,
                           char option);

void CadastroAlunoDisciplina(int key_disciplina, Disciplina lista_disciplina[],
                             Aluno lista_aluno[], int qtd_disciplina,
                             int qtd_aluno, int tamanho_maximo_disciplina);

void CadastroQuantidadeVagas(Disciplina lista_disciplina[],
                             int key_lista_disciplina);

void ListaDisciplinaDadosCadastros(Disciplina lista_disciplina[],
                                   Aluno lista_aluno[], int qtd_disciplina,
                                   int qtd_aluno);

void ListaDisciplinaVagas(Disciplina lista_disciplina[], int qtd_disciplina);

void ListaAlunoSubMatriculados(Aluno lista_aluno[], int qtd_aluno);

int CadastroDisciplinaNoSistema(Disciplina lista_disciplina[],
                                int qtd_disciplina, Professor lista_professor[],
                                int qtd_professor, int max_qtd_disciplina,
                                Aluno lista_aluno[], int qtd_aluno);

void CadastroNomeDisciplina(int key_lista_disciplina,
                            Disciplina lista_disciplina[]);

int VerificadorDisciplinaInativa(Disciplina lista_disciplina[],
                                 int qtd_disciplina);

void CadastroCodigoDisciplina(Disciplina lista_disciplina[], int qtd_disciplina,
                              int key_lista_disciplina);