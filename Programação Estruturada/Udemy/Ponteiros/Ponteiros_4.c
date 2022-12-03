#include <stdio.h>
#include<locale.h>

int main(){
    //ARRAY unidimensional --> vetor ( lista )


    /*
        0   1   2   3   4
      ---------------------
      |   |   |   |   |   |
      ---------------------
      int = 4 bytes 0000 0000 0000 0000
      bit 0/1
      byte 0000 0000
    */

    setlocale(LC_ALL,"Portuguese");

    int vetor[5] = {1,2,3,4,5}; // delcarando e inic

    for(int i =0; i < 5; i++){

        printf("O valor %d tem %ld bytes\n", vetor[i], sizeof(vetor[i]));// sizeof tamanho ocupado em memo

    }
    printf("Tamanho ocupado em memoria pelo vetor %d bits\n", sizeof(vetor));
    printf("Vetor[0] vale %d e endereço de memoria %p\n", vetor[0], vetor[0]);
    printf("*(vetor) vale %d e endereço de memoria %p\n", *(vetor), *(vetor));


    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("Vetor[%d] vale %d e endereço de memoria %p\n", i, vetor[i], vetor[i]);
        printf("*(vetor+%d) vale %d e endereço de memoria %p\n",i , *(vetor+i), *(vetor+i));
        printf("\n");
    }
    return 0;
}
