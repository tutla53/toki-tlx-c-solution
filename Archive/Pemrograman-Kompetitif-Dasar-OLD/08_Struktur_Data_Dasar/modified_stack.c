#include<stdio.h>
#include<stdlib.h>

typedef struct{
    void *next;
    int data;
    int freq;
} Stack_t;

Stack_t* createNode(int data, int freq){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->data = data;
    new_node->freq = freq;
    return new_node;
}

void push(Stack_t** st, int data, int freq){
    
    /*Create New Head Node*/
    Stack_t* new_node = createNode(data, freq);
    new_node->data = data;

    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) {
        return;
    }

    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

void printList(Stack_t* st){
    while (st != NULL) {
        for(int i=0; i<(st->freq); i++){
            printf("%d->", st->data);
        }
        st = st->next;
    }
    printf("NULL\n");
}

void adx(Stack_t** st, int data){
    Stack_t* temp = *st;
    while (temp != NULL) {
        temp->data += data;
        temp = temp->next;
    }
}


int main(){
    Stack_t* my_stack = NULL;
    int N, data, freq, count=0;
    char cmd[5];
    
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%s", cmd);
        switch(cmd[2]){
            case 'd':
                scanf("%d %d", &data, &freq);
                push(&my_stack, data, freq);
                count += freq;
                printf("%d\n", count);
                break;

            case 'l':
                scanf("%d", &data);
                if (my_stack != NULL){
                    printf("%d\n", my_stack->data);
                    
                    count = ((count-data)<0 ? 0: (count-data));
                    
                    while(data>0){
                        if(my_stack == NULL) break;

                        if (my_stack->freq > data){
                            my_stack->freq -= data;
                            break;
                        }
                        else{
                            data -= my_stack->freq;
                            pop(&my_stack);
                        } 
                    }
                }
                break;
            
            case 'x':
                scanf("%d", &data);
                if (cmd[1] == 'e') data *= -1;
                adx(&my_stack, data);
                break;
        }

        //printList(my_stack);
    }

    

    return 0;
}