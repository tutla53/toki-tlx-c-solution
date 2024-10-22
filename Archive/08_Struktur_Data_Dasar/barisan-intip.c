#include<stdio.h>
#include<stdlib.h>

typedef struct{
    void *next;
    int data;
} Stack_t;

void push(Stack_t** st, int data){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) return;

    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

int main(){
    unsigned long long sum = 0;
    int N, ans=0, *height;
    Stack_t* blocker = NULL;

    scanf("%d", &N);
    height = malloc(N* sizeof(int));

    for(int i=0; i<N; i++){
        scanf("%d", &height[i]);
    }

    for(int i=0; i<N; i++){
        while((blocker!=NULL) && (height[i]>=height[blocker->data])){
            pop(&blocker);
        }

        if(blocker==NULL) ans = i + 1;
        else ans = i - blocker->data;
        
        push(&blocker, i);
        sum += ans;
    }

    printf("%llu\n", sum);

    return 0;
}