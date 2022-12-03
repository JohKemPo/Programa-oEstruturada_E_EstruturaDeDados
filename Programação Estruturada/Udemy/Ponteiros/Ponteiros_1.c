#include <stdio.h>
#include <locale.h>// set idioma local



void incremento(int valor){// copia por valor
    ++valor;
    printf("O endere�o de var [dentro da fun��o_valor] %d e seu valor � %d\n", &valor, valor);
}

void incremento_end(int* valor){// copia por referencia
    ++(*valor);
    printf("O endere�o de var [dentro da fun��o_end] %d e seu valor � %d\n", &valor, (*valor));//(valor*) --> acessa o conteudo do ponteiro
}

int main(){

    setlocale(LC_ALL,"Portuguese");//reconhece o idioma pt-br

    int cont = 10;
    printf("Cont: %d\n", cont);
    printf("O endere�o de var [fora da fun��o] %d e seu valor � %d\n", &cont, cont);

    incremento(cont);// passa o valor de cont
    printf("N�o Incrementado [ref por valor] %d\n", cont);
    incremento_end(&cont); //atribui��o por endere�o
    printf("Incrementado [ref por endere�o] %d\n", cont);// Para que o valor de cont seja 11, apos incrementado, � necess�rio o uso de ponteiro ( para modificar diretamente a cont )

    return 0;
}
