#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int ull;

typedef struct{
    ull price;
    ull freq;
}List_t;

int compare(const void *va, const void *vb){

    const List_t *prev = va;
    const List_t *next = vb;

    if(prev->price == next->price) return prev->freq - next->freq;

    return (prev->price - next->price);
}

int main(void){
    List_t *list;
    ull N, D, total=0;

    scanf("%llu %llu", &N, &D);

    list = malloc(N*sizeof(List_t));

    for(int i=0; i<N; i++) scanf("%llu %llu", &list[i].price, &list[i].freq);

    qsort(list, N, sizeof(List_t), compare);

    for(int i=0; i<N; i++){
        if(list[i].price * list[i].freq <= D){
            total += list[i].freq;
            D -= (list[i].price) * (list[i].freq);
        }
        else{
            total += D/list[i].price;
            D -= (D/list[i].price) * (list[i].price);
        }
    }

    printf("%llu\n", total);

    return 0;

}