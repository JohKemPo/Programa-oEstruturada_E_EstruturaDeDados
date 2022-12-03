#include <stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL,"Portuguese");


    int n;// Var q quarda um valor

    //Delcarando ponteiro
    int* p;// ponteiro para um endereço de memoria

    printf("Digite um valor:");
    scanf("%d", &n);// salva o valor no endereço de n

    //inicializando vetor
    p = &n;// p agora guarda o endereço de n

    printf("Valor: %d\n", n);
    printf("Endereço original %d\n", &n);

    printf("Endereço do ponteiro em hex %p\n", p);
    printf("Endereço do ponteiro em int %d\n", p);
    printf("Valor guardado em poteiro %d", *p);

    return 0;
}
