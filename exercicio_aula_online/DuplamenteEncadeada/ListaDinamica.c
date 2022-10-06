#include<stdio.h>
#include<stdlib.h>
#include "ListaDinamica.h"

void CriaLista(TipoLista *L){
	(*L).ultimo = NULL;    
    (*L).primeiro = NULL;
    printf("Deu certo!\n");
}

int Insere(TipoLista *L, TipoItem I){
    //Inserção no final

    TipoApontador p; //criando o ponteiro
    p=(TipoApontador) malloc(sizeof(TipoNo));//

    if(p==NULL){// significa problema de memoria cheia
        printf("Memoria Lotada\n");
        return LISTA_CHEIA;     
    }

    p->item = I;
    p->ant = NULL;
    if(ListaVazia(L)){//lista vazia
        L->primeiro = p;
        L->ultimo = p;
        p->prox = NULL;
    }else if (L->primeiro->item.chave>I.chave){  //primeira posicao
        p->prox = L->primeiro;
        L->primeiro->ant= p;
        L->primeiro = p;

    }else{ //todos os demais
        TipoApontador aux;
        aux = L -> primeiro;
        while(aux->prox != NULL && aux->prox->item.chave<I.chave){
            aux=aux->prox;
        }
        p->prox=aux->prox;
        p->ant=aux;
        aux->prox =p;
        p->prox->ant=p;
    }

    /*
    p->prox = NULL;

    if(ListaVazia(L)){
        L->primeiro = p;
        L->ultimo = p;
    }else{
        L->ultimo->prox = p;
        L->ultimo = p;
    }*/
        return 0;


}

static int RemovePosicao(TipoLista *L, TipoApontador p){
    if(p==NULL){
        printf("Posicao Invalida\n");
        return POS_INVALIDA;
    }

    //unico elemento
    if( p==L->primeiro && p == L->ultimo){
        TipoLista P;
        CriaLista(&P);
        free(p);
        return SEM_ERRO;
    }

    //remove do inicio
    if( p==L->primeiro){
       L->primeiro = L->primeiro->prox;
       L->primeiro->ant=NULL;
       free(p);
       return SEM_ERRO;
    }

    //remove meio
   /* TipoApontador aux = L->primeiro; 
    while(aux->prox != NULL && aux->prox != p){
        aux = aux->prox;
        //indo pra frente até o auxiliar apontar para o anterio de p
    }*/

    p->ant->prox = p->prox; //pulando uma caixinha

    //remove fim
    if(p==L->ultimo){
        L->ultimo=p->ant;
    }
    else{
        p->prox->ant = p->ant;
    }

    free(p);
    return SEM_ERRO;
}

int Remove(TipoLista *L, TipoChave C){
    TipoApontador p = Pesquisa(L,C);
    int e = RemovePosicao(L,p);
    if(e==POS_INVALIDA){
        printf("Invalido\n");
    }
    else{
        printf("Removido com sucesso\n");
    }
    return 0;
}



TipoApontador Pesquisa(TipoLista *L, TipoChave C){
    TipoApontador p;

    p = L->primeiro;

    while(p!=NULL){
        if(p->item.chave==C){
            return p;
        }

        p=p->prox;
    }

    return p;
}

char ListaVazia(TipoLista *L){// verificar se o ultimo e o primeiro apontam para null
    return L->ultimo == NULL && L->primeiro==NULL;
}

void ImprimeLista(TipoLista *L){
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

void ImprimeListaInvertida(TipoLista *L){
    TipoApontador p = L->ultimo;
    int i=0;
    while(p != NULL){
        if(p->ant != NULL){
            printf("%d: Chave = %d, Proximo = %d\n", i, p->item.chave, p->prox->item.chave);
        }
        else{ 
            printf("%d: Chave = %d, Proximo =Nulo\n", i, p->item.chave);
        }
        p=p->ant;
        i++;
    }
}
