#ifndef LISTA_H
#define LISTA_H

#define MAX_TAM 100

#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef int t_chave;

typedef struct TipoNo{
	TipoItem Item;
	char
}TipoNo;

typedef t_elemento* t_apontador;

typedef struct {
	t_chave chave;
	char nome[50];
} t_elemento;

typedef struct t_no{

}


typedef struct {
	t_apontador primeiro, ultimo;
} t_lista;

int criar(t_lista *lista); 
//pré condição == nenhuma
int inserir(t_lista *lista, t_elemento elemento);
//pré condição == memória disponível // pós condição == elemento é inserido na primeira posição
int remover(t_lista *lista, t_chave chave); 
//pré condição == // pós condição ==
t_elemento pesquisar(t_lista *lista, t_chave chave);
// pré condição == nenhuma // pós condição == elemento
//a busca binaria não serve no caso da lista dinamica, 
//visto que não se sabe onde cada elemento ta --- O(n) --- é possivel verificar pela chave 
int alterar(t_lista *lista, t_elemento novo_elemento);
int vazia(t_lista *lista);
int cheia(t_lista *lista);
void imprimir(t_lista *lista);

#endif