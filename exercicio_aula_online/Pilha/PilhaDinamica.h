#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H


#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU null
#define PILHA_CHEIA -3

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
    TipoApontador primeiro;
}TipoPilha;

void CriaPilha(TipoPilha *P);
int Insere(TipoPilha *P, TipoItem I);
void Remove(TipoPilha *P);
TipoItem TopoPilha(TipoPilha *P);
char PilhaVazia(TipoPilha *P);
char PilhaCheia (TipoPilha *P);

void ImprimePilha(TipoPilha *P);

#endif