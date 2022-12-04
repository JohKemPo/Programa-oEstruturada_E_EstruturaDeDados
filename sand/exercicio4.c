#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definindo o tipo da lista
struct LISTA {
    int info;
    struct LISTA *prox;
};
typedef struct LISTA tLista;

// funcao para o menu
void menu(){
    printf("MENU: \n");
    printf("=================================\n");
    printf("1. uniao entre conjuntos; \n");
    printf("2. diferenca entre conjuntos; \n");
    printf("3. pertinencia entre conjuntos; \n");
    printf("4. intersecao entre conjuntos; \n");
    printf("5. imprimir os conjuntos; \n");
    printf("6. sair. \n");
    printf("=================================\n");
}

// funcao para criar a lista
tLista* criaLista(){
    return NULL; // o primeiro elemento aponta para null 
}

// funcao para inserir elemento no inicio
tLista* insereElemento(tLista *lista, int elem){
    tLista *novo;

    novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem;
    novo->prox = lista; // o no inserido passa a apontar para onde lista estava apontando
    return novo;
}

// funcao para inserir elemento no final
tLista* insereElementoFinal(tLista *lista, int elem){
    tLista *novo, *aux;

    aux = lista; // lista aponta pra null 

    novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem; // lista recebe o elem 
    novo->prox = aux->prox; // novo passa a apontar para onde aux estava apontando (ou seja, null)
    aux->prox = novo; // aux passa a apontar para novo que esta apontando para null
    return novo;
}

// funcao para imprimir a lista
void imprimeLista(tLista *lista){
    tLista *aux;

    aux = lista;
    for(aux; aux != NULL; aux = aux->prox){
        printf("%d -> ", aux->info);
    }
    printf("NULL \n");
}

// funcao para fazer a intersecao das listas
tLista* intersecao(tLista *lista1, tLista *lista2){
    tLista *lista3, *aux1, *aux2; // crio 2 ponteiros auxiliares p percorrer as duas listas

    if(lista1 == NULL || lista2 == NULL){
        lista3 == NULL; // se uma das listas forem vazias retorna null pq nao tem intersecao
    } else {    
        aux1 = lista1;
        aux2 = lista2;
        for(aux1; aux1 != NULL; aux1 = aux1->prox){ // pega 1 pos da lista 1
            while(aux2 != NULL){ // enquanto percorrre toda a lista 2 para comparar
                if(aux1->info == aux2->info){
                    lista3 = insereElemento(lista3, aux2->info);
                }
                aux2 = aux2->prox;
            }
        }
    }
    return lista3;
}

// funcao para fazer a uniao dos conjuntos
tLista* uniao(tLista *lista1, tLista *lista2){
    tLista *lista3, *aux1, *aux2;
    if(lista1 == NULL){
        return lista2; // se l1 estiver vazia retorna l2
    } else if(lista2 == NULL){
        return lista1; // se l2 estiver vazia retorna l1
    } else {
        aux1 = lista1;
        aux2 = lista2;
        for(aux1; aux1 != NULL; aux1 = aux1->prox){
            lista3 = insereElemento(lista3, aux1->info); // passando l1 para l3
        }
        for(lista3; lista3 != NULL; lista3 = lista3->prox){
            while(aux2 != NULL){
                if(lista3->info != aux2->info){ // se forem diferentes, entao inserimos os elementos de l2 em l3 ja q queremos a uniao 
                    lista3 = insereElemento(lista3, aux2->info);
                }
                aux2 = aux2->prox;
            }
        }
        return lista3;
    }
}

// funcao para fazer a diferenca das listas
tLista* diferenca(tLista *lista1, tLista *lista2){ // elementos q estao em l1 mas q nao estao em l2
    tLista *lista3, *aux1, *aux2;
    bool x;
    // se uma das listas estiver vazia a diferenca vai ser a outra lista inteira
    if(lista1 == NULL){
        return lista2; // se l1 estiver vazia retorna l2
    } else if(lista2 == NULL){
        return lista1; // se l2 estiver vazia retorna l1
    } else {
        aux1 = lista1;
        aux2 = lista2;
        for(aux1; aux1 != NULL; aux1 = aux1->prox){ // pega 1 elem de l1
            while(aux2 != NULL){ // enquanto esse percorre toda a l2
                if(aux1->info != aux2->info){
                    x = true;
                } else {
                    x = false;
                    break;
                }
                aux2 = aux2->prox;
            }
            if(x == true){
                lista3 = insereElemento(lista3, aux1->info); // se elem em l1 for diferente do elem em l2, l3 recebe o elem de l1
            }
        }
        return lista3;
    }
}

// funcao de pertinencia entre listas
bool pertinencia(tLista *lista1, tLista *lista2){
    tLista *lista3, *aux1, *aux2;
    bool x;
    // se uma das listas estiver vazia a outra lista esta contida nela pois em todo conj existe o vazio
    if(lista1 == NULL || lista2 == NULL){
        x = true;
        return x; // se l1 ou l2 estiverem vazias retorna true 
    } else {
        aux1 = lista1;
        aux2 = lista2;
        for(aux1; aux1 != NULL; aux1 = aux1->prox){ // pega 1 elem de l1
            while(aux2 != NULL){ // enquanto esse percorre toda a l2
                if(aux1->info == aux2->info){ // se l1 for igual a l2, l3 recebe l2 ja que queremos saber se l2 esta contido em l1
                    lista3 = insereElemento(lista3, aux2->info);
                }
                aux2 = aux2->prox;
            }
        }
        for(aux2; aux2 != NULL; aux2 = aux2->prox){ // pega 1 elem de l2 ja que no laco anterior inserimos os dados de l2 em l3
            while(lista3 != NULL){ // enquanto esse percorre toda a l3
                if(aux2->info == lista3->info){ // compara se l2 eh igual a l3
                    x = true; // se x eh igual a true entao l2 esta contido em l1
                } else {
                    x = false; // se x eh igual a false entao l2 nao esta contido em l1
                }
                aux2 = aux2->prox;
            }
        }

    }
    return x;
}

int main(){
    tLista *L1, *L2, *L3;
    int op = 0, x, y, i, el;
    bool aux;

    L1 = criaLista();
    L2 = criaLista();
    L3 = criaLista();
    
    printf("Digite a qtd de elementos a serem inseridos em L1 e L2: \n");
    scanf("%d %d", &x, &y);
    printf("Insira os elementos de L1: \n"); // inserindo os elementos em l1
    for(i = 0; i < x; i++){
        scanf("%d", &el);
        fflush(stdin);
        L1 = insereElemento(L1, el);
    }
    printf("Insira os elementos de L2: \n"); // inserindo os elementos em l2
    for(i = 0; i < y; i++){
        scanf("%d", &el);
        fflush(stdin);
        L2 = insereElemento(L2, el);
    }

    do{
        menu();
        printf("Digite a operacao desejada: \n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                L3 = uniao(L1, L2);
                imprimeLista(L3);
                break;
            case 2:
                L3 = diferenca(L1, L2);
                imprimeLista(L3);
                break;
            case 3:
                aux = pertinencia(L1, L2);
                if(aux == true){
                    printf("um conjunto esta contido no outro \n");
                } else {
                    printf("um conjunto nao esta contido no outro \n");
                }
                break;
            case 4:
                L3 = intersecao(L1, L2);
                imprimeLista(L3);
                break;
            case 5:
                printf("Conjunto 1: \n");
                imprimeLista(L1);
                printf("=================================\n");
                printf("Conjunto 2: \n");
                imprimeLista(L2);
                break;
            default:
                printf("Operacao invalida! \n");
                break;
        }
    } while(op != 6);

    return 0;
}
