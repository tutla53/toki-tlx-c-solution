#include<stdio.h>
#include<math.h>

unsigned long long int bigmod(unsigned long long int a, unsigned long long int b, unsigned long long int N){
    unsigned long long int result = 1;

    a = a%N;
    while(b>0){
        if (b&1) result = (result * a)%N;
        a = (a*a)%N;
        b = b>>1;
    }

    return result;
}

int main(void){
    unsigned long long int A, B, C, N; 
    scanf("%llu %llu %llu %llu", &A, &B, &C, &N);

    for (unsigned long long int i = 1; i <= C; i++){
        A = bigmod(A,B,N);
        A %= N;
    }

    A++;
    printf("%llu\n", A);
    
    return 0;
}