#include <stdio.h>
#include <stdlib.h>



int main(){

    FILE *arq_w = fopen("arquivos_prod/dado_e.txt","w");


    if( arq_w != NULL){
        char s[40];
        for(int i = 0; i < 10; i++){
            scanf("%s",s);
            fprintf(arq_w, "%d - %s\n", i, s);
        }
        fclose(arq_w);
    }else printf("ERROR AO ABRIR");


    return 0;
} 