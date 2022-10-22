#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4) Faça um programa que leia um nome de “arquivo .c” digitado pelo usuário e gere um
novo que remove as infos com comentários “//”
*/

int main(){
    char name[11] = "arquivo.c";
    char name2[11] = "arquivo2.c";
    char info[100];
    int b1 = 0, b2 = 0;
    char c;

    FILE* f = fopen(name,"r");
    if(f == NULL){
        exit(1);
    }else printf("Aberto!\n");

    FILE* f2 = fopen(name2,"w");
    if(f2 == NULL){
        exit(1);
    }else printf("Aberto2!\n");

    
    while((fgets(info,100,f) != NULL)){
        b1 = b2 = 0;
        //int aux = sscanf(info,"%s",&linha);
        //printf("%s\n", linha);
        //strcpy(linha,info);
        //printf("%s", linha);

        for(int i = 0; info[i] != '\0'; i++){
            if(info[i] == '/')b1 = 1;
            if(info[i] == '\n')b2 = 1;
            printf("> b1: %d b2: %d --> %c\n",b1,b2,info[i]);
        }
        if(b1 != 1 || b2 != 1 ){
            fprintf(f2,"%s",info);
        }
    }
    
   /*
    while ((c = fgetc(f)) != EOF){
        fputc(c,f2);
    }*/
   
    fclose(f);
    fclose(f2);
    return 0;
}