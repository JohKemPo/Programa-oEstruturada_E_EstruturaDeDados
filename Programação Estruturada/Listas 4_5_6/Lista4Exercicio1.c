#include <stdio.h>
#include <locale.h>// set idioma local


/*
1. Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os
elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o
10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o
vetor Y.
*/

int main(){

    setlocale(LC_ALL,"Portuguese");//reconhece o idioma pt-br
    int* x;
    int* y;
    int cont = 10;

    x = (int*) malloc(10*sizeof(int));
    y = (int*) malloc(10*sizeof(int));

    if(x == NULL){printf("Memoria insuficiente");exit(1);}
    if(y == NULL){printf("Memoria insuficiente");exit(1);}

    for(int i = 0; i < 10;i++){
        printf("Digite um número: ");
        scanf("%d", &x[i]);
    }
    for(int i = 10; i > 0; i--){
        printf("%d",i);
    }

    for(int i = 0; i < 10; i++){
        printf("X[%d] -> %d ---- Y[%d] -> %d\n", i,x[i],i,y[i]);
    }
    free(x);
    free(y);



    return 0;
}
