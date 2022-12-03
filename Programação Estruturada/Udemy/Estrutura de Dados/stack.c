#include <stdio.h>
#include <windows.h>

#define TAMSTACK 5


void list_elements(int *stack, int *top);
void push(int *stack, int *top);
void pop(int *stack, int *top);
void clear(int *stack, int *top);



int main(){
    int stack[TAMSTACK] = {0,0,0,0,0};
    int top = 0;

    system("cls");
    printf("\n======= FILA =======\n");
    int option = TAMSTACK;

    do{
        printf("Select the option: \n");
        printf("[1] - Pussh\n");
        printf("[2] - Remove\n");
        printf("[3] - List\n");
        printf("[4] - Clear\n");
        printf("[-1] - Exit\n");
        printf("Option: ");
        scanf("%d", &option);



        switch (option){
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            list_elements(stack, &top);
            break;
        case 4:
            clear(stack, &top);
            break;
        case -1:
            exit(1);
            break;
        default:
        printf("OPTION ERROR!\n");
            break;
        }
    }while( option != -1);

    return 0;
}

void list_elements(int *stack, int *top){

    int aux = TAMSTACK;
    
    system("cls");
    for( int i = 1; i <= TAMSTACK; i++){
        printf("| %d |\n", stack[aux - i]);
    }
    printf("\nTOP: %d\n", *top);
    printf("\n\n");
}

void push(int *stack, int *top){
    int val, aux_top = *top;

    if( *top < TAMSTACK){
        printf("Enter a value to add to the stack: ");
        scanf("%d", &val);
        stack[*top] = val;
        *top += 1;
        aux_top += 1;
        list_elements(stack, &aux_top);

    }else printf("FULL!\n");
}

void pop(int *stack, int *top){
    int aux_top = *top;
    
    if( *top != 0){
        *top -= 1;
        stack[*top] = 0;
        
        aux_top -= 1;
        list_elements(stack, &aux_top);
    }else{
        printf("A fila está vazia.\n");
    }
}

void clear(int *stack, int *top){
    int aux_top = *top;
    for(int i = 0; i < TAMSTACK; i++){
        stack[i] = 0;
    }
    *top = 0;
    aux_top = 0;

    list_elements(stack, &aux_top);
}
