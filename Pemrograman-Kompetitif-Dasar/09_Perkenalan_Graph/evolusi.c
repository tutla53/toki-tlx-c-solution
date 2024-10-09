#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    void *next;
    char data[25];
} Stack_t;

typedef struct Node{
    char name[25];
    struct Node* prev;
} Node_t;

Stack_t* createStackNode(char data[25]){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    strcpy(new_node->data, data);
    return new_node;
}

void push(Stack_t** st, char data[25]){
    Stack_t* new_node = createStackNode(data);
    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) return;
    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

Node_t* createNode(char name[25]){
    Node_t* node = malloc(sizeof(Node_t));
    strcpy(node->name, name);
    node->prev = NULL;

    return node;
}

int search_value(Node_t* sp[], int lenSP, char key[25]){
    for(int i=0; i<lenSP; i++){
        if(strcmp(key, sp[i]->name)==0){
            return i;
        }
    }
    return -1;
}

int print_ancestor(Node_t* sp, char key[25]){
    Node_t* temp = sp;
    Stack_t* st = NULL;
    int found = 0;
    
    while(!found){
        push(&st, temp->name);
        if (strcmp(key, temp->name)==0) found=1;
        if(temp->prev == NULL) break; 
        temp = temp->prev;
    }

    if(found){
        while(st!=NULL){
            printf("%s\n", st->data);
            pop(&st);
        }
    }
    return found;
}

int main(void){
    int N, M, idx=0, A_idx, B_idx, f1, f2;
    char dummy_name[25] = "ZZZZZZZZZZZZZZZZZZZZ", A[25], B[25];
    scanf("%d %d", &N, &M);
    Node_t* species_list[N];

    for(int i=0;i<N;i++) species_list[i] = createNode(dummy_name);

    for(int i=0; i<M; i++){
        char P[25], C[25];
        int P_idx, C_idx;

        scanf("%s %s", P, C);
        Node_t* P_temp = createNode(P);
        Node_t* C_temp = createNode(C);

        P_idx = search_value(species_list, idx, P);
        C_idx = search_value(species_list, idx, C);

        if(C_idx == -1)species_list[idx++] = C_temp;
        else C_temp = species_list[C_idx];

        if(P_idx == -1) {
            species_list[idx] = P_temp;
            C_temp->prev = species_list[idx];
            idx++;
        }
        else C_temp->prev = species_list[P_idx];
    }

    scanf("%s %s", A, B);
    A_idx = search_value(species_list, N, A);
    B_idx = search_value(species_list, N, B);

    f1 = print_ancestor(species_list[A_idx], B);
    f2 = print_ancestor(species_list[B_idx], A);

    if((f1 == 0) && (f2 == 0)) printf("TIDAK MUNGKIN\n");

    return 0;
}