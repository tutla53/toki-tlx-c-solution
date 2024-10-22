#include<stdio.h>
#include<string.h>

#define MAX_SIZE 105

void get_last_string(char source[MAX_SIZE], char target[MAX_SIZE], size_t source_len){
    int flag = 0, idx = 0;
    char temp[MAX_SIZE];

    for (int i=0; i<source_len;i++){
        if(source[i] == '*'){
            flag = 1;
            continue;
        }
        if(flag){
            temp[idx]=source[i];
            idx++;
        }
    }
    temp[idx]='\0';
    strcpy(target,temp);
}

void get_first_string(char source[MAX_SIZE], char target[MAX_SIZE], size_t source_len){
    int idx;
    char temp[MAX_SIZE];
    for (int i=0; i<source_len;i++){
        if(source[i]=='*'){
            idx = i;
            break;
        }
        temp[i]=source[i];
    }
    temp[idx]='\0';
    strcpy(target,temp);
}

int is_same_front(char slice[MAX_SIZE], char guess[MAX_SIZE], size_t slice_len){
    int isIdentical = 1;
    for (int i=0; i<slice_len;i++){
        isIdentical = isIdentical & (slice[i]==guess[i]);
    }
    return isIdentical;
}

int is_same_rear(char slice[MAX_SIZE], char guess[MAX_SIZE], size_t slice_len){
    int isIdentical = 1;
    size_t slice_idx = strlen(slice);
    for (int i=0; i<slice_len;i++){
        isIdentical = isIdentical & (slice[slice_idx-slice_len+i]==guess[i]);
    }
    return isIdentical;
}

int main() {
    char wildcard_word[MAX_SIZE], front_slice[MAX_SIZE], rear_slice[MAX_SIZE];;
    int N;
    size_t len, len_guess, front_len, rear_len;
    
    scanf("%s", wildcard_word);
    len = strlen(wildcard_word);
    get_first_string(wildcard_word, front_slice, len);
    get_last_string(wildcard_word, rear_slice, len);
    front_len   = strlen(front_slice);
    rear_len    = strlen(rear_slice);

    scanf("%d", &N);
    while (N--){
        char guess_word[MAX_SIZE];

        scanf("%s", guess_word);
        len_guess = strlen(guess_word);

        if(len_guess<len-1){
            continue;
        }
        
        if(len == 1){
            printf("%s\n", guess_word);
        }
        else{
            if(front_len>0 && rear_len==0){
                int flag;
                flag = is_same_front(guess_word, front_slice, front_len);
                if(flag){
                    printf("%s\n", guess_word);
                }
            }
            else if(front_len>0 && rear_len>0){
                int front_flag, rear_flag;
                front_flag = is_same_front(guess_word, front_slice, front_len);
                rear_flag = is_same_rear(guess_word, rear_slice, rear_len);
                if(front_flag && rear_flag){
                    printf("%s\n", guess_word);
                }
            }
            else if(front_len==0 && rear_len>0){
                int flag;
                flag = is_same_rear(guess_word, rear_slice, rear_len);
                if(flag){
                    printf("%s\n", guess_word);
                }
            }
        }
    }
	return 0;
}