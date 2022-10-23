
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

int zz(TNoA *a){
    
}
int main(){
    TNoA *raiz;
    TNoA *zig;
    
    raiz = cria(1);
    raiz->esq = cria(2);
    raiz->dir = cria(3);
    raiz->esq->esq = cria(4);
    raiz->esq->dir = cria(5);
    raiz->dir->esq = cria(6);
    raiz->dir->dir = cria(7);

    zig = cria(1);
    zig->esq = cria(2);
    zig->esq->dir = cria(3);
    
    imprime(raiz);
    printf("\n");
    imprime(zig);
    printf("\n");

    printf("Zz = %d", zz(zig));

    Libera(raiz);
    Libera(zig);
    return 0;
}