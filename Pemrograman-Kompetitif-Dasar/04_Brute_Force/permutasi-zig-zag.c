#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_zig_zag(char *str){
    int N, rule1, rule2;
    N = strlen(str);

    if(N<3) return 1;

    for(int i=1;i<N-1; i++){
        rule1 = (str[i]<str[i-1]) && (str[i]<str[i+1]);
        rule2 = (str[i]>str[i-1]) && (str[i]>str[i+1]);
        if(!(rule1^rule2)) return 0;
    }
    return 1;
}

int compare(const void *a, const void * b){ 
    return (*(char *)a - *(char *)b); 
} 
 
void swap(char* a, char* b){ 
    char t = *a; 
    *a = *b; 
    *b = t; 
} 
 
int findCeil(char *str, char first, int l, int h){ 
    int ceilIndex = l; 
 
    for (int i = l+1; i <= h; i++) 
        if (str[i] > first && str[i] < str[ceilIndex]) 
            ceilIndex = i; 
 
    return ceilIndex; 
} 
 
void sortedPermutations(char *str){ 
    int size = strlen(str); 
 
    qsort(str, size, sizeof(str[0]), compare); 
 
    int isFinished = 0; 
    while (!isFinished){ 
        if(is_zig_zag(str)) printf("%s \n", str); 
  
        int i; 
        for ( i = size-2; i >= 0; --i) 
            if (str[i] < str[i+1]) 
                break; 

        if (i==-1) isFinished =1; 
        else{ 
            int ceilIndex = findCeil(str, str[i], i+1, size-1 ); 
            swap(&str[i], &str[ceilIndex]); 
            qsort(str+i+1, size-i-1, sizeof(str[0]), compare); 
        } 
    } 
} 

int main(void){
    char str[12];
    int len=0, N;

    scanf("%d", &N);

    for(int i=0; i<N; i++) str[i]=i+'1';
    str[N]='\0';

    len = strlen(str);
    sortedPermutations(str);

    return 0;
}
