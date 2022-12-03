#include <stdio.h>
#include <locale.h>
#include <string.h>

//Estrutura
/*
Structs --> s�o estruturas de dados



FORMAS DE DECLARAR
struct st_aluno{//st = struct
    char matricula[10];
    char nome[10];
    char curso[10];
    int nascimento;

}VAR1, VAR2, VAR3;

OU

struct st_aluno VAR1, VAR2, VAR3;
*/

struct st_aluno{//st = struct
    char matricula[10];
    char nome[10];
    char curso[10];
    int nascimento;

};

int main(){
    setlocale(LC_ALL, "Portuguese");


    struct st_aluno aluno_1;

    printf("Informe a matr�cula do aluno: ");
    scanf("%s",&aluno_1.matricula);
/*
    printf("Informe a matr�cula do aluno: ");
    fgets(aluno_1.matricula, 10, stdin);
*/
    printf("Informe o nome do aluno: ");
    scanf("%s",&aluno_1.nome);

    printf("Informe o curso do aluno: ");
    scanf("%s",&aluno_1.curso);

    printf("Informe a data de nascimento do aluno: ");
    scanf("%d",&aluno_1.nascimento);

    printf("Matr�cula: %s\n", aluno_1.matricula);
    printf("Nome: %s\n", aluno_1.nome);
    printf("Curso: %s\n", aluno_1.curso);
    printf("Ano de nascimento: %d\n", aluno_1.nascimento);

    return 0;
}
