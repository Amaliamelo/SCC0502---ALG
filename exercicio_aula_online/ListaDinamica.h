#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H


#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU null
#define LISTA_CHEIA -3

typedef int TipoChave;


typedef struct {
    TipoChave chave;
    //char nome[50];
}TipoItem;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
    TipoItem item;
    struct TipoNo *prox;
} TipoNo;

typedef struct{
    TipoApontador ultimo, primeiro;
}TipoLista;

void CriaLista(TipoLista *L);
int Insere(TipoLista *L, TipoItem I);
int Remove(TipoLista *L, TipoChave C);
TipoApontador  Pesquisa(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia (TipoLista *L);

void ImprimeLista(TipoLista *L);

#endif