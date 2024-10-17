#include<stdio.h>

typedef unsigned long long int ull;
#define MOD 1000000007
#define NMAX 1010

ull f[NMAX];

ull inv(ull a){
    ull result = 1, b = MOD-2;

    a %= MOD;
    while(b>0){
        if (b&1) result = (result * a)%MOD;
        a = (a*a)%MOD;
        b = b>>1;
    }

    return result;
}

ull multipy_modular(ull A, ull B){
    ull res;
    res = ((A%MOD)*(B%MOD))%MOD;

    return res;
}

ull addition_modular(ull A, ull B){
    ull res;
    res = ((A%MOD)+(B%MOD))%MOD;

    return res;
}

ull combinatoric_modular(ull n, ull r){
    // n!⋅inv(k!)⋅inv((n−k)!)(modp);
    ull result = multipy_modular(multipy_modular(f[n], inv(f[r])), inv(f[n-r])) % MOD;
    
    return result;
}

int main(void){
    f[0]=1;
    f[1]=1;

    ull A, B, N, result=0;

    for(ull i=2; i<NMAX; i++) f[i] = multipy_modular(f[i-1], i) % MOD;
    
    scanf("%llu %llu %llu", &N, &A, &B);

    for(ull i=A; i<=B; i++) result = addition_modular(result, combinatoric_modular(N,i))%MOD;

    printf("%llu\n", result);

    return 0;
}
