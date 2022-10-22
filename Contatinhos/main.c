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
    while(op!='0'){
        switch(op){
            case 'I':
                scanf("%s", contato.nome);
                scanf("%d", &contato.numero);
                InsereContato(&A, contato);
                break; 
            case 'P':
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado");
                }else Pesquisa(&A, contato.nome);
            break;
            case 'A':
                scanf("%s", contato.nome);
                scanf("%d", &contato.numero);
                
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado");
                } else AlteraAgenda(&A, contato.nome, contato.numero );
            break;
            
            case 'R':
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado");
                } else Remove(&A, contato.nome);
            break;
            case '0':
                exit(0);
            break;

        }
        scanf("%s ", &op);
    }
	

    /*while(p!=NULL){
        A.primeiro = p->prox;
        printf("Limpando\n");
        free(p);
        p=A.primeiro;
    }*/

	return 0;
}

