#include <stdio.h>

void quickSort(int vetor[], int tam){

    int i, j, grupo, troca;
    if(tam<2){
        return;
    }else{
        grupo = vetor[tam/2];
    }
    
    for(i = 0, j = tam -1;/*SEM CRITERIO DE PARADA*/; i++,j-- ){
        //movimentar elementos

        while (vetor[i] < grupo){
            i++;
        }
        while (grupo < vetor[j]){
            j--;
        }
        //criterio de parada
        if(i >= j){
            break;
        }else{
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
            //imprimir(vetor);
        }
    }
    quickSort(vetor, i);
    quickSort(vetor + i, tam - i);
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
    

    quickSort(vetor, 10);

    printf("\nDepois:\n");
    imprimir(vetor);


    return 0;
}