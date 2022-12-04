
#include <stdlib.h>
#include <stdio.h>

typedef struct Funcionarios{
    int id;
    char nome[40];
    char cpf[15];
    char data_nasc[11];
    double salario;
}TFunc;

void salvaBin(TFunc *fun, FILE* out);
void salvaBin(TFunc *fun, FILE* out);
TFunc* leituraBin(FILE* in);
int tamanho_regsitro();
int tamanhoArquivo(FILE* arq);
void imprime(TFunc *func);