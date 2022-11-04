#include "pila_filha.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;
///////////////////
//////FILA/////////
///////////////////

void criar_f(t_conjunto *conjunto) {//criando a fila;

	conjunto->primeiro = NULL;
	conjunto->ultimo = NULL;
}

int enfileirar(t_conjunto *conjunto, t_elemento elemento) {
	//enfileirando de acordo com o FIFO

	t_apontador novo;
    novo = (t_apontador) malloc(sizeof(t_no));

	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = NULL;
	
	if (vazia_f(conjunto)) {//verificar se está vazia
		conjunto->primeiro = novo;
	} 
    else {
		conjunto->ultimo->proximo = novo;
	}
	conjunto->ultimo = novo;

	return 0;
}
int desenfileirar(t_conjunto *conjunto, t_elemento elemento) {
    //Função para remover elementos da fila (FIFO)


	if (vazia_f(conjunto)){//verificar se está vazia
		return 1;
    }
	if (conjunto->primeiro->elemento.chave != elemento.chave) {//elemento não existe
    	return 1;
  	}
	if (conjunto->primeiro == conjunto->ultimo){ // unitaria
		conjunto->ultimo = NULL;
    }

	t_apontador aux = conjunto->primeiro;
	conjunto->primeiro = conjunto->primeiro->proximo;
	free(aux);

	return 0;

}
int vazia_f(t_conjunto *conjunto) {//função para verificar se a fila está vazia
	if(conjunto->primeiro == NULL && conjunto->ultimo == NULL){
		return 1;
    }
	else{
		return 0;
    }
}
///////////////////
//////PILHA////////
///////////////////
void criar_p(t_conjunto *conjunto) {//criar pilha
	conjunto->topo = NULL;
	num_nos = 0;
}
int empilhar(t_conjunto *conjunto, t_elemento elemento) {
	//empilhando de acordo com o LIFO
	t_apontador novo;
    novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;
	novo->elemento = elemento;
	novo->proximo = conjunto->topo;
	conjunto->topo = novo;

	num_nos++;//incrementando número de nos que será usado para liberar a pilha posteriormente

	return SUCESSO;
}

int desempilhar(t_conjunto *conjunto) {
	//desempilhar pilha de acordo com o LIFO
	if (vazia_p(conjunto)){
		return NAO_ENCONTROU;
    }
	t_apontador aux = conjunto->topo;
	int elem = aux->elemento.chave;//elemento que será usado na função de liberar a pilha
	conjunto->topo = conjunto->topo->proximo;
	free(aux);

	num_nos--;//descrementando número de nos que será usado para liberar a pilha posteriormente
	return elem;
}

int vazia_p(t_conjunto *conjunto) {//função para verificar se a pilha está vazia
	if(conjunto->topo == NULL)
		return 1;
	else
		return 0;
}
void libera_f(t_conjunto *conjunto) {//liberando fila
  t_apontador P = conjunto->primeiro;
  while (P != NULL) {
    conjunto->primeiro = P->proximo;
	free(P);
    P = conjunto->primeiro;
  }
}
void libera_p(t_conjunto *conjunto) {//liberando pilha
	for(int i = num_nos; i > 0; i--){
		desempilhar(conjunto);//liberando todo o laço com a função desempilhar
	}		
}