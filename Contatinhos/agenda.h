#ifndef AGENDA_H
#define AGENDA_H


typedef char TipoNome[10];
Typedef char TipoNumero[9];

typedef struct {
    TipoNome nome;
    TipoNumero Numero;
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
TipoApontador BuscaContato(TipoAgenda *A, TipoNome N);

char AgendaVazia(TipoAgenda *A);
char AgendaCheia (TipoAgenda *A);

void ImprimeAgenda(TipoAgenda *A);

#endif