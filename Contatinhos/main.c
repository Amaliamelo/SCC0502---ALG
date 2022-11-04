#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "agenda.h"

int main() {    
    //Declarando variaveis
    TipoAgenda A;
    TipoContato contato;
    TipoApontador p;

    CriaAgenda(&A);
	
    char op = '1';
    int x=0;
    
    while(x<100000000) { //limitando o numero de operacoes
        
        scanf(" %c", &op);//lendo operação
        if (op == '0') break;//parando caso operação seja 0
        
        switch(op){
            case 'I'://Operação de Inserir
                scanf("%s", contato.nome);
                scanf("%ld", &contato.numero);
                InsereContato(&A, contato);
                break; 
                
            case 'P'://Operação de Pesquisar
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Contatinho nao encontrado\n");
                } else {
                    TipoApontador p = Pesquisa(&A, contato.nome);
                    printf("Contatinho encontrado: telefone %ld\n", p->contato.numero);
                }
                break;

            case 'A'://Operação de Alterar
                scanf("%s", contato.nome);
                scanf("%ld", &contato.numero);
                
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado\n");
                } else AlteraAgenda(&A, contato);
                break;
            
            case 'R'://Operação de Remover
                scanf("%s", contato.nome);
                if(Pesquisa(&A, contato.nome)==NULL){
                    printf("Operacao invalida: contatinho nao encontrado\n");
                } else Remove(&A, contato.nome);
                break;
            case 'K'://teste para ver o que esta sendo guardado na agenda
                ImprimeAgenda(&A);
                break;
            default:
                printf("Operação invalida\n");
        }

        //x=x+1;*/
        //printf("%d,", x++);
    }
	

    while(p!=NULL){
        A.primeiro = p->prox;
        printf("Limpando\n");
        free(p);
        p=A.primeiro;
    }

	return 0;
}