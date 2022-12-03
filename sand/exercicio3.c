#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo o tipo da lista
struct LISTA {
    int info;
    struct LISTA *prox;
};
typedef struct LISTA tLista;

// criando lista
tLista* criaLista(){
    return NULL; // o primeiro no da lista aponta pra no
}

// insere elemento no final da lista
tLista* insereElemento(tLista *lista, int elem){
    tLista *novo;

    novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem;
    novo->prox = lista;
    return novo;
}

// imprime a lista
void imprimeLista(tLista *lista){
    tLista *aux; // ponteiro auxiliar para nao perdermos o endereco do primeiro

    aux = lista;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox; // aux aponta para o proximo
    }
    printf("NULL \n");
}

// verifica se o elemento esta na lista
int verificaElemento(tLista *lista, int elem){
    tLista *aux = lista;
    
    if(lista != NULL){
        if(aux->info == elem){
            return 1;
        } else {
            return verificaElemento(aux->prox, elem);
        }
    }else{
        return 0;
    }

}

// verifica se o elemento esta na lista
int verificaElemento2(tLista *lista, int elem){
    tLista *aux = lista;
    
    if(lista != NULL){
        if(aux->info == elem){
            return elem;
        } else {
            return verificaElemento(aux->prox, elem);
        }
    }else{
        return -1;
    }

}

int main(){
    tLista *no;
    int qtd, i, num, existe, existe2;

    no = criaLista();

    printf("Digite o tamanho da lista: \n");
    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++){
        printf("%d elemento: \n", i+1);
        scanf("%d", &num);
        fflush(stdin);
        no = insereElemento(no, num);
    }

    printf("===============================================\n");
    imprimeLista(no);
    printf("===============================================\n");
    printf("Digite um elemento a ser procurado na lista: \n");
    scanf("%d", &qtd);

    existe = verificaElemento(no, qtd);
    existe2 = verificaElemento2(no, qtd);

    
    if(existe){
        printf("O elemento esta na lista \n");
    } else {
        printf("O elemento nao esta na lista \n");
    }
    

    if(existe2 == qtd){
        printf("2 - O elemento esta na lista \n");
    } else {
        printf("2 - O elemento nao esta na lista \n");
    }
    return 0;
}
