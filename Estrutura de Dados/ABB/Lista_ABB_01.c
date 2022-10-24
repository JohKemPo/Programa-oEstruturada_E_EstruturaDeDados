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
        printf("%d ",a->num);
        imprime(a->esq);
        imprime(a->dir);
    }
}

TNoA *insere(TNoA *no, int num) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->num = num;
        no->esq = NULL;
        no->dir = NULL;
    } else if (num < (no->num))
        no->esq = insere(no->esq, num);
    else if (num > (no->num))
        no->dir = insere(no->dir, num);
    else {
        printf("Inserção inválida! "); // num já existe
        exit(1);
    }
return no;
}

TNoA *copy(TNoA *a){
    if(a==NULL){
        return NULL;
    }
    TNoA *novo;
    novo->esq = copy(a->esq);
    novo=cria(a->num);
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

int Maior(TNoA *abb){
    int maior = abb->num;
    if(abb->dir != NULL){
        maior = Maior(abb->dir);
    }
    return maior;
}

int main(){
    TNoA *raiz;
    raiz = cria(50);
    
    raiz = insere(raiz, 55);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 70);
    raiz = insere(raiz, 30);
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 25);

    printf("\n%d\n", Maior(raiz));

    imprime(raiz);
    Libera(raiz);
    return 0;
}