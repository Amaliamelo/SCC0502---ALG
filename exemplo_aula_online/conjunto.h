#ifndef CONJUNTO_H
#define CONJUNTO_H

#define max 100

typedef char t_elemento;
typedef t_elemento t_conjunto[max];


void inicializar(t_conjunto A);
void uniao(t_conjunto A, t_conjunto B, t_conjunto C);
void interseccao(t_conjunto A, t_conjunto B, t_conjunto C);
void insercao(t_elemento e, t_conjunto A);
void remocao(t_elemento e, t_conjunto A);
int pertence(t_elemento e, t_conjunto A);
void imprimir(t_conjunto A);

#endif