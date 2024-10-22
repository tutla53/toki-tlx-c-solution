#include<stdio.h>
#include<math.h>

#define MAX_VAL 1001010

int power_by(int m){
    int N = 1;
    for(int i=0;i<m;i++){
        N *=3;  
    }
    return N;
}

int main(void){
    int N, arr[20], idx = 0, len=0;
    scanf("%d", &N);
    
    for(idx=0, len=0; N>0; idx++, N/=3){
        if(N%3 == 1){
            arr[len] = power_by(idx);
            len++;
        }
    }

    printf("%d\n", len);

    for(int i=0; i<len-1; i++){
        printf("%d ", arr[i]);
    }

    printf("%d\n", arr[len-1]);

    return 0;
}