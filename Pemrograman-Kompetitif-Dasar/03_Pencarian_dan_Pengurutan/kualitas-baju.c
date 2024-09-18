#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
    int* arr;
    int N, front, rear, sum;

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
        sum = arr[N>>1]+arr[(N>>1)-1];
        front = sum>>1;
        rear = 5*(sum&1);

        printf("%d.%d\n", front, rear);
    }

    return 0;
}