#include<stdio.h>
#include<string.h>

int main() {
    int N,M;

    scanf("%d %d", &N, &M);
    int arr[N][M], rot[M][N];

    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int idx;
    for(int i=0; i<M; i++){
        for (int j=0, idx=N-1; j<N; j++, idx--){
            rot[i][j] = arr[idx][i];
            printf("%d", rot[i][j]);
            if(j!=N-1) printf(" ");
        }
        printf("\n");
    }
    
	return 0;
}