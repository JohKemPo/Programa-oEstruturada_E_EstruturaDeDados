#include <stdio.h>
#include <stdlib.h>

typedef struct Teste{
    int info;
    struct Teste *prox; 
}t;

t* criaLista(){
    return NULL; // o primeiro elemento aponta para null 
}

t* insereElemento(t *lista, int elem){
    t *novo;

    novo = (t*)malloc(sizeof(t));
    novo->info = elem;
    novo->prox = lista; // o no inserido passa a apontar para onde lista estava apontando
    return novo;
}

void imprimeLista(t *lista){
    t *aux;

    aux = lista;
    for(aux; aux != NULL; aux = aux->prox){
        printf("%d -> ", aux->info);
    }
    printf("NULL \n");
}

int main(){
    int v[9] = {1,2,3,4,5,6,7,8,9};
    
    int tam = sizeof(v)/sizeof(int);
    printf("%d\n",tam);

    t *teste;
    teste = criaLista();

    teste = insereElemento(teste,1);
    teste = insereElemento(teste,2);
    teste = insereElemento(teste,3);
    teste = insereElemento(teste,4);
    teste = insereElemento(teste,5);

    imprimeLista(teste);
    tam = 0;

    for(t *i = teste; i != NULL;i = i->prox){
        tam++;
    }
    // tam = tam/sizeof(teste);
    printf("\n%d",tam);

    return 0;
}