#include <stdio.h>
#include <windows.h>

struct lista{
    int info;
    struct lista *prox;
    
};

typedef struct lista Lista;//apelido

Lista *create(){
    return NULL; 
}

Lista *fill(Lista *lst, int val){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL) exit(1);

    novo -> info = val;
    novo -> prox = lst;
    return novo;
}

void print(Lista *lst){
    Lista *p;
    for( p = lst; p != NULL; p = p -> prox){
        printf("| %d| -> ", p -> info);
    }
    printf("NULL");
}

int count(Lista *l){
    int x = 0;
    Lista *aux = l;
    while(aux != NULL){
        x++;
        aux =aux->prox;
    }   
    return x;
}

int main(){
    Lista *lst;
    int n = 0, val;

    lst = create();
    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Digite o %d° valor: ",i);
        scanf("%d",&val);
        
        lst = fill(lst, val);
    }
    print(lst);
    printf("\nCOunt %d", count(lst));

    return 0;
}