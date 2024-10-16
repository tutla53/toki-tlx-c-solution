#include<stdio.h>
#include<string.h>

int main(void){
    int N, flag=0, arr[100], inv_arr[100];

    for(int i='A'; i<='Z'; i++) arr[i]=-1;
    for(int i='A'; i<='Z'; i++) inv_arr[i]=-1;

    scanf("%d", &N);
    char msg_ori[N+2], msg1[N+2], msg2[N+2], result[N+2];

    scanf("%s %s %s", msg_ori, msg1, msg2);

    for(int i=0;i<N;i++){
        char c = msg1[i], c_ori = msg_ori[i];
        
        if((arr[c]==-1) && (inv_arr[c_ori]==-1)){
            arr[c] = c_ori;
            inv_arr[c_ori] = c;
        }
        else {
            if((arr[c] == c_ori)&&(inv_arr[c_ori]==c)) continue;
            else{
                flag=1;
                break;
            }
        }
    }

    if(flag) printf("Pak Dengklek bingung\n");
    else {
        for(int i=0;i<N;i++){
            char c = msg2[i];
            if(arr[c]==-1) result[i]='?';
            else result[i]= arr[c];
        }  
        result[N]='\0';
        printf("%s\n", result);
    }

    return 0;
}