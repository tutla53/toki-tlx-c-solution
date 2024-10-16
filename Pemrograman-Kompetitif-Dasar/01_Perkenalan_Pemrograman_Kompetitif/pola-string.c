#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){
    char input_string[256];
    int str_len, N, idx=0, inc=1;

    scanf("%s", input_string);
    str_len = strlen(input_string);
    N = ceil(sqrt(str_len));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(idx<str_len) printf("%c", input_string[idx]);
            else printf(".");
            idx += inc;
        }
        if(inc==1) idx +=(N-1);
        else idx += N+1;
        inc *=-1;
        printf("\n");
    }

    return 0;
}