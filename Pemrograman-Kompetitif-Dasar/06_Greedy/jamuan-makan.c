#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int start;
    int end;
}List_t;

int compare(const void *va, const void *vb){

    const List_t *prev = va;
    const List_t *next = vb;

    if(prev->end == next->end) return prev->start - next->start;

    return (prev->end - next->end);
}

int main(void){
    List_t *guess;
    int N, ans, next_available;

    scanf("%d", &N);
    guess = malloc(N*sizeof(List_t));
    
    for(int i=0; i<N; i++){
        scanf("%d %d", &guess[i].start, &guess[i].end);
        guess[i].end += guess[i].start-1;
    }

    qsort(guess, N, sizeof(List_t), compare);

    next_available = guess[0].start;
    ans = 1;

    for(int i=1; i<N; i++) {
        if(guess[i].start > next_available){
            next_available = guess[i].end;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;

}