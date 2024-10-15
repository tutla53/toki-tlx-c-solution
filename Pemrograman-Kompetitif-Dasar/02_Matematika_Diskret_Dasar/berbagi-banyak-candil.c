#include<stdio.h>

#define max(A,B) (A>B? A:B)
#define min(A,B) (A<B? A:B)

typedef long long ull;

int main(void){
    ull B, C, D, M, ans=0, iter=0, limit=0;

    scanf("%lld %lld %lld", &B, &C, &D);
    M = C-D;

    if(M==0){
        ans = max(B-C, 0);
    }
    else{
        limit = min(M, B);
        for(ull i=1; i*i<=M; i++){
            if((i<=B) && (C%i==D)) ans++;
            if(((M/i)!=i) && (M/i<=B) && (C%(M/i)==D)) ans++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}