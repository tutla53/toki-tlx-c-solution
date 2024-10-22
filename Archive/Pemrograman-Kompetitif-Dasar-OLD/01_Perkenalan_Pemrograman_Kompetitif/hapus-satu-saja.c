#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1100

int check_str(char first[MAX_SIZE], char second[MAX_SIZE]){
    int flag = 0, front_len = 0, rear_len = 0, idx = 0;
    int front_idx=0;
    size_t first_len, second_len;
    
    /*Len first > second*/
    first_len = strlen(first);
    second_len = strlen(second);
    idx = second_len-1;

    /*Check Front*/
    for (int i=0; i<second_len; i++){
        if(first[i]==second[i]){
            front_len++;   
        }
        else{
            front_idx = i;
            break;
        }
    }

    /*Check Rear*/
    for (int i=(first_len-1); i>front_idx; i--){
        if(first[i]==second[idx]){
            rear_len++;
        }
        else{
            break;
        }
        idx--;

        if(idx<0) break;
    }

    if((front_len+rear_len) == second_len){
        return 1;
    }

    if(front_len == second_len){
        return 1;
    }

    return 0;
}

int main() {
    char A[MAX_SIZE], B[MAX_SIZE];
    size_t len_A, len_B;
    scanf("%s", A);
    scanf("%s", B);

    len_A = strlen(A);
    len_B = strlen(B);

    if((len_A-len_B) == 1){
        int flag = 0;
        flag = check_str(A,B);

        if(flag){
            printf("Tentu saja bisa!\n");
        }
        else{
            printf("Wah, tidak bisa :(\n");
        }
        
    }
    else{
        printf("Wah, tidak bisa :(\n");
    }

	return 0;
}