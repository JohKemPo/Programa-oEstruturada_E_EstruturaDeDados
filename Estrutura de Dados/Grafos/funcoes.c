#include <stdio.h>
#include <stdlib.h>

typedef struct vizinhos{
    int id_vizinho;
    struct vizinhos *prox;
}TVizinho;

typedef struct grafo{
    int id_vertice; // Vértice id
    TVizinho *prim_vizinho; // lista horizontal, vertices adj AZUL
    struct grafo *prox; // prox vértice VERDE
}TGrafo;


// inicializa grafo
TGrafo *init(){
    return NULL;
}


TGrafo * busca_vertice(TGrafo *g, int x){
    while((g != NULL) && (g->id_vertice != x)){
        g = g->prox;
    }
    return g;
}

TVizinho *busca_aresta(TGrafo *g, int v1, int v2){
    TGrafo *pv1 = busca_vertice(g, v1);
    TGrafo *pv2 = busca_vertice(g, v2);

    TVizinho *resp = NULL;

    if((pv1 != NULL) && (pv2 != NULL)){
        resp = pv1->prim_vizinho;
        while((resp != NULL) && (resp->id_vizinho != v2)){
            resp = resp->prox;
        }
    }
    return resp;
}

//insere 
TGrafo *insere_vertice_inicio(TGrafo *g, int x){
    TGrafo *p = busca_vertice(g,x);

    if( p == NULL){
        p = (TGrafo*) malloc(sizeof(TGrafo));
        p->id_vertice = x;
        p->prim_vizinho = NULL;
        p->prox = g;
        g = p;
    }
    return g;
}

void insere_um_sentido(TGrafo *g, int v1, int v2){
    TGrafo *p = busca_vertice(g, v1);
    TVizinho *novo = (TVizinho*) malloc(sizeof(TVizinho));
    novo->id_vizinho = v2;
    novo->prox = p->prim_vizinho;
    p->prim_vizinho = novo;
}

//insere ARESTA grafo orientado DIGRAFOS
void insere_aresta_digrafo(TGrafo *g, int v1, int v2){
    TVizinho *v = busca_aresta(g, v1, v2);
    if(v == NULL){
        insere_um_sentido(g,v1,v2);
    }
}



//insere ARESTA grafo nao orientado--------------------------


void insere_aresta_nao_orientado(TGrafo *g, int v1, int v2){
    TVizinho *v = busca_aresta(g, v1, v2);
    if(v == NULL){
        insere_um_sentido(g,v1,v2);
        insere_um_sentido(g,v2,v1);
    }
}
//---------------------------------------------------------

// IMPRIME
void imprime(TGrafo *g){
    while(g != NULL){
        printf("Vértice | %d |  -> ", g->id_vertice); //imprime o vértice
        // printf("                |  ");
        

        // printf("Vizinhos: ");
        TVizinho *v = g->prim_vizinho;
        while (v != NULL){
            printf("%d -> ", v->id_vizinho);// imprime a lisca que contem seus vizinhos
            v = v->prox;
        }printf("NULL");
        
        printf("\n\n");
        g = g->prox;
    }
}

void libera_vizinhos(TVizinho *v){
    while (v != NULL){
        TVizinho *temp = v;
        v = v->prox;
        free(temp);
    }
    
}

void libera(TGrafo *g){
    while (g != NULL){
        libera_vizinhos(g->prim_vizinho);
        TGrafo *temp = g;// guarda no atual
        g = g->prox;// avança
        free(temp);// exclui no "atual"
    }
    
}







int main(){
    TGrafo *g;

    g = init();

    //digrafo
    g = insere_vertice_inicio(g,1);
    g = insere_vertice_inicio(g,2);
    g = insere_vertice_inicio(g,3);
    g = insere_vertice_inicio(g,4);
    insere_aresta_digrafo(g,1,2);
    insere_aresta_digrafo(g,1,3);
    insere_aresta_digrafo(g,2,3);

    //libera(g);

    imprime(g);
    return 0;
}