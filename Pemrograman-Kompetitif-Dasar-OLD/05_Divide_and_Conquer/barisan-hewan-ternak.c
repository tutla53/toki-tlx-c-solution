#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[], int n, int key){
    int lower = 0, upper = n-1, mid;

    while(lower<=upper){
        mid = (upper+lower)>>1;
        if(arr[mid]>=key) upper = mid-1;
        else lower = mid+1;
    }

    return lower;
}

int main(void){
    int N, Q, *arr, data, res;

    scanf("%d", &N);
    arr = malloc(N * sizeof(int));

    scanf("%d", &arr[0]);
    for(int i=1; i<N; i++) {
        scanf("%d", &data);
        arr[i] = arr[i-1]+data;
    }

    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        scanf("%d", &data);
        res = binary_search(arr, N, data);
        printf("%d\n", res+1);
    }

    return 0;
}