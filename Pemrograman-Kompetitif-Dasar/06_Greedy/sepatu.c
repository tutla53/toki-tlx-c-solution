#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(void){
    int N,M, *bebek, *dengklek, ans=0, found=0, idx=0, last_found_idx=-1;

    scanf("%d %d", &N, &M);

    bebek = malloc(N*sizeof(int));
    dengklek = malloc(M*sizeof(int));

    for(int i=0; i<N; i++)scanf("%d", &bebek[i]);
    for(int i=0; i<M; i++)scanf("%d", &dengklek[i]);

    qsort(bebek, N, sizeof(int), compare);
    qsort(dengklek, M, sizeof(int), compare);

    for(int i=0; i<N; i++){
        found = 0;
        idx = last_found_idx+1;

        while(!found && (idx<M)){
            if((bebek[i] == dengklek[idx]) || (bebek[i]+1 == dengklek[idx])){
                ans++;
                found=1;
                last_found_idx = idx;
            }
            idx++;
        }
        if(last_found_idx == M) break;
    }

    printf("%d\n", ans);

    return 0;
}