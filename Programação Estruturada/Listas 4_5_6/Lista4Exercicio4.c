#include <stdio.h>


/*
4. Implemente uma função que receba como parâmetros um vetor de números inteiros v e seu
comprimento n, e verifique se os elementos do vetor correspondem aos termos de uma PA
(Progressão Aritmética), isto é, se existe um número inteiro k tal que v[i]=v[0]+k*i. Caso os
elementos do vetor correspondam aos termos de uma PA, a função deve retornar o valor
calculado para k. Por exemplo, se for passado para essa função o vetor {2,10,18,26,34} a função
deve retornar o valor 8. Caso o vetor não corresponda a uma PA, a função deve retornar o valor 0.
Assuma que o vetor sempre terá pelo menos 3 elementos. Essa função deve ter o seguinte
protótipo:
int testa_PA(int n, int* v)
*/
int testa_PA(int n, int* v){
    int k, ant = 0;
    for(int i = 1; i < n; i++){
        k = v[i] - v[i-1];
        if(ant != k && i > 1){
            k = 0;
            break;
        }
        ant = k;
    }
    return k;
}


int main(){
    int* v;
    int n = 5;

    scanf("%d", &n);

    v = (int*) malloc(n * sizeof(int));



    if( v == NULL){printf("ERRO");exit(1);}
    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
    }

    printf("%d", testa_PA(n,v));
    free(v);
    return 0;
}
