#include<stdio.h>
#include<stdlib.h>

void brute_force(int arr[], int depth, int N, int K){
    
    if(depth>K){
        for(int i=1; i<K; i++){
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[K]);
    }
    else{
        for(int i=arr[depth-1]+1; i<=N; i++){
            arr[depth] = i;
            brute_force(arr, depth+1, N, K);
        }
    }

}

int main(void){
    int N, K, *arr;

    scanf("%d %d", &N, &K);

    arr = malloc((N+1)*sizeof(arr));

    brute_force(arr, 1, N, K);

    free(arr);
    
    return 0;
}