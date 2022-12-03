#include <stdio.h>
#include <stdlib.h>

void write(FILE *arq){
    
    char value[10];

    arq = fopen("arquivo1.txt", "a");

    if(arq){
        
        while(value[0] != '0'){
            fputs(value, arq);
            printf("Enter 0 to exit\n");
            printf("Enter name: ");
            fgets(value, 10, stdin);
            
            
        }

        fclose(arq);

    }else{
        printf("ERROR READ FILE or\n");
        printf("ERROR CREATE FILE\n");
        exit(1);
    }
}

void read(FILE *arq){
    
    char info;

    arq = fopen("arquivo1.txt", "r");

    if(arq){
        
        while((info = getc(arq)) != EOF){
            printf("%c", info);
        }
    }else{
        printf("ERROR READ FILE or\n");
        printf("ERROR CREATE FILE\n");
        exit(1);
    }

    fclose(arq);

}
void menu(FILE *arq, int op){
    switch (op){
    case 0:
        write(arq);
        break;
    case 1:
        read(arq);
        break;
    case -1:
        break;
    default:
        printf("ERROR ENTER!");
        break;
    }
}
int main(){
    FILE *arq;
    int op;

    
    //w - Cria/abre para escrita, sobrescreve
    //r - Abre para leitura
    //a - write append 
    
     do
    {

        printf("\nSelect the option: \n");
        printf("[0] - Write\n");
        printf("[1] - Read file\n");        
        printf("Enter a option: ");
        scanf("%d", &op);

        menu(arq, op);
    } while (op != -1);

    fclose(arq);
    return 0;
}