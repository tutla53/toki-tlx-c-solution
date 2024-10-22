#include<stdio.h>

int binary_search(int arr[], int n, int key){
    int lower = 0, upper = n, mid;

    while((mid = (upper+lower)>>1)>lower){
        if(arr[mid]>key) upper = mid;
        else lower = mid;
    }

    if(key>arr[n-1])return n-1;
    return lower;
}

int main(){
    int N, Q;
    scanf("%d", &N);
    int arr[N+1];
    
    arr[0] = 0;

    for (int i=1;i<=N;i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &Q);
    for (int i=0;i<Q;i++){
        int low, hi;
        scanf("%d %d", &low, &hi);
        printf("%d\n", binary_search(arr, N+1, hi) - binary_search(arr, N+1, low));
    }

    return 0;
}