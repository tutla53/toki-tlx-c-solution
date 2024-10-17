#include<stdio.h>

#define MAX 110

typedef struct{
    int arr[MAX][MAX];
    int row;
    int col;
}Matrix_t;

void print_arr(Matrix_t mtrx){
    for(int i=0; i<mtrx.row; i++){
        for(int j=0; j<mtrx.col-1; j++)printf("%d ", mtrx.arr[i][j]);
        printf("%d\n", mtrx.arr[i][mtrx.col-1]);
    }
}

Matrix_t vertical(Matrix_t mtrx){
    Matrix_t new = mtrx;

    for(int i=0; i<mtrx.row; i++){
        for(int j=0, k=mtrx.col-1; j<mtrx.col; j++, k--){
            new.arr[i][k] = mtrx.arr[i][j];
        }
    }
    return new;
}

Matrix_t horizontal(Matrix_t mtrx){
    Matrix_t new = mtrx;

    for(int i=0, k=mtrx.row-1; i<mtrx.row; i++, k--){
        for(int j=0; j<mtrx.col; j++){
            new.arr[i][j] = mtrx.arr[k][j];
        }
    }
    return new;
}

Matrix_t rotate_90(Matrix_t mtrx){
    Matrix_t new = mtrx;
    
    new.col = mtrx.row;
    new.row = mtrx.col;

    for(int i=0, k=mtrx.row-1; i<mtrx.row; i++, k--){
        for(int j=0; j<mtrx.col; j++){
            new.arr[j][k] = mtrx.arr[i][j];
        }
    }
    return new;
}

Matrix_t rotate_270(Matrix_t mtrx){
    Matrix_t new = mtrx;
    
    new.col = mtrx.row;
    new.row = mtrx.col;

    for(int i=0; i<mtrx.row; i++){
        for(int j=0, k=mtrx.col-1; j<mtrx.col; j++,k--){
            new.arr[k][i] = mtrx.arr[i][j];
        }
    }
    return new;
}

Matrix_t rotate_180(Matrix_t mtrx){
    Matrix_t new = mtrx;
    
    for(int i=0, k=mtrx.row-1; i<mtrx.row; i++, k--){
        for(int j=0, l=mtrx.col-1; j<mtrx.col; j++, l--){
            new.arr[k][l] = mtrx.arr[i][j];
        }
    }
    return new;
}

int main(void){
    int N, M, X;
    char cmd[5];
    Matrix_t mtrx;

    scanf("%d %d %d", &N, &M, &X);
    
    mtrx.row = N;
    mtrx.col = M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &mtrx.arr[i][j]);
        }
    }
    
    while(X--){
        scanf("%s", cmd);

        switch(cmd[0]){
            case '_':
                mtrx = horizontal(mtrx);
                break;
            case '|':
                mtrx = vertical(mtrx);
                break;
            case '9':
                mtrx = rotate_90(mtrx);
                break;
            case '1':
                mtrx = rotate_180(mtrx);
                break;
            default:
                mtrx = rotate_270(mtrx);
                break;
        }
    }
    print_arr(mtrx);
    
    return 0;
}