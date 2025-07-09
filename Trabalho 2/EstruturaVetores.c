#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

EstruturaAuxiliar *vetorPrincipal[TAM];

void ordenaVetor(int vetorAux[], int posicoes)
{
    int temp;

    for (int i = 0; i < posicoes - 1; i++)
    {
        for (int j = 0; j < posicoes - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                temp = vetorAux[j + 1];
                vetorAux[j + 1] = vetorAux[j];
                vetorAux[j] = temp;
            }
        }
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;
    if (tamanho < 1)
        return TAMANHO_INVALIDO;
    if (vetorPrincipal[posicao] != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    EstruturaAuxiliar *nova = malloc(sizeof(EstruturaAuxiliar));
    if (!nova)
        return SEM_ESPACO_DE_MEMORIA;

    nova->dados = malloc(tamanho * sizeof(int));
    if (!nova->dados) 
    {
        free(nova);
        return SEM_ESPACO_DE_MEMORIA;
    }

    nova->tamanho = tamanho;
    nova->quantidade = 0;
    nova->posicao = posicao;
    vetorPrincipal[posicao] = nova;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao--;


    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;
        
    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    if (estrutura->quantidade >= estrutura->tamanho)
        return SEM_ESPACO;
    
    estrutura->dados[estrutura->quantidade++] = valor;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];
    
    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    if (!estrutura->quantidade)
        return ESTRUTURA_AUXILIAR_VAZIA;
    
    estrutura->quantidade--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];
    
    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    if (!estrutura->quantidade)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int i = 0, encontrado = 0;
    while (i < estrutura->quantidade)
    {
        if (estrutura->dados[i] == valor)
        {
            encontrado = 1;
            break;
        }
        i++;    
    }
    if (!encontrado)
        return NUMERO_INEXISTENTE;
    
    for (int j = i; j < estrutura->quantidade - 1; j++)
    {
        estrutura->dados[j] = estrutura->dados[j + 1];
    }
    estrutura->quantidade--;

    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < estrutura->quantidade; i++) 
    {
        vetorAux[i] = estrutura->dados[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < estrutura->quantidade; i++) 
    {
        vetorAux[i] = estrutura->dados[i];
    }

    ordenaVetor(vetorAux, estrutura->quantidade);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i = 0, vazias = 1, cont = 0;
    while (i < TAM)
    {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->dados != NULL && vetorPrincipal[i]->quantidade > 0)
        {
            vazias = 0;
            break;
        }
        i++;
    }
    if (vazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int j = 0; j < TAM; j++)
    {
        if (vetorPrincipal[j] != NULL && vetorPrincipal[j]->dados != NULL)
        {
            for (int k = 0; k < vetorPrincipal[j]->quantidade; k++)
            {
                vetorAux[cont++] = vetorPrincipal[j]->dados[k];
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i = 0, vazias = 1, cont = 0, totalPosicoes = 0;
    while (i < TAM)
    {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->dados != NULL && vetorPrincipal[i]->quantidade > 0)
        {
            vazias = 0;
            break;
        }
        i++;
    }
    if (vazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int j = 0; j < TAM; j++)
    {
        if (vetorPrincipal[j] != NULL && vetorPrincipal[j]->dados != NULL)
        {
            for (int k = 0; k < vetorPrincipal[j]->quantidade; k++)
            {
                vetorAux[cont++] = vetorPrincipal[j]->dados[k];
            }
            totalPosicoes += vetorPrincipal[j]->quantidade;
        }
    }
    
    ordenaVetor(vetorAux, totalPosicoes);
    
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;
    
    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int novo_tam = estrutura->tamanho + novoTamanho;

    if (novo_tam < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *temp = realloc(estrutura->dados, novo_tam * sizeof(int));
    if (!temp)
        return SEM_ESPACO_DE_MEMORIA;

    estrutura->dados = temp;    
    estrutura->tamanho = novo_tam;

    if (estrutura->quantidade > novo_tam)
        estrutura->quantidade = novo_tam;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;

    if (posicao < 0 || posicao >= TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao];
    
    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    if (!estrutura->quantidade)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return estrutura->quantidade;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabecote = malloc(sizeof(No));
    if (!cabecote)
        return NULL;

    cabecote->prox = NULL;

    No *ultimo = cabecote;
    int existeValor = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->quantidade > 0)
        {
            for (int j = 0; j < vetorPrincipal[i]->quantidade; j++)
            {
                No *novo = malloc(sizeof(No));
                if (!novo)
                {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }
                novo->conteudo = vetorPrincipal[i]->dados[j];
                novo->prox = NULL;
                ultimo->prox = novo;
                ultimo = novo;
                existeValor = 1;
            }
        }
    }

    if (!existeValor)
    {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (inicio == NULL)
    return;

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL)
    {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL)
    return;

    No *atual = *inicio;
    while (atual != NULL)
    {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            free(vetorPrincipal[i]->dados);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}