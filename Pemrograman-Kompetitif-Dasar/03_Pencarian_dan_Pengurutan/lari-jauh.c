#include<stdio.h>
#include<stdlib.h>

int search(int key, int arr[], int lenA){
    int left=0, right=lenA-1, mid;
    
    while(left<=right){
        mid = (right+left)>>1;
        if(arr[mid]>key) right = mid-1;
        else left = mid+1;
    }

    return left;
}

int main(void){
    int N,K, *arr, *duck;
    scanf("%d %d", &N, &K);
    
    arr = malloc(N * sizeof(int));
    duck = malloc(K * sizeof(int));
    
    scanf("%d", &arr[0]);
    for(int i=1; i<N; i++){
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }

    for(int i=0; i<K; i++){
        scanf("%d", &duck[i]);
    }

    for(int i=0; i<K; i++) printf("%d\n", search(duck[i], arr, N));

    return 0;
}