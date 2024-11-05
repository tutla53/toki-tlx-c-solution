#include<stdio.h>

int main(void){
    signed char lower, upper, mid;
    scanf("%hhd %hhd", &lower, &upper);
    getchar();
        
    while(1){
        signed char i=0;
        char cmd[15];

        mid = (upper+lower)/2;
        printf("%hhd\n", mid);
        fflush(stdout);

        while (1) {
            cmd[i] = getchar();
            if (cmd[i] == '\n') break;
            i++;
        }
        cmd[i] = '\0';

        if(cmd[0] == 's') break;

        if(i>7 && cmd[8] == 'k') lower = mid+1;
        else upper = mid-1;
    }

    return 0;
}