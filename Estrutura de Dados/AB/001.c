#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    int chave;
    struct noA* esq;
    struct noA* dir;
} TNoAB;

TNoAB *busca(TNoAB *ab, int chave){
    TNoAB *aux = ab;
    while(ab != NULL){
        if(aux->chave == chave){
            return aux;
        }else if(aux->chave > chave){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }
    return NULL;
}

TNoAB *insere(TNoAB *no, int chave) {
    if (no == NULL) {
        no = (TNoAB *) malloc(sizeof(TNoAB));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

void imprime(TNoAB *a, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (a != NULL) {
        printf("%d\n", a->chave);
        imprime(a->esq, tab + 2);
        printf("\n");
        imprime(a->dir, tab + 2);
    } else printf("vazio");
}

int main(){

    TNoAB* raiz;
    raiz = NULL;
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 9);
    raiz = insere(raiz, 8);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 12);
    raiz = insere(raiz, 15);
    raiz = insere(raiz, 11);

    imprime(raiz,0);

    return 0;
}

