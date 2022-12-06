#ifndef ARVORE_B_ARVORE_B_H
#define ARVORE_B_ARVORE_B_H

#include <stdio.h>
#include <stdlib.h>

const int d = 2;

typedef struct No {
    int m; //quantidade de chaves armazenadas no nó
    struct No *pont_pai;
    int *s; //array de chaves
    struct No **p; //ponteiro para array de ponteiros para os filhos
} TNo;

TNo *cria();
TNo *libera(TNo *a);
void imprime(TNo *a, int nivel);
TNo *busca(TNo *no, int ch);
TNo *inicializa();
TNo *particiona(TNo *raiz, TNo *P, int ch, TNo *pt);
TNo *insere(TNo *raiz, int folha, int ch, TNo *pt);
TNo *particiona(TNo *raiz, TNo *P, int ch, TNo *pt);



#endif //ARVORE_B_ARVORE_B_H
