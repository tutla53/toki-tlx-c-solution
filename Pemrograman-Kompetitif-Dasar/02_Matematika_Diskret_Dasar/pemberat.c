#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int ull;

typedef struct{
    void *next;
    ull data;
} Stack_t;

Stack_t* createNode(ull data){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    return new_node;
}

void push(Stack_t** st, ull data){
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
    ull B, K, diff, mass=1;
    Stack_t* st = NULL;

    scanf("%llu %llu", &B, &K);

    diff = K-B;

    while(diff>0){
        if(diff&1) push(&st, mass);
        mass = mass<<1;
        diff = diff>>1;
    }

    while(st != NULL){
        printf("%llu\n", st->data);
        pop(&st);
    }

    return 0;
}