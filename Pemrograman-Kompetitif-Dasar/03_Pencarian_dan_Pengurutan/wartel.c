#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct phonebook{
    char name[15];
    char num[7];
} Wartel_t;

int compareName(const void* a, const void* b){ 
    const char* idA = ((Wartel_t*)a)->name; 
    const char* idB = ((Wartel_t*)b)->name; 
  
    return strcmp(idA,idB); 
}

int main(){
    int N,Q;

    scanf("%d %d", &N, &Q);
    Wartel_t wartel[N];
    Wartel_t* result;
    
    for(int i=0;i<N;i++){
        scanf("%s %s", wartel[i].name, wartel[i].num);
    }

    while(Q--){
        char new_name[15];
        scanf("%s", new_name);
        result = bsearch(&new_name, wartel, N, sizeof(Wartel_t), compareName);

        if(result != NULL){
            printf("%s\n", result->num);
        }
        else{
            printf("NIHIL\n");
        }
    }
    return 0;
}