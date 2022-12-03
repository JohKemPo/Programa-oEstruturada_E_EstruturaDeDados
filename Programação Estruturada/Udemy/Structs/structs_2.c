#include <stdio.h>
#include <locale.h>
#include <string.h>

//Estrutura
/*
Structs --> são estruturas de dados



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

}alunos[2];

int main(){
    setlocale(LC_ALL, "Portuguese");


    //struct st_aluno aluno_1;

    for(int i = 0; i < 2; i++){

        printf("Informe a matrícula do aluno: ");
        scanf("%s",&alunos[i].matricula);

        printf("Informe o nome do aluno: ");
        scanf("%s",&alunos[i].nome);

        printf("Informe o curso do aluno: ");
        scanf("%s",&alunos[i].curso);

        printf("Informe a data de nascimento do aluno: ");
        scanf("%d",&alunos[i].nascimento);

    }


    for(int i = 0; i < 2; i++){

        printf("\n =========== Dados do aluno =========== \n");
        printf("Matrícula: %s\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Ano de nascimento: %d\n", alunos[i].nascimento);

    }

    return 0;
}

