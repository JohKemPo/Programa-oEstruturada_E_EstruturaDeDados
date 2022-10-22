#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
1. Considere uma lista encadeada que armazena valores reais, na qual cada elemento é do
tipo Elemento, descrito abaixo:

struct elemento {
    float info; # Valor real armazenado
    struct elemento *prox; # Ponteiro para o próximo elemento
};

typedef struct elemento Elemento;

Escreva uma função que recebe como parâmetros o ponteiro lst, para o primeiro elemento
da lista, e os valores min e max, e remove e libera todos os elementos desta lista que
armazenam valores menores que min ou maiores que max. A função deve retornar o
ponteiro para o início da lista, que pode ter sido modificado, e tem o seguinte protótipo:

Elemento* filtra(Elemento *lst, float min, float max);
*/

struct elemento {
    float info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

void init(Elemento *lst);
int vazia(Elemento *lst);
void insere(Elemento *lst);
void imprime(Elemento *lst);

int main(){
    Elemento *lst = (Elemento*) malloc(sizeof(Elemento));
    if(!lst)exit(1);
    init(lst);
    imprime(lst);
    insere(lst);
    imprime(lst); 

    return 0;
}


//Inicia
void init(Elemento *lst){
    lst->prox = NULL;
    
}
//Testa vazia
int vazia(Elemento *lst){
    if(lst->prox == NULL){
        return 1;
    }else return 0;
}
//Insere inicio
void insere(Elemento *lst){
    Elemento *novo = (Elemento*) malloc(sizeof(malloc));
    if(novo == NULL)exit(1);

    printf("Digite a informacao: ");
    scanf("%f", &novo->info);
    
    Elemento *aux =    lst->prox;
    lst->prox = novo;
    novo->prox = aux;
}
//Print
void imprime(Elemento *lst){
    if(vazia(lst)){
        printf("VAVA");
        return;
    }
    Elemento *tmp;

    tmp = lst->prox;

    while(tmp != NULL){
        printf("|%f|->", tmp->info);
        tmp = tmp->prox;
    }
    printf("NULL");
}
//Busca

//deleta
//Libera
