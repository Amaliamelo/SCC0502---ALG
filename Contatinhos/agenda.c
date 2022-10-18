#include<stdio.h>
#include<stdlib.h>
#include "agenda.h"

void CriaAgenda(TipoAgenda *A){
	A->ultimo = NULL;    
    A->primeiro = NULL;
    //printf("Agenda Criada!\n");
}

void InsereContato(TipoAgenda *A, TipoNome N){
    //Inserção no finalda lista 

    TipoApontador p; //criando o ponteiro
    p=(TipoApontador) malloc(sizeof(TipoNo));//

    if(p==NULL){// significa problema de memoria cheia
        printf("Memoria Lotada\n");
        return Agenda_CHEIA;
    }

    //Pesquisar se nome já existe na agenda
    TipoApontador busca = Pesquisa(A,N);



    p->contato = C;
    p->prox = NULL;

    if(AgendaVazia(L)){
        A->primeiro = p;
        A->ultimo = p;
    }else{
        A->ultimo->prox = p;
        A->ultimo = p;
    }

}

static int RemovePosicao(TipoAgenda *A, TipoApontador p){
    if(p==NULL){
        printf("Posicao Invalida\n");
        return POS_INVALIDA;
    }

    //unico elemento
    if( p==L->primeiro && p == L->ultimo){
        CriaAgenda(&p);
        free(p);
        return SEM_ERRO;
    }

    //remove do inicio
    if( p==L->primeiro){
       L->primeiro = L->primeiro->prox;
       free(p);
       return SEM_ERRO;
    }

    //remove meio
    TipoApontador aux = L->primeiro; 
    while(aux->prox != NULL && aux->prox != p){
        aux = aux->prox;
        //indo pra frente até o auxiliar apontar para o anterio de p
    }

    aux->prox=p->prox;

    //remove fim
    if(aux->prox==NULL){
        L->ultimo=aux;
    }

    free(p);
    return SEM_ERRO;
}

void Remove(TipoAgenda *A, TipoNome N){
    TipoApontador p = Pesquisa(A,N);
    int posicao = RemovePosicao(A,p);
    if(posicao==POS_INVALIDA){
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
}



TipoApontador Pesquisa(TipoAgenda *A, TipoNome N){
    TipoApontador p;

    p = A->primeiro;

    while(p!=NULL){
        if(p->contato.nome==N){
            return p;
        }

        p=p->prox;
    }

    return p;
}

char AgendaVazia(TipoAgenda *A){// verificar se o ultimo e o primeiro apontam para null
    return A->ultimo == NULL && A->primeiro==NULL;
}

void ImprimeAgenda(TipoAgenda *A){
    TipoApontador p = L->primeiro;
    int i=0;
    while(p != NULL){
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

