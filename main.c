// inclusão das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>

// tamanhos máximos pré-definidos
#define MAX 10
#define SIZE 20

// arquivos
#define NOME_ARQUIVO_ENTRADA "entrada.txt"
#define NOME_ARQUIVO_SAIDA "saida.txt"

// tipos de nós que existem
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
    itemEssencial // item genérico para inicializar o invent�rio

} itensEssenciais;

// itens raros
typedef enum _itensRaros
{
    malvinao,
    barrinhaDeCereal,
    faca,
    itemRaro // item genérico para inicializar o invent�rio
} itensRaros;

// variável que indica a opção que eu selecionei em um nó e para qual nó essa oção leva
typedef struct _opcao
{
    char opcaoSelecionada;
    int indiceProximoNo;
} opcao;

// nó propriamente dito e suas características
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

// ponteiros de nós que apontam para o nó raiz e o ponteiro que estamos atualmente
no *ptrInicio;
no *ptrAtual;

// arquivo de saída
FILE *arquivoSaida;

// variáveis globais
int moedas;
int counterFO = 0;
int counterAtividades = 0;
int counterItensRaros = 0;

// inventórios
itensEssenciais inventarioEssencial[6] = {itemEssencial, itemEssencial, itemEssencial, itemEssencial, itemEssencial, itemEssencial};
itensRaros inventarioRaro[3] = {itemRaro, itemRaro, itemRaro};

// protótipos
char *lerNomeJogador(char *nomeArquivo);
void cadastrarNo(int indice, tipoNo tipo, opcao *opcoes, int nOpcoes, char *texto);
void cadastrarNos();
no *buscarNo(int indice);
int lerIndiceProximoNo(char opcao);
int isCompra(int indice);
int compra(int indice, int moedas, char opcao, itensEssenciais *inventarioEssencial, itensRaros *inventarioRaro);
int isValendoFO(int indice);
int isValendoItem(int indice);
int verificarItemEssencial(int indice, itensEssenciais *inventarioEssencial);
int verificarItemRaro(int indice, itensRaros *inventarioRaro);
int isFoundable(int indice);
void addItemRaro(itensRaros *inventarioRaro, int indice);
void addItemEssencial(itensEssenciais *inventarioEssencial);
void limparTela();
void readItensRaros(itensRaros *inventarioRaro, int *counterItensRaros, int *counterFO);
void printInventarioEssencial(itensEssenciais *inventarioEssencial);
void printInventarioRaro(itensRaros *inventarioRaro);
