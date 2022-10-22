#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
7) Um arquivo do tipo texto, chamado ‘‘numeros.txt’’ contém uma quantidade
desconhecida de números reais. Escreva um programa que leia estes números, os coloque
em ordem crescente e depois os grave em um arquivo binário chamado ‘‘numeros.bin’’.
*/

int main(){
    int n = 1;
    char info[10];
    FILE *i = fopen("numeros.txt","r");
    if(i == NULL){
        exit(1);
    }else printf("Aberto!\n");

    FILE *o = fopen("numeros.bin","ab");
    if(o == NULL){
        exit(1);
    }else printf("Aberto!\n");

    int *num = (int*) malloc(n*sizeof(int));
    if(!num)exit(1);

    while ((fgets(info, 10,i)) != NULL){
        printf("%s ", info);
    }
    

    fclose(o);
    fclose(i);
    free(num);
    return 0;
}