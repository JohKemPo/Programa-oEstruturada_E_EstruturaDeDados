#include <stdio.h>
#include <locale.h>// set idioma local


/*
2. Escreva um programa em C para ler um vetor R (de 5 elementos) e um vetor S (de 10
elementos). Gere um vetor X que possua os elementos comuns a R e a S. Considere que pode
existir repetição de elementos no mesmo vetor. Nesta situação somente uma ocorrência do
elemento comum aos dois deve ser copiada para o vetor X. Após o término da cópia, escrever o
vetor X.
*/

int main(){

    setlocale(LC_ALL,"Portuguese");//reconhece o idioma pt-br

    int r[5] = {1,2,3,4,5};
    int s[10] = {1,2,3,4,5,6,7,8,9,10};
    //int* x;
    int* x;
    int n = 1;

    x = (int*) malloc(n *sizeof(int));

    if(x == NULL){printf("Memo insu\n");exit(1);}

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            if(r[i] == s[j]){

                n++;

                for(int k = 0; k < n; k++){
                    if((r[i] == x[k])){
                        break;
                    }else{
                        x = (int*)realloc(x,n*sizeof(int));
                        x[i] = r[i];
                        }
                }
            }
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", x[i]);
    }




    free(x);

    return 0;
}
