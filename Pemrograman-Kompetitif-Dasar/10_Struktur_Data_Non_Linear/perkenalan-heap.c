#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

typedef struct {
    int items[MAX];
    int size;
} PriorityQueue_t;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue_t* pq, int index){
    if (index
        && pq->items[(index - 1) / 2] < pq->items[index]) {
        swap(&pq->items[(index - 1) / 2],
             &pq->items[index]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void enqueue_priority(PriorityQueue_t* pq, int value){
    if (pq->size == MAX) return;

    pq->items[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

int heapifyDown(PriorityQueue_t* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size
        && pq->items[left] > pq->items[smallest])
        smallest = left;

    if (right < pq->size
        && pq->items[right] > pq->items[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&pq->items[index], &pq->items[smallest]);
        heapifyDown(pq, smallest);
    }
}

int dequeue_priority(PriorityQueue_t* pq){
    if (!pq->size) return -1;

    int item = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    heapifyDown(pq, 0);
    return item;
}

int peek(PriorityQueue_t* pq){
    if (!pq->size) return -1;
    return pq->items[0];
}

int main(void){
    PriorityQueue_t pq = { { 0 }, 0 };

    int Q;
    scanf("%d", &Q);
    while(Q--){
        int cmd;
        scanf("%d", &cmd);
        switch (cmd){
        case 1:
            int x;
            scanf("%d", &x);
            enqueue_priority(&pq, x);
            break;
        case 2:
            printf("%d\n", peek(&pq));
            break;
        default:
            dequeue_priority(&pq);
            break;
        }
    }

    return 0;
}
