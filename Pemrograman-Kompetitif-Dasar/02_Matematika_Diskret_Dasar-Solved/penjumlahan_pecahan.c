#include<stdio.h>

long long gcd(long long a, long long b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

int main(void){
    long long A=0, B=0, C=0, D=0;
    long long E=0, F=0;
    long long gcd_result=0;

    scanf("%lld %lld", &A, &B);
    scanf("%lld %lld", &C, &D);
    
    E = (A*D)+(B*C);
    F = B*D;
    
    gcd_result=gcd(E,F);
    E /= gcd_result;
    F /= gcd_result;

    printf("%lld %lld\n", E, F);

    return 0;
}