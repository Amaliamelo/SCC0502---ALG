#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agenda.h"

void CriaAgenda(TipoAgenda *A){
	A->ultimo = NULL;    
    A->primeiro = NULL;
    //printf("Agenda Criada!\n");
}

void InsereContato(TipoAgenda *A, TipoContato C){
    // Inserção no finalda lista 
    // Cria um novo contato
    TipoApontador novo; 
    novo=(TipoApontador) malloc(sizeof(TipoNo));

    if(novo==NULL){ //significa problema de memoria cheia
        printf("Memoria Lotada\n");
        return;
    }

   // Pesquisar se nome já existe na agenda
    if(Pesquisa(A,C.nome)!=NULL){ //caso já existe o contato
        printf("Contatinho ja inserido");
        return;
    }
    else{
        novo->contato = C;
        novo->prox = NULL;

        if(AgendaVazia(&A)){
            A->primeiro = novo;
            A->ultimo = novo;
        }else{
            A->ultimo->prox = novo;
            A->ultimo = novo;
        }
    }
}

static int RemovePosicao(TipoAgenda *A, TipoApontador p){
    if(p==NULL){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return 1;
    }

    //unico elemento
    if( p==A->primeiro && p == A->ultimo){
        CriaAgenda(p);
        free(p);
        return 0;
    }

    //remove do inicio
    if( p==A->primeiro){
       A->primeiro = A->primeiro->prox;
       free(p);
       return 0;
    }

   // remove meio
    TipoApontador aux = A->primeiro; 
    while(aux->prox != NULL && aux->prox != p){
        aux = aux->prox;
        //indo pra frente até o auxiliar apontar para o anterio de p
    }
    aux->prox=p->prox;

    //remove fim
    if(aux->prox==NULL){
        A->ultimo=aux;
    }

    free(p);
    return 0;
}

void Remove(TipoAgenda *A, char N){
    TipoApontador p = Pesquisa(A,N);
    int posicao = RemovePosicao(A,p);
    if(posicao==1){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return;
    }

}

TipoApontador Pesquisa(TipoAgenda *A, TipoNome N){

    TipoApontador p;
    p = A->primeiro;

    if(p == NULL) return NULL;

    while(p!=NULL){
        if(strcmp(p->contato.nome, N)==0){
            return p;
        }
        p=p->prox;
    }
    return p;
}

char AgendaVazia(TipoAgenda *A){ //verificar se o ultimo e o primeiro apontam para null
    return A->ultimo == NULL && A->primeiro==NULL;
}


void AlteraAgenda(TipoAgenda *A, char N, TipoNumero Numero){
    TipoApontador p = Pesquisa(A,N);

    if(p!=NULL)
        p->contato.numero=Numero;
        return;

} 

 /*void ImprimeAgenda(TipoAgenda *A){
     TipoApontador p = A->primeiro;
     int i=0;
     while(p != NULL){
         if(p->prox != NULL){
             printf("%d: Chave = %d, Proximo = %d\n", i, p->contato.nome, p->prox->contato.nome);
         }
         else{
             printf("%d: Chave = %d, Proximo =Nulo\n", i, p->contato.nome);
         }
         p=p->prox;
         i++;
     }
 }*/

