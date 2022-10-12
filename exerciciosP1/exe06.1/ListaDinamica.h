#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H


#define SEM_ERRO 0
#define REARRANJOU 2
#define POS_INVALIDA -1
#define NAO_ENCONTROU NULL
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
void Insere(TipoLista *L, TipoItem I);
void Remove(TipoLista *L, TipoChave C);
TipoApontador  Pesquisa(TipoLista *L, TipoChave C);
//void Rearranja(TipoLista *L);
char ListaVazia(TipoLista *L);
char ListaCheia (TipoLista *L);

void ImprimeLista(TipoLista *L);

#endif


