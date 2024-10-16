#include<stdio.h>
#include<string.h>

void print_value(int arr[9], int left, int right){
    int mid = (right+left)>>1;
    
    printf("?\n");
    for(int i=left; i<mid; i++){
        printf("%d ", arr[i]);
        fflush(stdout);
    }
    printf("%d\n", arr[mid]);
    fflush(stdout);

    for(int i=mid+1; i<right; i++){
        printf("%d ", arr[i]);
        fflush(stdout);
    }
    printf("%d\n", arr[right]);
    fflush(stdout);
}

int main(void){
    int arr[9] = {0,1,2,3,4,5,6,7,8}, left = 1, right = 8, N=8;
    char cmd[10];

    while(left<right){
        print_value(arr, left, right);
    
        scanf("%s", cmd);

        if(strcmp(cmd,"KIRI")==0){
            right = (right+left)>>1;
        }
        else if(strcmp(cmd,"KANAN")==0){
            left =  ((right+left)>>1)+1;
        }
    }

    printf("! %d\n", left);
    fflush(stdout);

    return 0;
}