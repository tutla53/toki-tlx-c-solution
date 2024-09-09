#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct result{
    char ID[5];
    int s1;
    int s2;
    int s3;
} result_t;

int compare(const void* va, const void * vb){
    /*  Increasing Order
        0 --> Equal
        1 --> va > vb
        -1 --> va < vb

        Decreasing Order
        0 --> Equal
        1 --> va < vb
        -1 --> va > vb
    */

    const result_t *a = va;
    const result_t *b = vb;

    int result;
    if(a->s3 != b->s3){
        return (b->s3 - a->s3);
    }
    else{
        if(a->s2 != b->s2){
            return (b->s2 - a->s2);
        }
        else{
            return (b->s1 - a->s1);
        }
    }
}

int main(){
    int T, N=1, M, found = 0;
    char ID[5];
    scanf("%d", &T);
    result_t* arr;
    arr = malloc(N * sizeof(result_t));
    
    while(T--){
        scanf("%d %d", &N, &M);
        scanf("%s", ID);
        arr = realloc(arr, N * sizeof(result_t));

        if(arr!=NULL){
            for(int i = 0; i<N; i++){
                scanf("%s %d %d %d", arr[i].ID, &arr[i].s1, &arr[i].s2, &arr[i].s3);
            }
            
            qsort (arr, N, sizeof *arr, compare);
            for (int j = 0; j < M; j++){
                if (strcmp(arr[j].ID, ID)==0){
                    found = 1;
                    break;
                }
                else{
                    found = 0;
                }
            }

            if(found == 1) printf("YA\n");
            else printf("TIDAK\n");
        }
    }
    return 0;
}