/*
3. Crie uma lista encadeada onde cada elemento contém informações de um aluno. Crie
funções para o gerenciamento da lista: imprimir, excluir, incluir e alterar.
Aplique essas funções a partir de uma lista carregado do arquivo.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    char info[121];
    char c;
    int i = 0;
    FILE *f = fopen("input.txt", "rt");
    if(!f){
        printf("ERRO");
        exit(1);
    }
    /*LEITURA PULA ESPAÇO
    while(fscanf(f, "%s", &info) == 1){
        
        printf("%s\n", info);
    }*/

    /* LEITURA CARACT 
    do
    {
        c = fgetc(f);
        printf("%c",c);
    } while (c != EOF);
    */

    while((fgets(info, 121, f) != NULL)){
        i++;
        printf("%s", info);
    }
   
    
        
    
    fclose(f);


    return 0;
}