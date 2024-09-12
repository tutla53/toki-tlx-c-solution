#include<stdio.h>
#include<stdlib.h>

int main(){
    int N, M, K, x = 0, y = 0, flag = 0;
    scanf("%d %d %d", &N, &M, &K);
    
    int arr[N+2][M+2];

    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=M+1; j++){
            if((i==0)||(j==0)||(i==N+1)||(j==M+1)){
                arr[i][j] = 1;
            }
            else{
                scanf("%d", &arr[i][j]);
            }
        }
    }
 
    for(int j=1; j<=M; j++){
        if(flag) break;
        for(int i=1; i<=N; i++){
            int key = 1;
            key = arr[i+1][j]*arr[i-1][j]*arr[i][j+1]*arr[i][j-1];

            if(key == K){
                flag = 1;
                x = i;
                y = j;
                break;
            }
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}