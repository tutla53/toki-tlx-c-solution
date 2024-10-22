#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    /*Modified Doubly Linked List*/
    unsigned short int data;
    unsigned short int freq;
    struct Node* next;
    struct Node* prev;
} Node_t;

typedef struct queue{
    Node_t* head;
    Node_t* tail;
} ModifiedQueue_t;

Node_t* createNode(unsigned short int data, unsigned short int freq){
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->data = data;
    new_node->freq = freq;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ModifiedQueue_t* createQueue(){
    ModifiedQueue_t* new_queue = malloc(sizeof(ModifiedQueue_t));
    if (new_queue == NULL){
        return NULL;
    }
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

void push_front(ModifiedQueue_t* q, unsigned short int data, unsigned short int freq){
    
    /*Create New Head Node*/
    Node_t* temp = q->head;
    Node_t* new_node = createNode(data, freq);
    
    new_node->next = temp;

    if(q->head != NULL){
        if(q->tail->prev == NULL){
            q->tail->prev = q->head->next;
        }
        q->head->prev = new_node;
    }
    
    if (q->head == NULL){
        q->tail = new_node;
    }

    /*Point head to new node*/
    q->head = new_node;
}

void push_back(ModifiedQueue_t* q, unsigned short int data, unsigned short int freq){
    /*Create New Node*/
    Node_t* new_node = createNode(data, freq);
    if(q->tail == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        new_node->prev = q->tail;
        q->tail = new_node;
    }
}

void deleteAtEnd(ModifiedQueue_t* q) {
    if (q->tail == NULL) {
        return;
    }
    Node_t* temp = q->tail;
    q->tail = q->tail->prev;
        if (q->tail != NULL) {
            q->tail->next = NULL;
        } 
        else {
            q->head = NULL;
        }
    free(temp);
}

void deleteAtBeginning(ModifiedQueue_t* q) {
    if (q->head == NULL) {
        return;
    }

    Node_t* temp = q->head;
    q->head = q->head->next;
    if (q->head != NULL) {
        q->head->prev = NULL;
    } 
    else {
        q->tail = NULL;
    }
    free(temp);
}

unsigned short int getHeadData(ModifiedQueue_t* q){
    Node_t* node = q->head;
    if (node == NULL){
        return 0;
    }

    return node->data;
}

unsigned short int getHeadFreq(ModifiedQueue_t* q){
    Node_t* node = q->head;
    if (node == NULL){
        return -1;
    }

    return node->freq;
}

void setHeadFreq(ModifiedQueue_t* q, unsigned short int freq){
    Node_t* node = q->head;
    if (node == NULL){
        return;
    }
    if (freq<0){
        freq = 0;
    }
    node->freq = freq;
}

unsigned short int getTailData(ModifiedQueue_t* q){
    Node_t* node = q->tail;
    if (node == NULL){
        return -1;
    }
    return node->data;
}

unsigned short int getTailFreq(ModifiedQueue_t* q){
    Node_t* node = q->tail;
    if (node == NULL){
        return -1;
    }
    return node->freq;
}

void setTailFreq(ModifiedQueue_t* q, unsigned short int freq){
    Node_t* node = q->tail;
    if (node == NULL){
        return;
    }
    if (freq<0){
        freq = 0;
    }
    node->freq = freq;
}

unsigned short int isEmpty(ModifiedQueue_t* q){
    Node_t* node = q->head;
    if (node == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void printList2(ModifiedQueue_t* q){
    Node_t* node = q->head;
    while (node != NULL) {
        for (int i = 0; i<(node->freq); i++){
            printf("%hu->", (node->data));
        }
        node = node->next;
    }
    printf("NULL\n");
}

int main(void){
    ModifiedQueue_t* q = createQueue();

    if (q!=NULL){
        int N, count = 0, mode=0;
        char comm_msg[5];

        scanf("%d", &N);

        for (int i =0; i<N;i++){
            scanf("%s", comm_msg);

            if(strcmp(comm_msg, "add")==0){
                /*Add*/
                unsigned short int data, num;
                scanf("%hu %hu", &data, &num);
                if(mode == 0){
                    push_back(q, data, num);
                }
                else{
                    push_front(q, data, num);
                }
                count += num;
                printf("%d\n", count);
            }

            else if(strcmp(comm_msg, "del")==0){
                /*Del*/
                unsigned short int num, pop_element=0;
                scanf("%hu", &num);
                count = count - num;
                if (count<0) count = 0;
                
                if(!isEmpty(q)){
                    if(mode == 0) {
                        pop_element = getHeadData(q);
                        printf("%hu\n", pop_element);
                        
                        while (num>0){
                            unsigned short int head_freq = getHeadFreq(q);
                            if (head_freq == -1){
                                break;
                            }
                            if(head_freq > num){
                                setHeadFreq(q, head_freq-num);
                                break;
                            }
                            else{
                                num = num - head_freq;
                                deleteAtBeginning(q);
                            }
                        }
                    }
                    else {
                        pop_element = getTailData(q);
                        printf("%hu\n", pop_element);

                        while (num>0){
                            unsigned short int tail_freq = getTailFreq(q);
                            if (tail_freq == -1){
                                break;
                            }
                            if(tail_freq > num){
                                setTailFreq(q, tail_freq-num);
                                break;
                            }
                            else{
                                num = num - tail_freq;
                                deleteAtEnd(q);
                            }
                        }
                    }  
                }
            }

            else if(strcmp(comm_msg, "rev")==0){
                /*Reverse*/
                if (mode == 0) mode = 1;
                else mode = 0;
            }
        }
    }

    return 0;
}