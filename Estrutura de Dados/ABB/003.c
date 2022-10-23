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


int comp(TNoA *a, TNoA *b){
    if(!a && !b) return 1;
    if(!a || !b) return 0;

    if(a->num == b->num){
        if(comp(a->esq,b->esq)){
            if(comp(a->dir,b->dir)){
                return 1;
            }
        }
    }else return 0;
}

TNoA *copy(TNoA *a){
    if(a==NULL){
        return NULL;
    }
    TNoA *novo;
    novo=cria(a->num);
    novo->esq = copy(a->esq);
    novo->dir = copy(a->dir);

    return novo;
}

void Libera(TNoA *ab){
    if(ab){
        Libera(ab->dir);
        Libera(ab->esq);
        free(ab);
    }
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

    cop = copy(raiz);
    //cop->dir->dir->dir = cria(7);


    imprime(raiz);
    printf("\n");
    imprime(cop);
    printf("\n");

    printf("COMP = %d", comp(raiz, cop));

    Libera(raiz);
    Libera(cop);    
    return 0;
}