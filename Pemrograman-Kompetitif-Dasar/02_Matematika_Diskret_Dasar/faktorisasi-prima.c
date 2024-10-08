#include<stdio.h>

int main(void){
    int N;

    scanf("%d", &N);

    for(int i=2; i*i <=N; i++){
        int count = 0;

        while(N%i==0){
            N /= i;
            count++;
        }
        
        if(count==1) printf("%d",i);
        if(count>1) printf("%d^%d",i, count);
        if((count>0) && (N!=1)) printf(" x ");
    }

    if(N==1) printf("\n");
    else printf("%d\n", N);

    return 0;
}