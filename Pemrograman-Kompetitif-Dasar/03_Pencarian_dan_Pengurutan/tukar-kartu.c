#include<stdio.h>
#include<stdlib.h>

void swap(short int* xp, short int* yp){
    short int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(void){
    short int N, *arr;
    int swap_value = 0;

    scanf("%hd", &N);
    arr = malloc(N*sizeof(short int));

    for(int i=0; i<N; i++) scanf("%hd", &arr[i]);

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]); 
                swap_value++;
            }
        }
    }

    printf("%d\n", swap_value);

    return 0;
}