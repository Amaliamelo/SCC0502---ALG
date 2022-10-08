#include<stdio.h>
#include<stdlib.h>
#include "PilhaDinamica.h"

void CriaPilha(TipoPilha *P){
    (*P).primeiro = NULL;
    printf("Deu certo!\n");
}

int Insere(TipoPilha *P, TipoItem I){
    //Inserção no final

    TipoApontador p; //criando o ponteiro
    p=(TipoApontador) malloc(sizeof(TipoNo));//

    if(p==NULL){// significa problema de memoria cheia
        printf("Memoria Lotada\n");
        return PILHA_CHEIA;
    }

    p->item = I;
    
    if(PilhaVazia(P)){
        p->prox= NULL;
        P->primeiro = p;
        
    }else{
        p->prox = P->primeiro;
        P->primeiro = p;
    }

    return SEM_ERRO;

}


void Remove(TipoPilha *P){

   if(PilhaVazia(P)){
        printf("nao deu\n");
        return;
   }

    if(P->primeiro->prox == NULL){
        free(P->primeiro);
        CriaPilha(P);
        return;
    }

    TipoApontador p = P->primeiro;
    P->primeiro = P->primeiro->prox;
    free(p);
}

TipoItem TopoPilha(TipoPilha *P){
    if(!PilhaVazia(P)){
        return P->primeiro->item;
    }
    TipoItem I;
    I.chave = -1;
    return I;
}

char PilhaVazia(TipoPilha *P){// verificar se o ultimo e o primeiro apontam para null
    return P->primeiro==NULL;
}

char PilhaVazia(TipoPilha *P);

void ImprimePilha(TipoPilha *P){
    TipoApontador p = P->primeiro;
    int i=0;
    while(P != NULL){
        if(p->prox != NULL){
            printf("%d: Chave = %d, Proximo = %d\n", i, p->item.chave, p->prox->item.chave);
        }
        else{
            printf("%d: Chave = %d, Proximo =Nulo\n", i, p->item.chave);
        }
        p=p->prox;
        i++;
    }
}

