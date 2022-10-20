#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
1. Escreva uma função em C que receba como parâmetros um vetor (vet) de n números
reais e um ponteiro para inteiro (tam) e retorne o ponteiro para um novo vetor, alocado
dinamicamente, contendo somente os elementos do vetor original que são maiores que
a média de todos os valores. Por exemplo, o vetor {5.5, 3.2, 2.5, 9.4, 7.5, 4.1, 5.4, 8.0,
6.9}, daria origem ao vetor {9.4, 7.5, 8.0, 6.9}, de tamanho 4. No ponteiro para inteiro
deverá ser armazenado o tamanho do novo vetor. Se não for possível alocar o novo
vetor, a função deve retornar NULL.

float *acima_da_media(int n, float *vet, int *tam);

1) Calcular a média de vet
2) verificar quantos elementos de vet são maiores do que a média
3) alocar dinamicamente um vetresposta conforme o tamanho verificado no item 2
4) preencher o vetresposta com os elementos do item 2
5) atualizar a variável ponteiro tam com o tamanho do novo vetor
*/

float *acima_da_media(int n, float *vet, int *tam);

int main(){

    setlocale(LC_ALL,"portuguese");

    int tam,n;
    float *v,*vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v= (float*) malloc(n * sizeof(float));

    if(v == NULL){printf("EXIT");exit(1);}

    for(int i = 0; i < n;i++){
        printf("Digite o valor [%d/%d] - ", i+1, n);
        scanf("%f", &v[i]);// NUNCA ESQUECER QUE ISSO É A CACETA DE UM PONTEIRO, GRATO
    }

    vetor = acima_da_media(n,v,&tam);

    for(int i = 0; i < tam; i++){
        printf("%.1f\n", vetor[i]);
    }
    printf("%d",tam);
    
    free(v);
    free(vetor);
    return 0;
}

float *acima_da_media(int n, float *vet, int *tam){

    float total, media;
    int cont = 0, position = 0;
    float *vetoresposta;


    for(int i = 0; i < n;i++){
        total += vet[i];
    }

    //1) Calcular a média de vet
    media = total/n;

    //2) verificar quantos elementos de vet são maiores do que a média
    for(int i = 0; i < n;i++){
        if(vet[i] > media){
            cont++;
        }
    }

    *tam = cont;//5) atualizar a variável ponteiro tam com o tamanho do novo vetor
    
    //3) alocar dinamicamente um vetresposta conforme o tamanho verificado no item 2

    vetoresposta = (float*) malloc(cont * sizeof(float));

    if(vetoresposta == NULL){printf("!!!!!!!!!!");return NULL;exit(1);}
    //4) preencher o vetresposta com os elementos do item 2

    for(int i = 0; i < n; i++){
        if(vet[i] > media){
            vetoresposta[position]  = vet[i];
            position++;
        }
    }

    return vetoresposta;
}

