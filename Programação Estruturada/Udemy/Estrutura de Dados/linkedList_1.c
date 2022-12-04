#include <stdio.h>
#include <stdlib.h>

///definindo o tipo do no
typedef struct LISTA {
	int info;
	struct LISTA *prox;
}tLista;

///criando a lista
void *criaLista(){
	///faz o primeiro no da lista apontar pra null
	return NULL;
}

void criaLista_pp(tLista **l){
	///faz o primeiro no da lista apontar pra null, usando ponteiro de ponteiro
	*l = NULL;
}

void start(tLista *l){
    l->prox = NULL;
}

///insere elemento na lista
tLista* insereElemento_inicio(tLista *lista, int num){
	tLista *novo = (tLista*)malloc(sizeof(tLista));
	if(!novo)exit(1);

	novo->info = num;
	novo->prox = lista;

	return novo;
}

///imprime a lista
void imprimeLista(tLista* lista){
	if(lista == NULL){
		printf("NULL\n");
	}else{
		tLista *aux;
		int x = 0;
		
		for(aux = lista; aux != NULL; aux = aux->prox){
			x++;
			printf("Elemento %d: %d -> ",x,aux->info);
		}
		printf("NULL\n");
	}
}

///conta a quantidade de elementos na lista COM recursao
int contaElemento_recursivo(tLista *lista, int n){
	if(lista == NULL){
		return 0;
	} else {
		return contaElemento_recursivo(lista->prox, n+1);
	}
}

///outra forma de contar os elementos na lista SEM recursao
int contaElemento_norec(tLista *lista){
	tLista *aux;
	int x = 0;
	aux = lista;
	while(aux != NULL){
		x++;
		aux = aux->prox;
	}
	return x;
}


void insere_fim(tLista *l, int elem){
	tLista * new = (tLista*) malloc(sizeof(tLista));
    if(new == NULL)exit(1);

    new->info = elem;
    new->prox = NULL;

    if(l->prox == NULL){
        l->prox = new;
    }else{
        tLista *tmp = l->prox;

        while (tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = new;
    }
}

int main(){
	tLista *no;
	tLista *no2;
	int i, elem, qtd;
	int conta;
    int n = 0;
	
	//start(no2);
	no = criaLista();
	
	printf("Digite a quantidade de elementos a serem inseridos na lista: \n");
	scanf("%d", &qtd);

	for(i = 0; i < qtd; i++){
		printf("Digite o %d elemento: \n", i+1);
		scanf("%d", &elem);
		no = insereElemento_inicio(no, elem);
		//insere_fim(no2, elem);
	}
	
	imprimeLista(no);
	//imprimeLista(no2);
	
	// conta = contaElemento_norec(no);
	// conta = contaElemento_recursivo(no,0);
	printf("\nQuantidade de elementos na lista: %d . \n", contaElemento_norec(no));
	printf("Quantidade de elementos na lista: %d . \n", contaElemento_norec(no2));
	
	free(no);
	free(no2);
	return 0;
}
