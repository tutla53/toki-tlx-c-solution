#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_char 15

typedef struct book{
    char name[max_char];
} Book_t;

int compare(const void* va, const void * vb){

    const char* nameA   = ((Book_t*) va)->name; 
    const char* nameB   = ((Book_t*) vb)->name; 
    const int lenA      = strlen(nameA);
    const int lenB      = strlen(nameB);
    
    if (lenA == lenB){
         return strcmp(nameA,nameB); 
    }
    
    return lenA - lenB;
}


int main(){
    Book_t* buku_tamu;
    int N;

    scanf("%d", &N);
    buku_tamu = malloc(N* sizeof(Book_t));

    for(int i=0; i<N; i++){
        scanf("%s", buku_tamu[i].name);
    }

    qsort (buku_tamu, N, sizeof(*buku_tamu), compare);

    for(int i=0; i<N; i++){
        printf("%s\n", buku_tamu[i].name);
    }

    return 0;
}