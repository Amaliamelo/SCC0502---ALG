#ifndef PILAFILHA_H
#define PILAFILHA_H
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

// valor do elemento
typedef int t_chave;


// estrutura do "tipo elemento"
typedef struct t_elemento {
	t_chave chave;
} t_elemento;

typedef struct t_no *t_apontador;
// tipo nó
typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;

// tipo conjunto
typedef struct{
	t_apontador primeiro;
	t_apontador ultimo;
  	t_apontador topo;
} t_conjunto;

// FILA
void criar_f(t_conjunto *conjunto);
int enfileirar(t_conjunto *conjunto, t_elemento elemento);
int desenfileirar(t_conjunto *conjunto,t_elemento elemento);
int vazia_f(t_conjunto *conjunto);
void libera_f(t_conjunto *conjunto);
// PILHA
void criar_p(t_conjunto *conjunto);
int empilhar(t_conjunto *conjunto, t_elemento elemento);
int desempilhar(t_conjunto *conjunto);
int vazia_p(t_conjunto *conjunto);
void libera_p(t_conjunto *conjunto);

#endif