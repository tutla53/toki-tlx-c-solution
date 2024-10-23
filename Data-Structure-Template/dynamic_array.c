#include<stdio.h>
#include<stdlib.h>

typedef int Type_T;

typedef struct{
    Type_T *idx;
    size_t count;
    size_t capacity;
} Array_t;

void append(Array_t* arr, Type_T value){
    if((*arr).count >= (*arr).capacity){
        if((*arr).capacity == 0) (*arr).capacity=256;
        else (*arr).capacity = ((*arr).capacity*3)>>1;
        (*arr).idx = realloc((*arr).idx, (*arr).capacity*sizeof(*(*arr).idx));
    }
    (*arr).idx[(*arr).count++] = value;
}

int main(void){
    Array_t arr={0};

    for(int i=0; i<300; i++) append(&arr, i);

    for(int i=0; i<arr.count; i++){
        printf("%d\n", arr.idx[i]);
    } 

    return 0;
}