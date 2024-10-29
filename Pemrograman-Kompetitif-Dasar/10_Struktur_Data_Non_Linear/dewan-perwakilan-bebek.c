#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b) ? a:b)
#define min(a,b) ((a<b) ? a:b)

typedef struct{
    int num;
    int ego;
}Duck_t;

int compare(const void* va, const void * vb){
    const int A = ((Duck_t*) va)->ego;
    const int B = ((Duck_t*) vb)->ego;
    
    return A - B;
}

int DFS(int hold, int P, Duck_t arr[], int lower, int upper){
    int ego, new_cost=0;
    ego = arr[upper].ego - arr[lower].ego;

    if(ego<=P) return (upper - lower + 1);
    if(upper==lower) return 0;
    
    // Skip node if it has been visited
    if(arr[lower+1].num != hold) new_cost = max(new_cost, DFS(hold, P, arr, lower+1, upper));
    if(arr[upper-1].num != hold) new_cost = max(new_cost, DFS(hold, P, arr, lower, upper-1));
    
    return new_cost;
}

int main(void){
    int N, P, Q, *result;
    Duck_t *duck;

    scanf("%d %d %d", &N, &P, &Q);
    duck = malloc((N+2)*sizeof(Duck_t));
    result = malloc((N+2)*sizeof(int));
    
    duck[0].ego = -1;
    duck[0].num = 0;

    for(int i=1; i<=N; i++){
        scanf("%d", &duck[i].ego);
        duck[i].num = i;
    }

    qsort(duck, N+1, sizeof(*duck), compare); 

    for(int i=1; i<=N; i++){
        result[i] = DFS(duck[i].num, P, duck, 1, N);
    }

    for(int i=1; i<=N; i++){
        printf("[%d] %d\n", i, result[i]);
    }

    return 0;
}