#include<stdio.h>
#include<string.h>

int main(void){
    char cmd[10];
    int idx=0;

    scanf("%s", cmd);
    
    for(int i=2; i<8; i++){
        if(cmd[i]!=cmd[i-1]){
            if(cmd[i]==cmd[i-2]){
                idx = i-1;    
                break;
            }
            else{
                idx = i;
                break;
            }
        }
    }

    printf("%d\n", idx+1);

    return 0;
}