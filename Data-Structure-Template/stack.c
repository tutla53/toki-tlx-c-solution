#include<stdio.h>
#include<stdlib.h>

typedef struct{
    void *next;
    int data;
} Stack_t;

Stack_t* createStackNode(int data){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    return new_node;
}

void push(Stack_t** st, int data){
    Stack_t* new_node = createStackNode(data);
    new_node->data = data;

    new_node->next = (*st);
    *st = new_node;   
}

int pop(Stack_t** st) {
    if ((*st) == NULL) return -1;

    Stack_t* temp = *st;
    int value = temp->data;

    *st = (*st)->next;
    free(temp);
    return value;
}

int peekStack(Stack_t* q){
    if (q == NULL) return -1;
    return q->data;
}

int isStackEmpty(Stack_t* q){
    if (q == NULL) return 1;
    return 0;
}

void printStack(Stack_t* st){
    while (st != NULL) {
        printf("%d->", st->data);
        st = st->next;
    }
    printf("NULL\n");
}

int main(void){
    Stack_t* st = NULL;

    printf("Push\n");
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    printStack(st);

    printf("\nPeek: %d\n", peekStack(st));
    printStack(st);

    printf("\nPop: %d\n", pop(&st));
    printStack(st);

    printf("\nPop: %d\n", pop(&st));
    printStack(st);
    
    printf("\nPush\n");
    push(&st, 5);
    push(&st, 6);
    push(&st, 7);
    printStack(st);

    printf("\nEmptying the Queue\n");
    while(!isStackEmpty(st)) pop(&st);
    
    printStack(st);

    return 0;
}