#include<stdio.h>
#include<stdlib.h>

typedef long long lld;

int comp_inc(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

int comp_dec(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(void){
    int *v, *w, N;
    lld ans = 0;

    scanf("%d", &N);

    v = malloc(N*sizeof(int));
    w = malloc(N*sizeof(int));

    for(int i=0; i<N; i++)scanf("%d", &v[i]);
    for(int i=0; i<N; i++)scanf("%d", &w[i]);

    qsort(v, N, sizeof(int), comp_dec);
    qsort(w, N, sizeof(int), comp_inc);

    for(int i=0; i<N; i++) ans += (lld)v[i] * (lld)w[i];

    printf("%lld\n", ans);

    return 0;
}