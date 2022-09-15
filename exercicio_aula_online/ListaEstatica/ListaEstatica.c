#include<stdio.h>
#include "ListaEstatica.h"

void CriaLista(TipoLista *L){
    L->ultimo = -1; //para não jogar lixo na main
    printf("Deu certo!\n");
}

int Insere(TipoLista *L, TipoItem I){
    //Inserção por ultimo
    if(ListaCheia(L)){
        printf("Inválida operacao de inserir!\n");
        return LISTA_CHEIA;
    }

    L->ultimo++; //passandoo ultimo pra frente
    L->itens[L->ultimo]= I; //inserindo item na posição ultimo
}


static int RemovePosicao(TipoLista *L, TipoApontador P){
    TipoApontador a;
    if(P < 0 || P >= L->ultimo){
        printf("Posicao Invalida\n");
        return POS_INVALIDA;
    }
    for(a = P;a < L->ultimo; a++){
        //fazendo uma copia dos elementos da frente do que sera removido
        L->itens[a]=L->itens[a+1];
    }
    L->ultimo--;
}

int Remove(TipoLista *L, TipoChave C){
    RemovePosicao(L, Pesquisa(L,C));
}

TipoApontador Pesquisa(TipoLista *L, TipoChave C){
    TipoApontador a;
    for(a=0; a<=L->ultimo; a++){
        //verificando se foi achaou
        if(L->itens[a].chave == C){
            return a;
        }
    }

    return NAO_ENCONTROU;
}

char ListaVazia(TipoLista *L){
    //verificando se o ponteiro está com -1, lista só criada
    return L->ultimo == -1;
}
char ListaCheia (TipoLista *L){
    //verificando se o ponteiro esta apontando para o tamanha máximo
    return L->ultimo == MAXTAM -1;
}

void ImprimeLista(TipoLista *L){
    TipoApontador a;
    printf("Lista:");
    for(a=0; a<=L->ultimo; a++){
        printf("%d ", L->itens[a].chave);
    }
    printf("\n\n");
}

