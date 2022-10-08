#include<stdio.h>
#include<stdlib.h>
#include "PilhaDinamica.h"

int main() {    
    TipoPilha P;
    TipoItem item;

    CriaPilha(&P);
	
    item.chave = 5;
    Insere(&P, item);

	item.chave = 1;
    Insere(&P, item);

	ImprimePilha(&P);

    item.chave = 3;
    Insere(&P, item);
	
    item.chave = 0;
    Insere(&P, item);

    item.chave = 25;
    Insere(&P, item);

    item.chave = -3;
    Insere(&P, item);

	ImprimePilha(&P);
	
	item = TopoPilha(&P);
    printf("Topo = %d\n", item.chave);
	
    Remove(&P);
    Remove(&P);
    Remove(&P);

	ImprimePilha(&P);

    while(!PilhaVazia(&P))
        Remove(&P);
	return 0;
}

