#include <stdio.h>
#include <string.h>
#include<locale.h>

/*
union é um struct que separa na memo o espaço eq ao espaço da maior var.

ela sobreescreve a informação

REVER AULA 64
*/

union pessoa{
    char nome[100];//  tamanho ocupado em memo uma char ocupa 1 byte --> 1*100 = 100 bytes
    int idade;// 4 bytes
}pessoa_1;// TOTAL = 104 bytes


int main(){

    setlocale(LC_ALL,"Portuguese");

    strcpy(pessoa_1.nome, "joao");
    printf("Tem %s.\n",pessoa_1.nome, pessoa_1.idade);

    pessoa_1.idade = 23;
    printf("Tem %d anos.\n",pessoa_1.nome, pessoa_1.idade);

    printf("%s tem %d anos.\n",pessoa_1.nome, pessoa_1.idade);// a informação "joao" foi sobrescrita por 23
    printf("union pessoa ocupa %ld bytes na memoria\n",sizeof(pessoa_1));
    return 0;
}


