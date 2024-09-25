#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    int* arr;
    unsigned long long sum = 0;

    scanf("%d", &N);

    arr = malloc(N * sizeof(int));

    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<N; i++){
        sum += (arr[i-1] > arr[i] ? arr[i-1] : arr[i]);
    }
    
    printf("%llu\n", sum);

    return 0;
}