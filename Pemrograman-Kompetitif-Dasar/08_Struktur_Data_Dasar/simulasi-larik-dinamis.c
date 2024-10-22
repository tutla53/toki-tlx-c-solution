#include<stdio.h>
#include<stdlib.h>

#define push_back(arr, x)\
    do{\
        if(arr.count >= arr.capacity){\
            if(arr.capacity == 0) arr.capacity=256;\
            else arr.capacity = (arr.capacity*3) >> 1;\
            arr.items = realloc(arr.items, arr.capacity*sizeof(*arr.items));\
        }\
        arr.items[arr.count++] = x;\
    }while(0)

typedef struct{
    int *items;
    size_t count;
    size_t capacity;
} Array_t;

int main(void){
    Array_t arr[1010]={0};
    int Q;
    char cmd[5];

    scanf("%d", &Q);
    
    while(Q--){
        int L, X, Y, Z;
        scanf("%s", cmd);
        switch(cmd[0]){
            case 'a':
                scanf("%d %d %d", &L, &X, &Y);
                for(int i=0; i<Y; i++) push_back(arr[L], X);
                break;
            case 'o':
                scanf("%d %d", &L, &Z);
                printf("%d\n", arr[L].items[Z-1]);
            default:
                continue;
        }
    }

    return 0;
}