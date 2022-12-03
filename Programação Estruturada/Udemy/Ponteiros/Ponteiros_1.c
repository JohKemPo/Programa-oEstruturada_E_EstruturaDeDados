#include <stdio.h>
#include <locale.h>// set idioma local



void incremento(int valor){// copia por valor
    ++valor;
    printf("O endereço de var [dentro da função_valor] %d e seu valor é %d\n", &valor, valor);
}

void incremento_end(int* valor){// copia por referencia
    ++(*valor);
    printf("O endereço de var [dentro da função_end] %d e seu valor é %d\n", &valor, (*valor));//(valor*) --> acessa o conteudo do ponteiro
}

int main(){

    setlocale(LC_ALL,"Portuguese");//reconhece o idioma pt-br

    int cont = 10;
    printf("Cont: %d\n", cont);
    printf("O endereço de var [fora da função] %d e seu valor é %d\n", &cont, cont);

    incremento(cont);// passa o valor de cont
    printf("Não Incrementado [ref por valor] %d\n", cont);
    incremento_end(&cont); //atribuição por endereço
    printf("Incrementado [ref por endereço] %d\n", cont);// Para que o valor de cont seja 11, apos incrementado, é necessário o uso de ponteiro ( para modificar diretamente a cont )

    return 0;
}
