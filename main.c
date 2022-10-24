#include<stdio.h>
#include<stdlib.h>
#include "agenda.h"

int main() {    
    TipoAgenda A;
    TipoContato contato;
    TipoApontador p;

    CriaAgenda(&A);
	
    char op = '1';
    while(op != 0) {
        
        scanf("%s", &op);
        
        if (op == '0') break;
        
        switch(op){
            case 'I':
                scanf("%s", contato.nome);
                scanf("%ld", &contato.numero);
                InsereContato(&A, contato);
                break; 
            case 'P':
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado");
                } else {
                    printf("Contatinho encontrado: telefone %ld\n", contato.numero);
                }
                break;

            case 'A':
                scanf("%s", contato.nome);
                scanf("%ld", &contato.numero);
                
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
            
            default:
                printf("Operação invalida\n");
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