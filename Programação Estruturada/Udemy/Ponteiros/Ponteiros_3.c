#include <stdio.h>
#include<locale.h>

int main(){
    //ARRAY unidimensional --> vetor ( lista )


    /*
        0   1   2   3
      -----------------
      |   |   |   |   |
      -----------------
    */
    setlocale(LC_ALL,"Portuguese");

    int valor[4];//ponteiro aponta para o primeiro end de memo end 0

    for(int i = 0; i < 4; i++){
        printf("Informe o valor %d de 5: ", (i+1));
        scanf("%d", &valor[i]);

    }


    printf("Os valores informados foram: \n");
    for(int i = 0; i < 4; i++){
        printf("valor na posi��o I: %d\n", valor[i]);
        printf("Endere�o na posi��o I: %d\n", &valor[i]);
    }


    printf("\n Primeiro endere�o: %d", &valor);
    printf("\n Endere�o 0: %d", &valor[0]);

    return 0;
}
