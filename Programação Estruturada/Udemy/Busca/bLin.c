#include <stdio.h>

int bl(int vetor[], int key, int tam){
    for(int i = 0; i < tam; i++){
        if(vetor[i] == key)return i;
    }
    return -1;
}

int main(){
    int vetor[6] = { 1,2,3,4,5,6};

    int key = 6;

    int ret = bl(vetor, key, 6);

    printf("O elementor %d esta na posicao %d", key, ret);

    return 0;
}