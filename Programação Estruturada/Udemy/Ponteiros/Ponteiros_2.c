#include <stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL,"Portuguese");


    int n;// Var q quarda um valor

    //Delcarando ponteiro
    int* p;// ponteiro para um endere�o de memoria

    printf("Digite um valor:");
    scanf("%d", &n);// salva o valor no endere�o de n

    //inicializando vetor
    p = &n;// p agora guarda o endere�o de n

    printf("Valor: %d\n", n);
    printf("Endere�o original %d\n", &n);

    printf("Endere�o do ponteiro em hex %p\n", p);
    printf("Endere�o do ponteiro em int %d\n", p);
    printf("Valor guardado em poteiro %d", *p);

    return 0;
}
