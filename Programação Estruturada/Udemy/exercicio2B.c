#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo o tipo da esturtura
struct INFO {
    int codigo;
    char nome[40];
    float preco;
};
typedef struct INFO tInfo;

// definindo o tipo da lista
struct LISTA {
    tInfo dados;
    struct LISTA *prox;
};
typedef struct LISTA tLista;

// funcao para criar a lista
tLista* criaLista(){
    return NULL; // primeiro elem da lista aponta para null 
}

// funcao para inserir elemento
tLista* insereElemento(tLista* lista, int cod, char prod[40], float prc){
    tLista *novo;
    
    novo = (tLista*)malloc(sizeof(tLista)); // aloca espaco na memoria
    novo->dados.codigo = cod;
    
    strcpy(novo->dados.nome, prod);

    // novo->dados.nome[40] = prod[40]; ERROR

    novo->dados.preco = prc;
    novo->prox = lista; // aponta para onde lista estava apontando
    return novo;
}

// funcao para imprimir a lista
void imprimeLista(tLista* lista){
    tLista *aux; // ponteiro aux para n perder o endereco inicial

    for(aux = lista; aux != NULL; aux = aux->prox){
        printf("\ncod: %d nome: %s  preco: %.2f -> ", aux->dados.codigo, aux->dados.nome, aux->dados.preco);
    }
    printf("NULL \n");
}

// funcao para calcular a media de precos
float calculaMedia(tLista *lista){
    if(lista == NULL){ // se a lista estiver vazia, retorna 0
        return 0;
    }
    // se n estiver vazia, calcula a media
    tLista *aux = lista;
    float media = 0;
    int x = 0;

    while(aux != NULL){
        media += aux->dados.preco; // soma os valores
        x++; // incrementa 1
        aux = aux->prox; // direciona o ponteiro pro prox 
    }
    media = media / x;
    return media; 
}

int main(){
    tLista *no;
    int i, qtd = 0, cod;
    char prod[40];
    float prc, med;

    no = criaLista(); // faz o primeiro no apontar para null

    printf("Digite a quantidade de elementos a serem inseridos na lista: \n");
    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++){
        printf("Digite o codigo, o nome e o preco de um produto: \n");
        scanf("%d %s %f", &cod, prod, &prc);
        //printf(prod);
        fflush(stdin); // limpa o buffer de entrada
       
        no = insereElemento(no, cod, prod, prc);
    }

    imprimeLista(no);

    med = calculaMedia(no);
    printf("A media de valor dos produtos é de R$%.2f.", med);

    return 0;
}
