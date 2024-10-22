#include<stdio.h>
#include<stdlib.h>

#define push_back(arr, x)\
    do{\
        if(arr.count >= arr.capacity){\
            if(arr.capacity == 0) arr.capacity=256;\
            else arr.capacity *=2;\
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

void push(Array2D_t* arr, int i, int value){
    if(i>=(*arr).capacity){
        if((*arr).capacity == 0) (*arr).capacity=256;
        else (*arr).capacity *=2;
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
    Array2D_t arr={0};

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            push(&arr, i, i*j);
        }
    } 

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d ", get_value(arr, i, j));
        }
        printf("\n");
    } 

    return 0;
}