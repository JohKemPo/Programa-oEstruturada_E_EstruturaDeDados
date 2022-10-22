#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float media (char* mat, char* nome_arquivo);

int main(){
    char name[] = "L10E03.txt";
    char mat[] = "8820324-3";

    printf("%.1f", media(mat, name));

    return 0;
}

float media (char* mat, char* nome_arquivo){
    float media, n1, n2, n3;
    char matr[10], info[23];
    FILE *fi = fopen("L10E03.txt","r");
    if(!fi){
        printf("ERRO");
        exit(1);
    }else{
        printf("\nABERTO COM SUCESSO!!\n");
    }


    while((fgets(info,23,fi) != NULL)){
        printf("> %23s\n", info);
        int aux = sscanf(info, "%s %f %f %f", &matr, &n1, &n2, &n3);
        //printf("%s %f %f %f\n", matr, n1, n2, n3);

        if(!strcmp(matr, mat)){
            media = (n1+n2+n3)/3;
            //fclose(f);
            //return media;
        }
    }

    fclose(fi);
    return -1;
}