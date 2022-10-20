#include <stdio.h>
#include <stdlib.h>

typedef struct sTNoAB{
    int chave;
    char info;
    struct sTNoAB* esq;
    struct sTNoAB* dir;
}TNoAB;

TNoAB* cria(TNoAB *a){
    return NULL;
}

void ordena(int* v){
    int tam = 7, aux;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            int aux = 0;
            if(v[i]<=v[j]){
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
}

TNoAB* input(TNoAB* a,int v){
   
    //inserir 
    if (a == NULL) {
        a = (TNoAB *) malloc(sizeof(TNoAB));
        a->chave = v;
        a->esq = NULL;
        a->dir = NULL;
    }else if (v < (a->chave)){
        a->esq = input(a->esq, v);
    }else if (v > (a->chave)) {
        a->dir = input(a->dir, v);
    }else{
        printf("Inserção inválida! ");
        exit(1);
    }
    return a;
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
void criaArvoreBalanceada(TNoAB *raiz, int* v, int inicio, int fim){
    
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        raiz = input(raiz, v[meio]);
        //constroi subárvores esquerda e direita
        criaArvoreBalanceada(raiz, v, inicio, meio - 1);
        criaArvoreBalanceada(raiz, v, meio + 1, fim);
    }
}
int main(){

    int v[] = {150, 300, 400, 500, 600, 800, 80};
    TNoAB* raiz;

    ordena(v);
    raiz = cria(raiz);
    raiz = input(raiz,90);
    criaArvoreBalanceada(raiz, v, 0,6);
    imprime(raiz,0);


    //free(raiz);
    return 0;
}