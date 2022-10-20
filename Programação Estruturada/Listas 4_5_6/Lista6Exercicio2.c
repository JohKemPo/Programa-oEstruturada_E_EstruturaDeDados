#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

/*
2. Escreva uma função em C que receba como parâmetro uma cadeia de caracteres,
contendo apenas letras entre 'A' e 'Z' ou 'a' e 'z' e espaços em branco,

e retorne uma nova cadeia -- alocada dinamicamente --, contendo uma cópia da cadeia original, mas
sem espaços em branco no início ou no final, isto é, sem qualquer caractere ' ' (espaço)
localizado antes da primeira letra ou depois da última letra da cadeia. Por simplificação,
considere que a cadeia de entrada possui no mínimo uma letra (entre 'A' e 'Z' ou 'a' e
'z'). Por exemplo, se a cadeia “ nota do aluno ” (com três espaços em branco no início
e dois no final) for passada para a função, a cadeia retornada deve ser “nota do aluno”,
sem nenhum espaço no início ou no final. Se não for possível alocar dinamicamente a
nova cadeia, a função deve retornar NULL. O protótipo da função é:
char *compactar(char *s);
*/

char *compactar(char *s);

int main(){  

    char* compactada;
    char frase[100];


    //Printf lê a entrada até encontrar um espaço, um "enter" ou uma tabulação, ou seja, até encontrar ' ', '\n' ou '\t'.
    //AJUDA - https://www.ic.unicamp.br/~norton/disciplinas/mc1022s2005/06_10.html

    printf("DIGITE: ");
    gets(frase);
    printf("ANTES - [%s",frase);
    printf("]\n");

    compactada = compactar(frase);
    printf("%s", compactada);
    free(compactada);

    return 0;
}

char *compactar(char *s){ 
    int len = 0, i, position = 404, position_f = 404, posit = 0, k;
    char* nova;

    //testa espaço no inicial
    for(i = 0; s[i] != '\0';i++){
        if(s[i] != ' '){
            printf("Encontrou uma letra\n");
            break;
        }else{
            printf("Sem espaços no ini\n");
            position = i+1;
        };
    }
      
    
    //testa final antes do espaço
    if(position == 404){
        position = 0;
        printf("Inicial - %d\n", position);
        for (int j = position; s[j] != '\0'; j++){
        if (s[j] != ' '){
            position_f = j;
            }
        }
    }else{
        printf("Inicial - %d\n", position);
        for (int j = position; s[j] != '\0'; j++){
        if (s[j] != ' '){
            position_f = j;
            }
        }
    }

    //len da nova string
    printf("Final - %d\n", position_f);
    len = position_f - position + 1;

    printf("%d\n", len);
 

    //aloca
    nova = (char*) malloc(len * sizeof(char));

    if(nova == NULL){return NULL;}

    //preenche
    for(k = position; k <= position_f; k++){
        nova[posit] = s[k];
        posit++;
    }
    nova[k++] = '\0';

    return nova;

}
