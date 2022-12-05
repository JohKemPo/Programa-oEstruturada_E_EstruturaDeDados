#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct circularlista{
    int info;
    struct circularlista *prox;
    struct circularlista *ant;
}TLC;


void inicia(TLC* l){
    l->prox = NULL;
    l->ant = NULL;
}
int main(){
    TLC* l;
    inicia(l);
    if(l->prox == NULL && l->ant == NULL)printf("NULL");
    
    return 0;
}