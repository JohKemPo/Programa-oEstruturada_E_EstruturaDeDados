#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA {
	int info;
	struct LISTA *prox;
}tLista;


void start(tLista *l);
void imprimeLista(tLista* l);
tLista *insere_fim(tLista *l, int elem);
void insereS(tLista *l, int elem);

int main(){

    tLista *no = (tLista*) malloc(sizeof(tLista));
    if(!no)exit(1);
    
    no = NULL;
	
    no = insere_fim(no, 1);

    imprimeLista(no);
	free(no);
    return 0;
}


void start(tLista *no){
    no->prox = NULL;
}

///imprime a lista
void imprimeLista(tLista *l){
	if(l == NULL){
		printf("NULL\n");
	}else{
		tLista *aux = l->prox;
		
		while(aux != NULL){
            printf("|%d|-> ", aux->info);
        }
		printf("[NULL]\n");
	}
}


tLista* insere_fim(tLista *l, int elem){
	tLista *novo = (tLista*) malloc(sizeof(tLista));

	novo->info = elem;
	novo->prox = NULL;

	if(!novo)exit(1);

	if(l == NULL){
		return novo;
	}else{
		
	}
}

void insereS(tLista *l, int elem){
	tLista *novo = (tLista*) malloc(sizeof(tLista));
	if(!novo)exit(1);

	novo->info = elem;
	tLista *tmp = l->prox;

	l->prox = novo;
	novo->prox = tmp;
}