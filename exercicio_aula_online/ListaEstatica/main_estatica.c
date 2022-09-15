#include<stdio.h>
#include<stdlib.h>
#include "ListaEstatica.h"

int main() {    
    TipoLista L;
    TipoItem item;

    CriaLista(&L);

	printf("Lista vazia? %d\n", ListaVazia(&L));
	
    item.chave = 5;
    Insere(&L, item);

	item.chave = 1;
    Insere(&L, item);

	ImprimeLista(&L);

    item.chave = 3;
    Insere(&L, item);
	
    item.chave = 0;
    Insere(&L, item);

	ImprimeLista(&L);
	
	//PesquisaLista(&L, 5);
	
    Remove(&L, 3);
    Remove(&L, 5);
	
	ImprimeLista(&L);
	
	item.chave = 15;
    Insere(&L, item);
	
	ImprimeLista(&L);
	
	Remove(&L, 15);
	
	ImprimeLista(&L);


	return 0;
}

