#include <stdio.h>
/*
2. Mostre e explique (comentando as linhas de código) o que será impresso na tela:
*/
#include<stdio.h>
#include<string.h>
void main(void)
{
char texto[]= "foi muito facil";
int i;
for (i = 0; texto[i]!='\0'; i++)
{
if (texto[i] == ' ') break;
}
i++;// Aqui o i = 4
for ( ; texto[i]!='\0'; i++)//imprime 'm' e assim por diante
{
printf("%c", texto[i]);
}
}