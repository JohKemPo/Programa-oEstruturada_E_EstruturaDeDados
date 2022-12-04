#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#include "[BIN] base_dados.h"

int main(){

    return 0;
}

void salvaBin(TFunc *fun, FILE* out){
    fwrite(&fun->id, sizeof(int),1,out);// unico que precisam de &
    fwrite(fun->nome, sizeof(char[40]),sizeof(fun->nome),out);
    fwrite(fun->cpf, sizeof(char[15]),sizeof(fun->cpf),out);
    fwrite(fun->data_nasc, sizeof(char[11]),sizeof(fun->data_nasc),out);
    fwrite(&fun->salario, sizeof(double),1,out);// unico que precisam de &
}

TFunc* leituraBin(FILE* in){
    TFunc *func = (TFunc*) malloc(sizeof(TFunc));

    if(0 != (fread(&func->id, sizeof(int), 1, in))){
        free(func);
        return NULL;
    }

    fread(func->nome,sizeof(char[40]),sizeof(func->nome),in);
    fread(func->cpf,sizeof(char[15]),sizeof(func->cpf),in);
    fread(func->data_nasc,sizeof(char[11]),sizeof(func->data_nasc),in);
    fread(&func->salario,sizeof(double),1,in);
    
    return func;
}
int tamanho_regsitro(){
    return sizeof(int) 
         + sizeof(char) * 40 
         + sizeof(char) * 15 
         + sizeof(char) * 11 
         + sizeof(double);
}

int tamanhoArquivo(FILE* arq){
    fseek(arq,0,   SEEK_SET);
    int tam = trunc(ftell(arq)/tamanho_registro());
}

void imprime(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de código ");
    printf("%d", func->id);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nCPF: ");
    printf("%s", func->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", func->data_nasc);
    printf("\nSalário: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}