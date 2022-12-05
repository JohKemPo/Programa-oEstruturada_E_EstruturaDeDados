#include <stdio.h>

void quick_sort(int *v, int tam){
    
}

int tam(int *v){
    int tam = 0;
    tam = sizeof(v)/sizeof(int);
    return tam;
}

int main(){
    int *v = {8,3,1,42,12,5};

    quick_sort(*v, tam(v));

    for(int i = 0; i < tam; i++){
        printf("%d - ", v[i]);
    }
    return 0;
}