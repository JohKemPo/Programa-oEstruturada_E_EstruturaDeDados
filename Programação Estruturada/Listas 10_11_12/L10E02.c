#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float busca (char* arquivo, char *matricula);

int main(){
    char mat[30] = "9010087-2";
    char name[11] = "L10E02.txt";
    float cr = 0;


    //printf("Digite a mat: ");
    //scanf("%30s", &mat);

    //printf("Digite o nome do arq: ");
    //scanf("%11s", &name);

    printf("M_%s\n", mat);
    cr = busca(name, mat);
    printf("CR: %.1f", cr);

    return 0;
}

float busca (char* arquivo, char *matricula){
    FILE *f = fopen(arquivo,"r");
    char info[121],  mat_a[30];
    float cr = 1.0;

    printf("M: %s\n", matricula);

    if(!f){
        printf("ERRO");
        exit(1);
    }

    //matricula = "9010087-2";
    while ((fgets(info,121,f) != NULL))
    {
        printf("----> %s", info);
        int aux = sscanf(info, "%s  %f", &mat_a, &cr);
        printf("M:%s C:%.1f\n", mat_a, cr);
        //printf("A: %s\n", arquivo);
        printf("\nTESTE:%s e %s = %d\n",matricula, mat_a, (mat_a == matricula));

        if(!strcmp(mat_a,matricula)){
            fclose(f);
            return cr;
        }else{
            cr = -1.0;
        }
    }
    fclose(f);
    return cr;
}
