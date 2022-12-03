#include <stdio.h>
#include <stdlib.h>



int main(){

    FILE *arq_A = fopen("arquivos_prod/dado_A.txt","r");
    FILE *arq_B = fopen("arquivos_prod/dado_B.txt","r");
    FILE *arq_C = fopen("arquivos_prod/dado_C.txt","w");


    if( arq_A != NULL && arq_B != NULL){
        char aux[20];
        char s[20];
        while((fscanf(arq_A, "%s", aux)) != EOF){
            fprintf(arq_C,"%s\n",aux);
        }
        while((fscanf(arq_B, "%s", aux)) != EOF){
            fprintf(arq_C,"%s\n",aux);
        }

        fclose(arq_C);
        FILE *arq_C = fopen("arquivos_prod/dado_C.txt","r");


        // IMPRIME A MAIS ultima linha em branco
        // while(!feof(arq_C)){
        //     fscanf(arq_C, "%s", s);
        //     printf("TESTE - %s\n", s);
        // }

        while((fscanf(arq_C,"%s",s)) != EOF){
            printf("%s\n", s);
        }

        fclose(arq_A);
        fclose(arq_B);
        fclose(arq_C);

    }else printf("ERROR AO ABRIR");


    return 0;
} 