#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} QueueNode_t;

typedef struct queue{
    QueueNode_t* head;
    QueueNode_t* tail;
} Queue_t;

QueueNode_t* createQueueNode(int data){
    QueueNode_t* new_node = malloc(sizeof(QueueNode_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

Queue_t* createQueue(){
    Queue_t* new_queue = malloc(sizeof(Queue_t));
    if (new_queue == NULL) return NULL;

    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

void enqueue(Queue_t** q, int data){
    QueueNode_t* new_node = createQueueNode(data);
    
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

int dequeue(Queue_t** q) {
    if ((*q)->head == NULL) return -1;

    QueueNode_t* temp = (*q)->head;
    int value = temp->data;
    (*q)->head = (*q)->head->next;

    if ((*q)->head != NULL) (*q)->head->prev = NULL;
    else (*q)->tail = NULL;
    free(temp);

    return value;
}

int peekQueue(Queue_t* q){
    QueueNode_t* node = q->head;
    if (node == NULL) return -1;

    return node->data;
}

int isQueueEmpty(Queue_t* q){
    QueueNode_t* node = q->head;

    if (node == NULL) return 1;
    return 0;
}

void printQueue(Queue_t* q){
    QueueNode_t* node = q->head;
    while (node != NULL) {
        printf("%d->", (node->data));
        node = node->next;
    }
    printf("NULL\n");
}

int main(void){
    Queue_t* q = createQueue();

    printf("Enqueue\n");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printQueue(q);

    printf("\nPeek: %d\n", peekQueue(q));
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(&q));
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(&q));
    printQueue(q);
    
    printf("\nEnqueue\n");
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    printQueue(q);


    printf("\nEmptying the Queue\n");
    while(!isQueueEmpty(q)) dequeue(&q);
    
    printQueue(q);

    return 0;
}