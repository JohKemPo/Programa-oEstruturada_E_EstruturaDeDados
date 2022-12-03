#include <stdio.h>
#include <windows.h>

#define TAMQUEUE 10


void list_elements(int *queue, int *head, int *tail);
void enqueue(int *queue, int *head, int *tail);
void dequeue(int *queue, int *head, int *tail);
void clear(int *queue, int *head, int *tail);



int main(){
    int queue[TAMQUEUE] = {0,0,0,0,0,0,0,0,0,0};
    int head = 0, tail = 0;
    system("cls");
    printf("\n======= FILA =======\n");
    int option = 0;

    do{
        printf("Select the option: \n");
        printf("[1] - Add\n");
        printf("[2] - Remove\n");
        printf("[3] - List\n");
        printf("[4] - Clear\n");
        printf("[-1] - Exit\n");
        printf("Option: ");
        scanf("%d", &option);



        switch (option){
        case 1:
            enqueue(queue, &head, &tail);
            break;
        case 2:
            dequeue(queue, &head, &tail);
            break;
        case 3:
            list_elements(queue, &head, &tail);
            break;
        case 4:
            clear(queue, &head, &tail);
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

void list_elements(int *queue, int *head, int *tail){
    
    
    system("cls");
    for( int i = 0; i < TAMQUEUE; i++){
        printf(" %d |", queue[i]);
    }
    printf("\nHEAD: %d\n", *head);
    printf("TAIL: %d\n", *tail);
    printf("\n\n");
}

void enqueue(int *queue, int *head, int *tail){
    int val, aux_head = *head, aux_tail = *tail;

    if( *tail < TAMQUEUE){
        printf("Enter a value to add to the queue: ");
        scanf("%d", &val);
        queue[*tail] = val;
        *tail += 1;
        aux_tail += 1;
        // **head
        list_elements(queue, &aux_head, &aux_tail);

    }else printf("FULL!\n");
}

void dequeue(int *queue, int *head, int *tail){
    int aux_head = *head, aux_tail = *tail;
    if( * head < *tail){
        queue[*head] = 0;
        *head += 1;
        aux_head += 1;
        list_elements(queue, &aux_head, &aux_tail);
    }else{
        printf("A fila está vazia.\n");
    }
}

void clear(int *queue, int *head, int *tail){
    int aux_head = *head, aux_tail = *tail;
    for(int i = 0; i < TAMQUEUE; i++){
        queue[i] = 0;
    }
    *head = 0;
    aux_head = 0;
    *tail = 0;
    aux_tail = 0;

    list_elements(queue, &aux_head, &aux_tail);
}
