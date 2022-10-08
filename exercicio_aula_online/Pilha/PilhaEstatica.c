#include<stdio.h>
#include "PilhaEstatica.h"

void CriaPilha(TipoPilha *P){
    P->ultimo = -1; //para não jogar lixo na main
    printf("Deu certo!\n");
}

int Insere(TipoPilha *P, TipoItem I){
    //Inserção por ultimo
    if(PilhaCheia(P)){
        printf("Inválida operacao de inserir!\n");
        return Pilha_CHEIA;
    }

    P->ultimo++; //passandoo ultimo pra frente
    P->itens[P->ultimo]= I; //inserindo item na posição ultimo
}


int Remove(TipoPilha *P){
    if(PilhaVazia(P)){
        P->ultimo--;
    }
}

TipoItem TopoPilha(TipoPilha *P){
    if(!PilhaVazia(P)){
        return P->itens[P->ultimo];
    }
    TipoItem I;
    I.chave = -1;
    return I;
}

char PilhaVazia(TipoPilha *P){
    //verificando se o ponteiro está com -1, Pilha só criada
    return P->ultimo == -1;
}
char PilhaCheia (TipoPilha *P){
    //verificando se o ponteiro esta apontando para o tamanha máximo
    return P->ultimo == MAXTAM -1;
}

void ImprimePilha(TipoPilha *P){
    TipoApontador a;
    printf("Pilha:");
    for(a=P->ultimo; a>=0; a--){
        printf("%d ", P->itens[a].chave);
    }
    printf("\n\n");
}

