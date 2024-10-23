#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} DequeNode_t;

typedef struct queue{
    DequeNode_t* head;
    DequeNode_t* tail;
} Deque_t;

DequeNode_t* createQueueNode(int data){
    DequeNode_t* new_node = malloc(sizeof(DequeNode_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

Deque_t* createDeque(){
    Deque_t* new_queue = malloc(sizeof(Deque_t));
    if (new_queue == NULL) return NULL;

    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

void push_front(Deque_t** q, int data){
    DequeNode_t* temp = (*q)->head;
    DequeNode_t* new_node = createQueueNode(data);
    
    new_node->next = temp;

    if((*q)->head != NULL){
        if((*q)->tail->prev == NULL){
            (*q)->tail->prev = (*q)->head->next;
        }
        (*q)->head->prev = new_node;
    }
    
    if ((*q)->head == NULL){
        (*q)->tail = new_node;
    }

    (*q)->head = new_node;
}

void push_back(Deque_t** q, int data){
    DequeNode_t* new_node = createQueueNode(data);
    
    if((*q)->tail == NULL){
        (*q)->head = new_node;
        (*q)->tail = new_node;
    }
    else{
        (*q)->tail->next = new_node;
        new_node->prev = (*q)->tail;
        (*q)->tail = new_node;
    }
}

int pop_back(Deque_t* q) {
    if (q->tail == NULL) return -1;
    DequeNode_t* temp = q->tail;
    int value = temp->data;

    q->tail = q->tail->prev;
    if (q->tail != NULL) q->tail->next = NULL;
    else q->head = NULL;
    
    free(temp);

    return value;
}

int pop_front(Deque_t* q) {
    if (q->head == NULL) return -1;

    DequeNode_t* temp = q->head;
    int value = temp->data;

    q->head = q->head->next;
    if (q->head != NULL) q->head->prev = NULL;
    else q->tail = NULL;

    free(temp);

    return value;
}

int peek_front(Deque_t* q){
    DequeNode_t* node = q->head;
    if (node == NULL) return 0;

    return node->data;
}

int peek_back(Deque_t* q){
    DequeNode_t* node = q->tail;
    if (node == NULL) return 0;

    return node->data;
}

int isDequeEmpty(Deque_t* q){
    DequeNode_t* node = q->head;
    return (node == NULL) ? 1:0;
}

void printDeque(Deque_t* q){
    DequeNode_t* node = q->head;
    while (node != NULL) {
        printf("%d->", (node->data));
        node = node->next;
    }
    printf("NULL\n");
}

int main(void){
    Deque_t* dq = createDeque();

    printf("Push Back\n");
    for(int i=0; i<5; i++) push_back(&dq, i);
    printDeque(dq);

    printf("\nPush Front\n");
    for(int i=5; i<10; i++) push_front(&dq, i);
    printDeque(dq);

    printf("\nPeek Back: %d\n", peek_back(dq));
    printDeque(dq);

    printf("\nPeek Front: %d\n", peek_front(dq));
    printDeque(dq);

    printf("\nPop Back: %d\n", pop_back(dq));
    printDeque(dq);

    printf("\nPop Front: %d\n", pop_front(dq));
    printDeque(dq);

    printf("\nEmptying Deque\n");
    printDeque(dq);
    while(!isDequeEmpty(dq))pop_back(dq);
    printDeque(dq);


    return 0;
}