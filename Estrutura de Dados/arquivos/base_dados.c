#include <stdio.h>
#include<stdlib.h>

typedef struct Funcionarios{
    int id;
    char nome[40];
    char cpf[15];
    data_nasc[11];
    double salario;
}TFunc;
void salvaBin(TFunc *fun, FILE* out);
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