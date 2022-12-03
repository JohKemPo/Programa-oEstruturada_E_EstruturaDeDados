#include <stdio.h>

void bubbleSort(int vetor[], int tam){

    int prox = 0;

    for(int j = 0; j < tam; j++){
        for(int k = 0; k < (tam -1);k++){
            if(vetor[k] > vetor[k+1]){
                prox = vetor[k];
                vetor[k] = vetor[k+1];
                vetor[k+1] = prox;
                imprimir(vetor);
            }
            
        }
    }
}

void imprimir(int *vetor){
    printf("[");
    for(int i = 0; i < 10;i++){
        printf(" %d ", vetor[i]);
    }
    printf("]\n");
}

int main(){
    int vetor[10] = {10,20,5,1,7,3,15,10,2,0};

    printf("\nAntes:\n");
    imprimir(vetor);
    printf("\n\n");
    

    bubbleSort(vetor, 10);

    printf("\nDepois:\n");
    imprimir(vetor);


    return 0;
}