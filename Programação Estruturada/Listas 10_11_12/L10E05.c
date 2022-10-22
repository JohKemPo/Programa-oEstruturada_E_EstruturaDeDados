#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5) Escreva um programa que leia de um arquivo, cujo nome será fornecido pelo usuário,
um conjunto de números reais e armazene em um vetor. O programa ao final calcula a
media dos números lidos.
*/

int main(){
    char name[11] = "L10E05.txt", linha[100], faux;
    FILE *f = fopen(name, "r");
    int n = 1;
    int v[40];

    if(f == NULL){
        exit(1);
    }else printf("Aberto!\n");

   
    while((fgets(linha,100,f)) != NULL){
        //printf("%s", linha);
        for(int i = 0; linha[i] != '\0'; i++){
            if(linha[i] == ' ' || linha[i] == '\n'){
                n++;     
            }
        }
              
    }
    

    free(v);
    fclose(f);
    return 0;
}