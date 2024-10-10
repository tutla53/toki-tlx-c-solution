#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N, ans, x,y;
    scanf("%d", &N);
    ans = (N*(N-1)*(N-2))/6;

    while(N--) scanf("%d %d", &x, &y);
     
    printf("%d\n", ans);

    return 0;
}