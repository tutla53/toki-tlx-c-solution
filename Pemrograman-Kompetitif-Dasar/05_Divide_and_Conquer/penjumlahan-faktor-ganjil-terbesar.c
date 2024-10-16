#include<stdio.h>
typedef unsigned long long ull;

int main(void){
    ull res=0, N;

    scanf("%llu", &N);

    while(N>0){
        res += ((N+1)/2)*((N+1)/2);
        N = N>>1;
    }

    printf("%llu\n", res);

    return 0;
}