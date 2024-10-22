#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double cpw;
    int weight;
    int cost;
} Price_t;

int compare(const void* va, const void* vb) {

    const Price_t *a = va;
    const Price_t *b = vb;

    if (a->cpw < b->cpw) return 1;
    if (a->cpw > b->cpw) return -1;
    return 0;
}

int main(){
    Price_t* price;
    int N, X;
    double result = 0.0;

    scanf("%d %d", &N, &X);
    price = malloc(N* sizeof(Price_t));

    for(int i=0; i<N; i++){
        scanf("%d", &price[i].weight);
    }

    for(int i=0; i<N; i++){
        scanf("%d", &price[i].cost);
        price[i].cpw = price[i].cost/((double) price[i].weight);
    }

    qsort(price, N, sizeof(Price_t), compare);

    for(int i=0; i<N; i++){
        if(X==0) break;
        int weight_val = (price[i].weight>X ? X: price[i].weight);
        result += price[i].cpw * weight_val;
        X -= weight_val;
    }
    
    printf("%.5lf\n", result);

    return 0;
}