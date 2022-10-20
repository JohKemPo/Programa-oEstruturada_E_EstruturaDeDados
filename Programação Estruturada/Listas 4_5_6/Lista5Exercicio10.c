#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

/*
10. Fazer um programa para cadastro e diálogo de login. 

O programa deve:

a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente os
caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.

b. Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.

c. Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos
descritos nos itens a e b.

d. Comparar o nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário, informar “Acesso
negado”.
*/

int getch();
int main(){

    char name[8], senha[8];// string com nome atual e senha atual
    char var, aux = 1;// var caractere digitado, aux boleano para teste
    int cont = 0, negados = 14;// cont para posições nos vetores name e senha, quantidades neg de caract negados
    char neg[14] = {'!','@','#','$','%','&','*','(',')','_','-','+','=',' '};
    char usuarios[2], senhas[2];//contem os 2 users e keys

    setlocale(LC_ALL,"Portuguese");

    for(int k = 0; k < 2; k++){
        cont = 0;
        
        //NOME USUARIO
        printf("\nUSUÁRIO: \n");
        while (cont < 8){
            aux = 1;
            var = getch();

            for(int j = 0; j < negados; j++){
                if( (var == neg[j]) == 1){
                    aux = 0;                  
                }
            }
            if(aux == 1){
                printf("%c", var);
                name[cont] = var;
                cont++;
            }
                        
        }
        name[8] = '\0';
        usuarios[k] = *name;

        //SENHA
        printf("\nSENHA: \n");
        cont = 0;
        
        while (cont < 8){
            aux = 1;
            var = getch();

            for(int j = 0; j < negados; j++){
                if( (var == neg[j]) == 1){
                    aux = 0;                  
                }
            }
            if(aux == 1){
                printf("%c", '*');
                senha[cont] = var;
                cont++;
            }
                
        }
        senha[8] = '\0';
        senhas[k] = *senha;

    }
    
    printf("%s", usuarios);
    printf("%s", senhas);

    if((usuarios[0] == usuarios[1]) && (senhas[0] == senhas[1])){
        printf("\nOK");
    }else printf("\nAcesso negado");
    
    return 0;
}

