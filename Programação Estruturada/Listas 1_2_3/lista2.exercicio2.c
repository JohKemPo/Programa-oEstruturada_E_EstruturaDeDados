#include<stdio.h>
int main(){
	int repete;
	int i=1;
	int soma=0;
	int cont=0;
	printf("Quantos numeros para repetir: ");
	scanf("%d",&repete);
	for(;cont<repete;cont){
		soma = soma+i;
		i=i+2;
		cont++;
	}
	printf("%d", soma);
	return 0;
}
