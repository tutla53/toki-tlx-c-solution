#include<stdio.h>
#include<string.h>

#define MAX_VAL 1001010

int main(void){
    unsigned long long arr[MAX_VAL];
    int T, N;
    
    for(int i=0;i<3; i++) arr[i]=0;

    for(int i=4; i<MAX_VAL; i++){
        arr[i] = arr[i-1];
        if (((i%4) == 0) || ((i%7) == 0)){
            arr[i] += i;
        } 
    }

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%llu\n", arr[N]);
    }

    return 0;
}