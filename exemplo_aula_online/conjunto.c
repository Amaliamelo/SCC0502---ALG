#include "conjunto.h"
#include <stdio.h>
#include <string.h>

void inicializar(t_conjunto A){
    memset(A, 0, sizeof(t_conjunto));
};

void uniao(t_conjunto A, t_conjunto B, t_conjunto C){
    for(int i=0;i<max;i++){
        C[i]=A[i]||B[i]; // if(A[i]==1||B==1) c[i]==1
    }
};
void interseccao(t_conjunto A, t_conjunto B, t_conjunto C){
    for(int i=0;i<max;i++){
        C[i]=A[i] && B[i];
    }
};

int pertence(t_elemento e, t_conjunto A){
    if(e<0 || e>=max){
        printf("\nElemento inválido.");
        return -1;
    }
    return A[e];
};

void insercao(t_elemento e, t_conjunto A){
     if(e<0 || e>=max){
        printf("\nElemento inválido.");
        return;
    }
    if(pertence(e, A)){
        printf("\nElemento ja foi inserido");
    }
    A[e]=1;
}; 

void remocao(t_elemento e, t_conjunto A){
     if(e < 0 || e >= max){
        printf("\nElemento inválido.");
        return;
    }
    if(!pertence(e, A)){
        printf("\nElemento não estava no conjunto");
    }
    A[e]=0;
};



void imprimir(t_conjunto A){
    printf("{");
    for(int i=0; i< max;i++){
        if(pertence(i,A)){
            printf("%d ", i); 
        }
    }
    printf("}");
}
