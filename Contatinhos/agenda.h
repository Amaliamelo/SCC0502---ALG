#ifndef AGENDA_H
#define AGENDA_H


typedef char TipoNome[12];
typedef long int TipoNumero;

typedef struct {
    TipoNome nome;
    TipoNumero numero;
}TipoContato;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
    TipoContato contato;
    //struct TipoNo *prox;
    TipoApontador prox;
} TipoNo;

typedef struct{
    TipoApontador ultimo, primeiro;
}TipoAgenda;

void CriaAgenda(TipoAgenda *A);
void InsereContato(TipoAgenda *A, TipoContato C);
void Remove(TipoAgenda *A, TipoNome N);
TipoApontador Pesquisa(TipoAgenda *A, TipoNome N);
char AgendaVazia(TipoAgenda *A);
void AlteraAgenda(TipoAgenda *A, TipoContato C);

char AgendaCheia (TipoAgenda *A);

void ImprimeAgenda(TipoAgenda *A);

#endif