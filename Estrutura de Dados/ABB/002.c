/*
1. Escreva uma função em C que faz a cópia de uma árvore: TAB* copia (TAB
*a); 
*/
#include <stdio.h>
#include<stdlib.h>

typedef struct NoA{
    int num;
    struct NoA* esq;
    struct NoA* dir;
}TNoA;


TNoA *cria(int n){
    TNoA *novo = (TNoA*) malloc(sizeof(TNoA));
    if(!novo)exit(1);

    novo->num = n;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TNoA *a){
    if (a!= NULL){
        imprime(a->esq);
        printf("%d ",a->num);
        imprime(a->dir);
    }
}

TNoA *copy(TNoA *a){
    if(a==NULL){
        return NULL;
    }
    TNoA *novo;
    novo=cria(a->num);
    novo->dir=copy(a->esq);
    novo->esq=copy(a->dir);

    return novo;
}

int main(){
    TNoA *raiz;
    TNoA *cop;
    raiz = cria(1);
    raiz->esq = cria(2);
    raiz->dir = cria(3);
    raiz->esq->esq = cria(4);
    raiz->esq->dir = cria(5);
    raiz->dir->esq = cria(6);
    raiz->dir->dir = cria(7);
    imprime(raiz);
    cop = copy(raiz);
    printf("\n");
    imprime(cop);

    return 0;
}