#include<stdio.h>

int check(int q){
    int divider = 0;
    for(int i=2; i*i<=q;i++){
        if(q%i == 0){
            divider++;
            if(divider>=2) return 0;
        }
    }
    return 1;
}

int main(void){
    int N, P;

    scanf("%d", &N);

    while(N--){
        scanf("%d", &P);
        if(check(P)) printf("YA\n");
        else printf("BUKAN\n");
    }

    return 0;
}