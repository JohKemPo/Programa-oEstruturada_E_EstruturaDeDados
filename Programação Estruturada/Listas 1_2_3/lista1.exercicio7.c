#include <stdio.h>
#include <math.h>

int main (void){
    float num, arredondado;
    printf("Digite um numero: ");
    scanf("%f", &num);
    arredondado=round(num);
    printf ("Numero arredondado: %f", arredondado);
    return 0;
}
