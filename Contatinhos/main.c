#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "agenda.h"

int main() {    
    TipoAgenda A;
    TipoContato contato;
    TipoApontador p;

    CriaAgenda(&A);
	
    char op = '1';
 
    while(op != 0) {
        
        scanf("%s", &op);
        //toupper(op);
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
                    printf("Contatinho nao encontrado\n");
                } else {
                    TipoApontador p = Pesquisa(&A, contato.nome);
                    printf("Contatinho encontrado: telefone %ld\n", p->contato.numero);
                }
                break;

            case 'A':
                scanf("%s", contato.nome);
                scanf("%ld", &contato.numero);
                
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado\n");
                } else AlteraAgenda(&A, contato);
                break;
            
            case 'R':
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado\n");
                } else Remove(&A, contato.nome);
                break;
            case 'K':
                ImprimeAgenda(&A);
                break;
            case '0':
                exit(0);
            default:
                printf("Operação invalida\n");
        }
    }
	

    /*while(p!=NULL){
        A.primeiro = p->prox;
        printf("Limpando\n");
        free(p);
        p=A.primeiro;
    }*/

	return 0;
}
 
 /*   
    scanf("%s", &op);
    while(op!='0'){
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
                } else AlteraAgenda(&A, contato );
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
	

    return 0;
}
*/
