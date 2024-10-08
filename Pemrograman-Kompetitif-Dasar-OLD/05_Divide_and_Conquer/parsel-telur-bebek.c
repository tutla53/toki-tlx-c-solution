#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int ull;

int N, M;
ull *A;

ull package_number(ull X){
    ull value = 0;
    
    for(int i = 0; i<N; i++) value += X/A[i];

    return value;
}

ull find_value(ull m){
    ull left = 1, right = (1LL<<60)/N, value = 0;

    while(left <= right){
        ull mid = (left + right)/2;

        if(package_number(mid) >= m){
            right = mid-1;
            value = mid;
        }
        else left = mid+1;
    }
    return value;
}


int main(void){
    
    scanf("%d %d", &N, &M);
    A = malloc(N*sizeof(ull));

    for(int i=0; i<N; i++) scanf("%llu", &A[i]);
    printf("%llu\n", find_value(M+1)-find_value(M));

    return 0;
}