#include<stdio.h>
#include<stdlib.h>
#include "agenda.h"


int main() {    
    TipoAgenda A;
    TipoContato contato;
    TipoApontador p;

    CriaAgenda(&A);
	
    char op;
    scanf("%s", &op);
    switch(op){
        case 'I':
            scanf("%s", contato.nome);
            scanf("%s", contato.numero);
            InsereContato(&A, contato);
            break; 
        case 'P':
            scanf("%s", contato.nome);
            if(Pesquisa(&A, contato.nome)==NULL){
                printf("Operacao invalida: contatinho nao encontrado");
            }
        break;
        case 'A':
            scanf("%s", contato.nome);
            scanf("%s", contato.numero);
            if(Pesquisa(&A, contato.nome)==NULL){
                printf("Operacao invalida: contatinho nao encontrado");
            }
            else{
                
            }
        break;
        case 'R':
        break;
        case '0':
        break;

    }
	

    /*while(p!=NULL){
        A.primeiro = p->prox;
        printf("Limpando\n");
        free(p);
        p=A.primeiro;
    }*/

	return 0;
}

