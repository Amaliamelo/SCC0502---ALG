#include<stdio.h>
#include "ListaEstatica.h"

void CriaLista(TipoLista *L){
    L->ultimo = -1; //para não jogar lixo na main
    printf("Deu certo!\n");
}

int Insere(TipoLista *L, TipoItem I){
    
}
int Remove(TipoLista *L, TipoChave C);
int Pesquisa(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia (TipoLista *L);

void ImprimeLista(TipoLista *L);

