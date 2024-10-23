#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b) ? a:b)

typedef struct{
    int *idx;
    size_t count;
    size_t capacity;
} Array_t;

typedef struct{
    Array_t *idx;
    size_t row;
    size_t capacity;
} Matrix_t;

void append(Array_t* arr, int value){
    if((*arr).count >= (*arr).capacity){
        if((*arr).capacity == 0) (*arr).capacity=256;
        else (*arr).capacity = ((*arr).capacity*3)>>1;
        (*arr).idx = realloc((*arr).idx, (*arr).capacity*sizeof(*(*arr).idx));
    }
    (*arr).idx[(*arr).count++] = value;
}

void appendMatrix(Matrix_t* mtrx, int row, int value){

    if(row>=(*mtrx).capacity){
        if((*mtrx).capacity == 0) (*mtrx).capacity=256;
        else (*mtrx).capacity = row+((*mtrx).capacity*3)>>1;
        (*mtrx).idx = realloc((*mtrx).idx, (*mtrx).capacity*sizeof(*(*mtrx).idx));
    }

    (*mtrx).row = max((*mtrx).row, row+1);
    append(&((*mtrx).idx[row]), value);
}

int getMatrixValue(Matrix_t mtrx, int i, int j){
    if(i>= mtrx.capacity) return -1;
    if(j>= mtrx.idx[i].capacity) return -1;

    return mtrx.idx[i].idx[j];
}

int main(void){
    Matrix_t mtrx={0};

    appendMatrix(&mtrx, 20, 11);
    appendMatrix(&mtrx, 20, 12);

    appendMatrix(&mtrx, 0, 1);
    appendMatrix(&mtrx, 0, 2);
    appendMatrix(&mtrx, 0, 3);

    appendMatrix(&mtrx, 1, 4);
    appendMatrix(&mtrx, 1, 5);

    appendMatrix(&mtrx, 10, 6);
    appendMatrix(&mtrx, 10, 7);
    appendMatrix(&mtrx, 10, 8);
    appendMatrix(&mtrx, 10, 9);
    appendMatrix(&mtrx, 10, 10);


    for(int i=0; i<mtrx.row; i++){
        int len = mtrx.idx[i].count;
        
        if(len==0) continue;

        printf("[%d] ", i);
        for(int j=0; j<len; j++) printf("%d ", getMatrixValue(mtrx, i, j));
        printf("\n");
    }

    printf("Matrix Capacity: %ld\n", mtrx.capacity);
    printf("Matrix Row: %ld\n", mtrx.row);

    return 0;
}