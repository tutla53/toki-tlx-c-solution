#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 25

typedef int (*Compare)(const char *, const char *);

typedef struct{
    void *next;
    char data[MAXLEN];
} Stack_t;

typedef struct Node{
    char name[MAXLEN];
    struct Node* prev;
} Node_t;

typedef struct node{
    Node_t *value;           
    struct node *p_left;
    struct node *p_right;
}StrTreeNode_t;

Stack_t* createStackNode(char data[MAXLEN]){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    strcpy(new_node->data, data);
    return new_node;
}

void push(Stack_t** st, char data[MAXLEN]){
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

Node_t* createNode(char name[MAXLEN]){
    Node_t* node = malloc(sizeof(Node_t));
    strcpy(node->name, name);
    node->prev = NULL;

    return node;
}

void insert(Node_t** key, StrTreeNode_t** leaf, Compare cmp){
    int res;

    if((*leaf)== NULL){
        (*leaf) = malloc(sizeof(StrTreeNode_t));
        (*leaf)->value = *key;

        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
    } 
    else{
        res = cmp((*key)->name,(*leaf)->value->name);
        if(res < 0)
            insert(key, &(*leaf)->p_left, cmp);
        else if(res > 0)
            insert(key, &(*leaf)->p_right, cmp);
        else  
            return;
    }
}

int CmpStr(const char *a, const char *b){
    return (strcmp (a, b));   
}

Node_t* search(char key[MAXLEN], StrTreeNode_t* leaf, Compare cmp){
    int res;

    if(leaf != NULL ) {
        res = cmp(key, leaf->value->name);
        if(res < 0)
            return search(key, leaf->p_left, cmp);
        else if(res > 0)
            return search(key, leaf->p_right, cmp);
        else
            return leaf->value;
    }

    return NULL;
}

int search_value(Node_t* sp[], int lenSP, char key[MAXLEN]){
    for(int i=0; i<lenSP; i++){
        if(strcmp(key, sp[i]->name)==0){
            return i;
        }
    }
    return -1;
}

int print_ancestor(Node_t* sp, char key[MAXLEN]){
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
    int N, M, idx=0, f1, f2;
    char A[MAXLEN], B[MAXLEN];
    scanf("%d %d", &N, &M);
    StrTreeNode_t *p_root = NULL;
    Node_t *A_key, *B_key;

    for(int i=0; i<M; i++){
        char P[MAXLEN], C[MAXLEN];
        Node_t *P_key, *C_key;

        scanf("%s %s", P, C);
        Node_t *P_temp = createNode(P);
        Node_t *C_temp = createNode(C);
        
        P_key = search(P, p_root, (Compare)CmpStr);
        C_key = search(C, p_root, (Compare)CmpStr);

        if(C_key == NULL){
            if(P_key == NULL){
                C_temp->prev = P_temp;
                insert(&P_temp, &p_root, (Compare)CmpStr);
            }
            else{
                C_temp->prev = P_key;
            }
            insert(&C_temp, &p_root, (Compare)CmpStr);
        }
        else{
            if(P_key == NULL){
                C_key->prev = P_temp;
                insert(&P_temp, &p_root, (Compare)CmpStr);
            }
            else{
                C_key->prev = P_key;
            }
        }
    }

    scanf("%s %s", A, B);
    A_key = search(A, p_root, (Compare)CmpStr);
    B_key = search(B, p_root, (Compare)CmpStr);

    f1 = print_ancestor(A_key, B);
    f2 = print_ancestor(B_key, A);

    if((f1 == 0) && (f2 == 0)) printf("TIDAK MUNGKIN\n");

    return 0;
}