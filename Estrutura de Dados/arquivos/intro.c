#include <stdio.h>
#include <stdlib.h>



int main(){

    // Associar uma STREAM a um arquivo e paos realizar a operação de abertura
    //// iniciializar CURSOR


    //estrtura de controle usada FILE stdio.h
    /*
    * fopen() - abre o rquivo
    * fclose() - fecha arquivo e descarrega o buffer automatic.
    * feof() - retorna TRUE se fim do arquivo
    * ferror() - retorna TRUE se houve erro
    * remove() - deleta arquivo
    * fflsuh() - descarrega buffer no arquivo
    * 
    * 
    * 
    * Modo

        Significado

        "r"	Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto.
        "w"	Abrir um arquivo texto para grava��o. Se o arquivo n�o existir, ele ser� criado. Se j� existir, o conte�do anterior ser� destru�do.
        "a"	Abrir um arquivo texto para grava��o. Os dados ser�o adicionados no fim do arquivo ("append"), se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o existente anteriormente.
        "rb"	Abre um arquivo bin�rio para leitura. Igual ao modo "r" anterior, s� que o arquivo � bin�rio.
        "wb"	Cria um arquivo bin�rio para escrita, como no modo "w" anterior, s� que o arquivo � bin�rio.
        "ab"	Acrescenta dados bin�rios no fim do arquivo, como no modo "a" anterior, s� que o arquivo � bin�rio.
        "r+"	Abre um arquivo texto para leitura e grava��o. O arquivo deve existir e pode ser modificado.
        "w+"	Cria um arquivo texto para leitura e grava��o. Se o arquivo existir, o conte�do anterior ser� destru�do. Se n�o existir, ser� criado.
        "a+"	Abre um arquivo texto para grava��o e leitura. Os dados ser�o adicionados no fim do arquivo se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o existente anteriormente.
        "r+b"	Abre um arquivo bin�rio para leitura e escrita. O mesmo que "r+" acima, s� que o arquivo � bin�rio.
        "w+b"	Cria um arquivo bin�rio para leitura e escrita. O mesmo que "w+" acima, s� que o arquivo � bin�rio.
        "a+b"	Acrescenta dados ou cria uma arquivo bin�rio para leitura e escrita. O mesmo que "a+" acima, s� que o arquivo � bin�rio


    */

    // FILE *arq = fopen("arquivos_prod/dado.txt","w");
    // fclose(arq);

    FILE *arq_r = fopen("arquivos_prod/dado.txt","r");


    if( arq_r != NULL){
        char c;
        char s[40];
        // while((c = fgetc(arq_r)) != EOF){
        //     printf("%c", c);
        // }
        // while((fscanf9arq, "%s", s) != EOF) tbm pode ser usado
        while(!feof(arq_r)){
            fscanf(arq_r, "%s", s);
            printf("TESTE - %s\n", s);
        }
        fclose(arq_r);
    }else printf("ERROR AO ABRIR");


    return 0;
}