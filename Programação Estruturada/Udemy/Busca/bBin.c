#include <stdio.h>

int bb(int vetor[], int key, int tam){
    int inicio = 0;
    int fim = tam - 1;

    while( inicio <= fim){
        int meio = (inicio+fim)/2;

        if( key == vetor[meio]){
            return meio;
        }

        if(key < vetor[meio]){
            fim = meio - 1;
        }else inicio = meio + 1;
    }

    return -1;
}

int main(){
    int vetor[6] = { 1,2,3,4,5,6};

    int key = 6;

    int ret = bb(vetor, key, 6);

    printf("O elementor %d esta na posicao %d", key, ret);

    return 0;
}