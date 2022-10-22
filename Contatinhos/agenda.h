#ifndef AGENDA_H
#define AGENDA_H


typedef char TipoNome;
typedef int TipoNumero;

typedef struct {
    TipoNome nome[10];
    TipoNumero numero;
}TipoContato;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
    TipoContato contato;
    struct TipoNo *prox;
} TipoNo;

typedef struct{
    TipoApontador ultimo, primeiro;
}TipoAgenda;

void CriaAgenda(TipoAgenda *A);
void InsereContato(TipoAgenda *A, TipoContato C);
void RemoveContato(TipoAgenda *A, TipoNome N);
TipoApontador Pesquisa(TipoAgenda *A, TipoNome N);
char AgendaVazia(TipoAgenda *A);
void AlteraAgenda(TipoAgenda *A, TipoNome N, TipoNumero Numero);

char AgendaCheia (TipoAgenda *A);

void ImprimeAgenda(TipoAgenda *A);

#endif