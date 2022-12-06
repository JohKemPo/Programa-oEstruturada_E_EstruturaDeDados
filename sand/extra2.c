#include <stdio.h>
#include <stdlib.h>

// definindo o tipo da pilha
struct PILHA {
    int info;
    struct PILHA *prox;
};
typedef struct PILHA tPilha;

// cria a pilha
tPilha* criaPilha(){
    return NULL;
}

// insere elemento na pilha (inicio)
tPilha* insereElemento(tPilha *pilha, int elem){ // push
    tPilha *topo;

    topo = (tPilha*)malloc(sizeof(tPilha));
    topo->info = elem;
    topo->prox = pilha; // aponta para onde pilha esta apontando
    return topo;
}

// remove elemento da pilha (remove do inicio)
tPilha* removeElemento(tPilha *pilha){ // pop
    if(pilha == NULL){
        return NULL;
    }
    tPilha *lixo;

    lixo = pilha;
    pilha->prox = lixo->prox; // pilha prox aponta pra lixo prox
    free(lixo); // removemos lixo
    return pilha;
}

// imprimir a lista
void imprimePilha(tPilha *pilha){
    tPilha *aux;

    aux = pilha;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL \n");
}

// conta o tamanho da lista
int tamanhoPilha(tPilha *pilha, int tam){
    tPilha *aux;
    
    aux = pilha;
    if(aux == NULL){ // se aux for igual a null, retorna o tamanho
        return tam;
    } else {
        return tamanhoPilha(aux->prox, tam+1); // se n chama a funcao, passa o prox ponteiro e incrementa tamanho
    }
}

// alterna as pilhas em uma pilha nova
tPilha* alternaLista(tPilha *pilha1, tPilha *pilha2, tPilha *pilha3){
    tPilha *aux1, *aux2;
    int tam1 = 0, tam2 = 0;
    
    tam1 = tamanhoPilha(pilha1, tam1); // verifica o tamanho de l1
    tam2 - tamanhoPilha(pilha2, tam2); // verifica o tamanho de l2
    
    aux1 = pilha1;
    aux2 = pilha2;

    if(tam1 >= tam2){ // se l1 for maior ou igual l2
        while(aux1 != NULL){ // fazemos o loop em l1 pq eh maior q l2
            pilha3 = insereElemento(pilha3, aux1->info);
            if(aux2 != NULL){ // fazemos enquanto aux2 for diferente de null p nao imprimir lixo 
                pilha3 = insereElemento(pilha3, aux2->info);
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
    } else { 
        while(aux2 != NULL){ // fazemos o loop em l2 pq eh maior q l1
            pilha3 = insereElemento(pilha3, aux2->info);
            if(aux1 != NULL){ // fazemos enquanto aux1 for diferente de null p nao imprimir lixo
                pilha3 = insereElemento(pilha3, aux1->info);
                aux1 = aux1->prox;
            }
            aux2 = aux2->prox;            
        }
    imprimePilha(pilha3);
    }
    return pilha3; // retorna l3
}

int main(){
    tPilha *L1, *L2, *L3;
    int i = 1, j = 1, x1, x2;
    int a = 0, b = 0;

    L1 = criaPilha();
    L2 = criaPilha();
    L3 = criaPilha();

    printf("Preencha L1 com valores inteiros e positivos: \n");
    printf("%d elemento: \n", i);
    scanf("%d", &x1);
    while(x1 >= 0){
        L1 = insereElemento(L1, x1);
        i++;
        printf("%d elemento: \n", i);
        scanf("%d", &x1);
        fflush(stdin);
    }

    printf("Preencha L2 com valores inteiros e positivos: \n");
    printf("%d elemento: \n", j);
    scanf("%d", &x2);
    while(x2 >= 0){
        L2 = insereElemento(L2, x2);
        j++;
        fflush(stdin);
        printf("%d elemento: \n", j);
        scanf("%d", &x2);
        fflush(stdin);
    }  
    
    L3 = alternaLista(L1, L2, L3);

    imprimePilha(L1);
    printf("=======================\n");
    imprimePilha(L2);
    printf("=======================\n");
    imprimePilha(L3);

    free(L1);
    free(L2);
    free(L3);

    return 0;
}