#include "pila_filha.h"
#include <stdio.h>
int main() {
    
    t_conjunto pilha, fila;
    t_elemento e;
    t_apontador p;
    t_no no;

    int nc, nop, i, j;
    int r_pilha, r_fila, erro_pilha=0;
    char op;
    scanf("%d", &nc);//recebendo o número de casos
    int vet[nc];
    for (i = 0; i < nc; i++) {
        //criando as estruturas
        criar_f(&fila);
        criar_p(&pilha);
        scanf("%d", &nop);//recebendo o número de operações
        for (j = 0; j < nop; j++) {
            scanf(" %c %d", &op, &e.chave);//recebendo a operação e o elemento de cada iteração do for
            if(op=='i'){
                //empilhando e desenfileirando caso seja inserção
                empilhar(&pilha, e);
                enfileirar(&fila, e);
            }
            else if(op=='r'){//remoção
                //no caso da pilha, receber o retorno da função através da variável "r_pilha",
                // em que será possível
                //verificar se algum elemento não condiz com a estrutura da função
                //caso não, a variável "erro_pilha" receberá um valor que será usado posteriormente 
                //na comparação
                r_pilha = desempilhar(&pilha);
                if(r_pilha != e.chave){
                    erro_pilha = 1;
                }
                //no caso da fila, só foi necessário que "r_fila" recebesse 1 ou 0 indicando 
                //se a estrutura seguiu os 
                //parâmetros da função ou não
                r_fila = desenfileirar(&fila, e);
            }
            else{//caso de operador inválido
                printf("Operador inválido. Digite i ou r.");
            }
        }
        //comparações usando r_fila e erro_pilha -> 0 = sem erro & 1 = com erro
        if (r_fila == 1 && erro_pilha == 1){
            //caso impossível
            printf("\nimpossivel");
        } 
        else if(erro_pilha == 0 && r_fila == 1) {
            // pilha
            printf("\npilha");
        }
        else if (r_fila == 0 && erro_pilha == 1){
            // fila
            printf("\nfila");
        }
        else if(erro_pilha == 0 && r_fila == 0){ 
            //indefinido 
            printf("\nindefinido");
        }
        //liberando as estruturas depois do for do número de casos 
        libera_f(&fila);
        libera_p(&pilha);
        erro_pilha = 0;
  
    }
    return 0;
}
