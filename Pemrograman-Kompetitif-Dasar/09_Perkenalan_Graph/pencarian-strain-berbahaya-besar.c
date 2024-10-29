#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXPATIENT 1000007
#define MAXSTR 15
#define max(a,b) ((a>b) ? a:b)
#define min(a,b) ((a<b) ? a:b)

typedef struct{
    char name[MAXSTR];
}Virus_t;

typedef struct{
    void *next;
    int data;
} Stack_t;

Stack_t *adj_list[MAXPATIENT];
int *stay_list;

Stack_t* createStackNode(int data){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    return new_node;
}

void push(Stack_t** st, int data){
    Stack_t* new_node = createStackNode(data);

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

int isStackEmpty(Stack_t* q){
    if (q == NULL) return 1;
    return 0;
}

int DFS(int pt, int cost){
    int node_cost, result;
    
    node_cost = cost + stay_list[pt];
    result = node_cost;

    if(isStackEmpty(adj_list[pt])) return result;

    while(!isStackEmpty(adj_list[pt])){
        int new_cost, new_adj = pop(&adj_list[pt]);
        
        new_cost = DFS(new_adj, node_cost);
            
        result = max(new_cost, result);
    }

    return result;
}

int main(void){
    int N,S,P, cost=0, parent[15];
    char result[MAXSTR];
    Virus_t virus_list[15];

    scanf("%d %d %d", &N, &S, &P);
    
    stay_list = malloc((N+5)*sizeof(stay_list));
    
    for(int i=0; i<(N+5); i++){
        adj_list[i] = NULL;
    }

    for(int i=1; i<=N; i++){
        scanf("%d", &stay_list[i]);
    }

    for(int i=1; i<=P; i++){
        scanf("%s %d", virus_list[i].name, &parent[i]); 
    }

    for(int i=1; i<=(N-P); i++){
        int x, y;
        scanf("%d %d", &x, &y);
        push(&adj_list[x], y);
    }

    for(int i=1; i<=P; i++){
        int new_cost, node = parent[i];
        new_cost = DFS(node,0);

        if(new_cost>cost){
            strcpy(result, virus_list[i].name);
            cost = new_cost;
        }
    }

    printf("%s\n%d\n", result, cost);

    return 0;
}