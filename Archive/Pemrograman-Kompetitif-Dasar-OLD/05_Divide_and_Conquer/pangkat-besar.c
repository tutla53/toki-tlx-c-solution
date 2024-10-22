#include<stdio.h>
#include<math.h>

#define MOD 1000000

unsigned long long int bigmod(unsigned long long int a,unsigned long long int b, int* over_flag){
    unsigned long long int result = 1;
    
    if(b*log10(a) >= 6) *over_flag=1;

    a = a%MOD;
    while(b>0){
        if (b&1) result = (result * a)%MOD;
        a = (a*a)%MOD;
        b = b>>1;
    }

    return result;
}

int main(void){
    unsigned long long int A, B, result;
    int over_flag = 0;
    scanf("%llu %llu", &A, &B);

    result = bigmod(A,B, &over_flag);

    if(over_flag) printf("%06llu\n", result);
    else printf("%llu\n", result);

    return 0;
}