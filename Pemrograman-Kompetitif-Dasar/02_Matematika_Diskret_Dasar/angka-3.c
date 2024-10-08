#include<stdio.h>
#include<stdlib.h>

typedef struct{
    void *next;
    unsigned short int data;
} Stack_t;

Stack_t* createNode(unsigned short int data){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    return new_node;
}

void push(Stack_t** st, unsigned short int data){
    Stack_t* new_node = createNode(data);
    new_node->data = data;

    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) return;

    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

int main(void){
    unsigned short int source, base;
    Stack_t* st = NULL;

    scanf("%hu %hu", &source, &base);
    
    while(source>0){
        push(&st, source%base);
        source /= base;
    }

    while (st != NULL) {
        printf("%d", st->data);
        st = st->next;
    }
    printf("\n");

    return 0;
}