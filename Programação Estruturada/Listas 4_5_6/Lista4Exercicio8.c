#include <stdio.h>
#include <locale.h>

/*
8. Inicialize um vetor de inteiros aleatoriamente e percorra o vetor usando dois ponteiros : um
começando do início do vetor e outro do final até se encontrarem no meio. Obs : O vetor deve
conter um número par de elementos.
*/

int main(){

    setlocale(LC_ALL, "portuguese");

    int* v;
    int n ;

    scanf("%d", &n);

     v = (int*) malloc( n * sizeof(int));

    if(v == NULL){printf("ERROR MEMO");exit(1);}

    if(n % 2 == 0){

        for(int i = 0; i < n; i++){
            scanf("%d", v[i]);
        }
        for(int i = 0; i < n; i++){
            printf("%d", v[i]);
        }

    }

    free(v);

    return 0;
}
