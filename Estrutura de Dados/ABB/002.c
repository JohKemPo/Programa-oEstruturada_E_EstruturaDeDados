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

void Libera(TNoA *ab){
    if(ab){
        Libera(ab->dir);
        Libera(ab->esq);
        free(ab);
    }
}

TNoA *Espelha(TNoA *ab){
    TNoA *novo = (TNoA*) malloc(sizeof(TNoA));
    if(!novo)exit(1);

    if(!ab) return NULL;

    TNoA *aux = ab;
    printf("aux = %d ", aux->num);
    if(aux != NULL){

        novo->num = ab->num;
        
        //inverte
        novo->esq = Espelha(ab->dir);
        novo->dir = Espelha(ab->esq);

        //atualiza o aux
        aux = Espelha(ab->esq);
        aux = Espelha(ab->dir);
    }
    return novo;
}


int main(){
    TNoA *raiz;
    TNoA *espelhada;

    raiz = cria(1);

    raiz->esq = cria(2);
    raiz->dir = cria(3);
    raiz->esq->esq = cria(4);
    raiz->esq->dir = cria(5);
    raiz->dir->esq = cria(6);
    raiz->dir->dir = cria(7);


    imprime(raiz);
    printf("\n");

    espelhada = Espelha(raiz);
    printf("\n");
    imprime(espelhada);

    Libera(espelhada);
    Libera(raiz);

    return 0;
}