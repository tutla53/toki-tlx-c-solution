#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
    int* arr;
    int N;

    scanf("%d", &N);
    arr = malloc(N * sizeof(int));

    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    if(N&1){
        printf("%d.0\n",arr[N>>1]);
    }
    else{
        printf("%d.%d\n", (arr[N>>1]+arr[(N>>1)-1])>>1, 5*((arr[N>>1]+arr[(N>>1)-1])&1));
    }

    return 0;
}