#include <stdio.h>
#include <windows.h>

struct st_knot{
    int value;
    struct st_knot *next;
};

typedef struct st_knot knot;

int empty(knot *lst);
void release(knot *lst);
void display(knot *lst);
void insertS(knot *lst);
void insertE(knot *lst);
void start(knot *lst);
void menu(knot *lst, int op);
void search(knot *ls);

int main(){
    int op;

    knot *lst = (knot*) malloc(sizeof(knot));
    if(!lst)exit(1);

    start(lst);
    system("cls");
    do
    {
        
        printf("Select the option: \n");
        printf("[1] - Insert Start\n");
        printf("[2] - Insert End\n");
        printf("[3] - Release\n");
        printf("[4] - Display\n");
        printf("[5] - Empty\n");
        printf("[6] - Search\n");
        printf("[-1] - Exit\n");
        printf("Enter a option: ");
        scanf("%d", &op);

        menu(lst, op);
    } while (op != -1);
    
    return 0;
}

int empty(knot *lst){
    if(lst->next == NULL){
        return 1;
    }else return 0;
}

void start(knot *lst){
    lst->next = NULL;
}

void release(knot *lst){
    if(empty(lst) != 1){
        knot *currentP, *nextP;
        currentP = lst->next;
            
        while (currentP != NULL){
            nextP = currentP->next;
            free(currentP);
            currentP = nextP; 
        }
        start(lst);
    }
}

void search(knot *lst){
    knot *p;
    int value;

    printf("Digite um valor: ");
    scanf("%d", &value);

    for( p = lst; p != NULL; p = p->next){
        if(p->value == value){
            printf("Encontramos o valor.\n");
            printf("|%d|-> \n", p->value); 
        }
    }
}
void display(knot *lst){
    system("cls");
    if(empty(lst)){
        printf("Empty!\n\n");
        return;
    }
    knot *tmp;
    tmp = lst->next;

    while(tmp != NULL){
        //Sleep(1000);
        printf("|%d|-> ", tmp->value);
        tmp = tmp->next;
    }
    printf("[NULL]\n\n");
}


void insertS(knot *lst){
    knot *new = (knot*) malloc(sizeof(knot));
    if(new == NULL)exit(1);

    printf("Enter a value: ");
    scanf("%d", &new->value);

    knot *oldHead = lst->next;

    lst->next = new;
    new->next = oldHead;
    system("cls");
}

void insertE(knot *lst){
    knot * new = (knot*) malloc(sizeof(knot));
    if(new == NULL)exit(1);

    printf("Enter a value: ");
    scanf("%d", &new->value);
    new->next = NULL;

    if(empty(lst)){
        lst->next = new;
    }else{
        knot *tmp = lst->next;

        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new;

    }
    system("cls");
}

void menu(knot *lst, int op){
    
    
    

    switch (op){
    case 1:
        insertS(lst);
        break;
    case 2:
        insertE(lst);
        break;
    case 3:
        release(lst);
        break;
    case 4:

        display(lst);
        break;
    case 5:
        system("cls");
        if(empty(lst)){
            printf("Empty!\n\n");
        }else printf("Not empty.\n");
        break;
    case 6:
        
        search(lst);
        break;
    case -1:
        exit(1);
        break;
    default:
        printf("ERROR!");
        break;
    }
}

