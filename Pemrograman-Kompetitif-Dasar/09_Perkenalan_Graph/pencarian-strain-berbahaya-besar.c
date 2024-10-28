#include<stdio.h>
#include<stdlib.h>
#include<string.h>


const int MAXPATIENT = 1000007;
#define MAXSTR 15
#define max(a,b) ((a>b) ? a:b)

typedef struct{
    char name[MAXSTR];
}Virus_t;

typedef struct{
    int *idx;
    size_t count;
    size_t capacity;
} Array_t;

void append(Array_t* arr, int value){
    if((*arr).count >= (*arr).capacity){
        if((*arr).capacity == 0) (*arr).capacity=256;
        else (*arr).capacity = ((*arr).capacity*3)>>1;
        (*arr).idx = realloc((*arr).idx, (*arr).capacity*sizeof(*(*arr).idx));
    }
    (*arr).idx[(*arr).count++] = value;
}

int DFS(int pt, Array_t adj[], int stay[], int cost){
    int len, node_cost, result;
    
    node_cost = cost + stay[pt];
    result = node_cost;

    len = adj[pt].count;

    if(len==0) return result;

    for(int j=0; j<len; j++){
        int new_cost, new_adj = adj[pt].idx[j];
        
        new_cost = DFS(new_adj, adj, stay, node_cost);
            
        result = max(new_cost, result);
    }

    return result;
}

int main(void){
    int N,S,P, cost=0, parent[15], *stay_list;
    char result[MAXSTR];
    Array_t *adj_list;
    Virus_t virus_list[15];

    scanf("%d %d %d", &N, &S, &P);
    
    stay_list = malloc((N+5)*sizeof(stay_list));
    adj_list = malloc((N+5)*sizeof(Array_t));
    
    for(int i=0; i<(N+5); i++){
        adj_list[i].capacity = 128;
        adj_list[i].idx = realloc(adj_list[i].idx, (adj_list[i].capacity)*sizeof(adj_list[i].idx));
        adj_list[i].count=0;
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
        append(&adj_list[x], y);
    }

    for(int i=1; i<=P; i++){
        int new_cost, node = parent[i];
        new_cost = DFS(node, adj_list, stay_list, 0);

        if(new_cost>cost){
            strcpy(result, virus_list[i].name);
            cost = new_cost;
        }
    }

    printf("%s\n%d\n", result, cost);

    return 0;
}