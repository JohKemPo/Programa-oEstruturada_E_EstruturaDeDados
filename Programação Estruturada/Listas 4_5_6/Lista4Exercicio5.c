#include <stdio.h>
#include <locale.h>
#include <math.h>


/*
5. Desde mar�o deste ano, os 33 t�xis da cidade de Rio das Ostras tiveram que instalar a aferir
tax�metros para o c�lculo do valor das corridas. De acordo com a tabela em vigor, a tarifa inicial
(ou bandeirada) custa R$4,95. Al�m disso,

para cada quil�metro percorrido s�o cobrados mais
R$2,50, na bandeira 1,
ou R$3,00, na bandeira 2.

Escreva uma fun��o em C que calcula os valores
da corrida de t�xi em Rio das Ostras.

 A fun��o recebe como par�metros o valor real dist,
correspondendo � dist�ncia percorrida pelo t�xi (em quil�metros), e os ponteiros b1 e b2,
indicando os endere�os onde devem ser armazenados, respectivamente, os valores calculados
para a corrida na bandeira 1 e na bandeira 2.
void calcula_corrida(float dist, float *b1, float *b2);
*/

void calcula_corrida(float dist, float *b1, float *b2){

    float ban1 = *b1, ban2 = *b2;
    float tarifa_ini = 4.95, dist_flo;
    float p1, p2;
    int dist_int;

    printf("%f\n", dist);
    dist_int = trunc(dist);
    printf("%d\n", dist_int);
    printf("%f\n", dist);
    dist_flo = dist - dist_int;
    printf("%f\n", dist_flo);

    p1 = tarifa_ini + dist_int * ban1 + dist_flo * ban1;

    p2 = tarifa_ini + dist_int * ban2 + dist_flo * ban2;


    printf("Valor da bandeira 1 R$ %.2f \nValor da bandeira 2 R$ %.2f  \nPara a distÂncia %.2fKm. ", p1,p2,dist );

}

int main(){

    setlocale(LC_ALL,"Portuguese");

    float dist = 2.5;
    float b1 = 2.50;
    float b2 = 3.00;
    float p1, p2;

    printf("Digite a distância percorrida: ");
    scanf("%f",&dist);

    printf("%f\n", dist);
    calcula_corrida(dist, &b1, &b2);

    return 0;
}



