#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

int main(void){
    int N, B, *H, ans=0, height=0;

    scanf("%d %d", &N, &B);
    H = malloc(N*sizeof(int));

    for(int i=0; i<N; i++)scanf("%d", &H[i]);

    qsort(H, N, sizeof(int), compare);
    
    for(int i=0; i<N, height<=B; i++, ans++) height += H[i];

    printf("%d\n", ans);

    return 0;
}