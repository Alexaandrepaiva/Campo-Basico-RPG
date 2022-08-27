// inclus�o das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>

// tamanhos m�ximos pr�-definidos
#define MAX 10
#define SIZE 20

// arquivos
#define NOME_ARQUIVO_ENTRADA "entrada.txt"
#define NOME_ARQUIVO_SAIDA "saida.txt"

// tipos de n�s que existem
typedef enum _tipoNo
{
    raiz,
    naoTerminal,
    terminal
} tipoNo;

// itens essenciais
typedef enum _itensEssenciais
{
    sacoImpermeavel,
    lanterna,
    caboSolteiro,
    caderno,
    itemEssencial // item gen�rico para inicializar o invent�rio

} itensEssenciais;

// itens raros
typedef enum _itensRaros
{
    malvinao,
    barrinhaDeCereal,
    faca,
    itemRaro // item gen�rico para inicializar o invent�rio
} itensRaros;

// vari�vel que indica a op��o que eu selecionei em um n� e para qual n� essa op��o leva
typedef struct _opcao
{
    char opcaoSelecionada;
    int indiceProximoNo;
} opcao;

// n� propriamente dito e suas caracter�sticas
typedef struct _no
{
    int indice;
    tipoNo tipo;
    opcao opcoes[MAX];
    int nOpcoes;
    char texto[1001];
    struct _no *anterior;
    struct _no *proximo;
} no;

// ponteiros de n�s que apontam para o n� raiz e o ponteiro que estamos atualmente
no *ptrInicio;
no *ptrAtual;

// arquivo de sa�da
FILE *arquivoSaida;

// vari�veis globais
int moedas;
int counterFO = 0;
int counterAtividades = 0;
int counterItensRaros = 0;