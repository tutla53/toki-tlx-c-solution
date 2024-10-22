#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
    int* arr;
    int N, K;

    scanf("%d %d", &N, &K);
    arr = malloc(N*sizeof(arr));

    for (int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    qsort (arr, N, sizeof(*arr), compare);
    printf("%d\n",arr[K-1]);

    return 0;
}