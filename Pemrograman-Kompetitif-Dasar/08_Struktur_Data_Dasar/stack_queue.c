#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push_front(struct Node** head, struct Node** tail, int data){
    
    /*Create New Node*/
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    new_node->prev = NULL;

    if(*head != NULL){
        if((*tail)->prev == NULL){
            (*tail)->prev = (*head)->next;
        }
        (*head)->prev = new_node;
    }
    
    if(*head == NULL){
        *tail = new_node;
    }

    (*head) = new_node;
}

void push_back(struct Node** head, struct Node** tail, int data){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = (*tail);

    if (*head == NULL){
        *head = new_node;
        *tail = *head;
        return;
    }

    (*tail)->next = new_node;
    *tail = new_node;
};

void pop(struct Node** head, struct Node** tail, struct Node* del_node) {
    // if head or del is null, deletion is not possible
    if (*head == NULL || del_node == NULL)
        return;

    // if del_node is the head node, point the head pointer to the next of del_node
    if (*head == del_node)
        *head = del_node->next;

    // if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
    if (del_node->next != NULL){
        del_node->next->prev = del_node->prev;
    }

    // if del_node is not the first node, point the next of the previous node to the next node of del_node
    if (del_node->prev != NULL){
        (*tail) = del_node->prev;
        del_node->prev->next = del_node->next;
    }

    // free the memory of del_node
    free(del_node);
}

void pop_front(struct Node** head, struct Node** tail){
    if (*head == NULL) {
        *tail = NULL;
        return; // Empty list
    }

    // Store the current head
    struct Node* temp = *head;

    // Move head to the next node
    *head = (*head)->next;
    
    // Free memory of the old head
    free(temp);
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

void printList2(struct Node* node){
    while (node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(void){
    struct Node* head = NULL;
    struct Node* tail = NULL;

    int N;
    char comm_msg[15];

    scanf("%d", &N);

    for (int i =0; i<N;i++){
        scanf("%s", comm_msg);
        if(strcmp(comm_msg, "push_back")==0){
            int d;
            scanf("%d", &d);
            push_back(&head,&tail,d);
        }
        else if(strcmp(comm_msg, "push_front")==0){
            int d;
            scanf("%d", &d);
            push_front(&head, &tail, d);
        }
        else if(strcmp(comm_msg, "pop_back")==0){
            pop(&head, &tail, tail);
        }
        else if(strcmp(comm_msg, "pop_front")==0){
            pop(&head, &tail, head);
        }
    }
    
    printList(head);
    
    return 0;
}