#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define push_back(arr, x)\
    do{\
        if(arr.count >= arr.capacity){\
            if(arr.capacity == 0) arr.capacity=256;\
            else arr.capacity = arr.capacity<<1;\
            arr.items = realloc(arr.items, arr.capacity*sizeof(*arr.items));\
        }\
        arr.items[arr.count++] = x;\
    }while(0)

typedef struct{
    int *items;
    size_t count;
    size_t capacity;
} Array_t;

typedef struct{
    Array_t *items;
    size_t capacity;
} Array2D_t;


typedef struct{
    void *next;
    int value;
} Stack_t;

Stack_t* createNode(int value){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->value = value;
    return new_node;
}

void push(Stack_t** st, int value){
    Stack_t* new_node = createNode(value);

    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) return;

    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

void init_array_2D(Array2D_t* arr, size_t size){
    (*arr).capacity = size;
    (*arr).items = malloc(size*sizeof(*(*arr).items));
}

void append(Array2D_t* arr, int i, int value){
    if(i>=(*arr).capacity){
        if((*arr).capacity == 0) (*arr).capacity=256;
        else (*arr).capacity = (*arr).capacity<<1;
        (*arr).items = realloc((*arr).items, (*arr).capacity*sizeof(*(*arr).items));
    }
    push_back((*arr).items[i], value);
}

int get_value(Array2D_t arr, int i, int j){
    if(i>= arr.capacity) return -1;
    if(j>= arr.items[i].capacity) return -1;

    return arr.items[i].items[j];
}

int main(void){
    Array2D_t arr;
    Stack_t *st = NULL;
    int N, M, *visited, count=0;

    scanf("%d %d", &N, &M);
    
    init_array_2D(&arr, N+1);

    visited = malloc((N+1)*sizeof(visited));
    memset(visited, 0, N+1);

    for(int i=0; i<M; i++){
        int U, V;
        scanf("%d %d", &U, &V);
        append(&arr, U, V);
        append(&arr, V, U);
    }
    
    for(int i=1; i<=N; i++){

        if(!visited[i]){
            push(&st, i);

            while(st!=NULL){
                int node, len;

                node = st->value;
                len = arr.items[node].count;
                visited[node]=1;

                pop(&st);

                for(int j=0; j<len; j++){
                    int adj = get_value(arr, node, j);
                    if(visited[adj]) continue;
                    push(&st, adj);
                    visited[adj]=1;
                }
            }
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}