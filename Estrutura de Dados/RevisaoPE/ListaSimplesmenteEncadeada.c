#include <stdio.h>
#include <stdlib.h>

//Struct listSE
//Criando o nó e dando apelido
typedef struct TLSE{
    int info;
    struct TLSE* next;
}TLSE;

//Init
TLSE* init(){
    return NULL;// li aponta para NULL, iniciando a lista encadeada
}

//inStart
TLSE* inStart(TLSE* li, int i){
    TLSE* new = (TLSE*) malloc(sizeof(TLSE));// Criando um ní aux para ser adicionado a lista encadeada
    new->info = i;
    new->next = li;

    return new;
}

//inEnd
TLSE* inEnd(TLSE* li, int i){
    // cria o no a ser adicionado
    TLSE* new = (TLSE*) malloc(sizeof(TLSE));
    new->info = i;
    new->next = NULL;
    
    TLSE* aux = li;// Ponteiro aux
    if(aux == NULL) li = new;// Se lsita vazia, add no
    else{
        while(aux->next != NULL){// Encontra o ult elem
            aux = aux->next;
        }
        aux->next = new; // Atualiza next do ultimo elem
    }
    return li;// retorna lista atualizada
}

//inOrder
TLSE* inOrder(TLSE* li, int i){
    
    /* A IMPLEMENTAR */

    return NULL;
}

//print
void print(TLSE* li){
    TLSE* aux;
    if(li == NULL)printf("NULL");
    else{
        for(aux = li; aux != NULL; aux = aux->next){
            printf("%d -> ", aux->info);
        }
        printf("NULL");
    }
}
//out
TLSE* out(TLSE* li, int val){
    TLSE* p = li; // ponteiro percorre
    TLSE* ant = NULL; // ponteiro guarda anterior

    while (p->next != NULL && p->info != val){// busca
        ant = p;
        p = p->next;
    }

    if (p == NULL){ // NULL - fim da lista ( nao encontrado )
        return li;
    }

    if(ant == NULL) li = p->next;
    else ant->next = p->next;
     
    // atualiza ant->next
    // free
    free(p);
    return li;
}



//delete
TLSE* delete(TLSE* li){
    TLSE* aux = li;
    TLSE* p;

    while (aux != NULL){
        p = aux->next;
        free(aux);
        aux = p;   
    }
    return NULL;
}
//search

int main(){

    TLSE* listE_no;
    TLSE* listE_inv;
    listE_no = init(listE_no);
    listE_inv = init(listE_inv);

    listE_no = inStart(listE_no, 1);
    listE_no = inStart(listE_no, 2);
    listE_no = inStart(listE_no, 3);
    listE_no = inStart(listE_no, 4);
    listE_no = inStart(listE_no, 5);

    listE_inv = inEnd(listE_inv, 1);
    listE_inv = inEnd(listE_inv, 2);
    listE_inv = inEnd(listE_inv, 3);
    listE_inv = inEnd(listE_inv, 4);
    listE_inv = inEnd(listE_inv, 5);

    print(listE_no);
    printf("\n");
    print(listE_inv);

    listE_no = out(listE_no, 3);// remocendo no 3

    printf("\n");
    printf("\n");
    print(listE_no);
    printf("\n");
    print(listE_inv);

    listE_no = delete(listE_no);
    listE_inv = delete(listE_inv);

    printf("\n");
    print(listE_no);
    printf("\n");
    print(listE_inv);

    return 0;
}