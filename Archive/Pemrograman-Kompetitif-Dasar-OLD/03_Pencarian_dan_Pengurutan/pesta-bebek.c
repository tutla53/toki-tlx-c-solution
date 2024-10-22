#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CHAR 15

typedef struct{
    char name[MAX_CHAR];
} Guest_t;

void swap_string(char* a, char* b){
    char* temp = malloc((strlen(a) + 1) * sizeof(char)); ;
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    free(temp);
}


int main(){
    int N;
    Guest_t* guest;

    scanf("%d", &N);
    guest = malloc(N*sizeof(Guest_t));

    for(int i=0; i<N; i++){
        scanf("%s", guest[i].name);
        int idx = i;
            
        while((strcmp(guest[idx-1].name, guest[idx].name)>0) && (idx>0)){
            swap_string(guest[idx-1].name, guest[idx].name);
            idx--;
        }
        printf("%d\n", idx+1);
    }

    return 0;
}