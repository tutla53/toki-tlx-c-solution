#include<stdio.h>
#include<stdlib.h>

#define MAX  1000000000
#define min(A,B) (A<B? A:B)

typedef struct{
    int x;
    int y;
} Point_t;

typedef struct Node{
    /*Modified Doubly Linked List*/
    Point_t pt;
    struct Node* next;
    struct Node* prev;
} Node_t;

typedef struct {
    Node_t* head;
    Node_t* tail;
} Queue_t;

Node_t* createNode(Point_t point){
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->pt = point;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

Queue_t* createQueue(){
    Queue_t* new_queue = malloc(sizeof(Queue_t));
    if (new_queue == NULL) return NULL;

    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

void push(Queue_t* q, Point_t point){
    /*Create New Node*/
    Node_t* new_node = createNode(point);
    if(q->tail == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        new_node->prev = q->tail;
        q->tail = new_node;
    }
}

void pop(Queue_t* q) {
    if (q->head == NULL) return;

    Node_t* temp = q->head;
    q->head = q->head->next;
    if (q->head != NULL) q->head->prev = NULL;
    else q->tail = NULL;

    free(temp);
}

Point_t getFront(Queue_t* q){
    Node_t* node = q->head;
    if (node == NULL) return (Point_t) {0,0};
    return node->pt;
}

int isEmpty(Queue_t* q){
    Node_t* node = q->head;
    if (node == NULL) return 1;
    else return 0;
}

void printList(Queue_t* q){
    Node_t* node = q->head;
    while (node != NULL) {
        printf("(%d,%d)->", node->pt.x, node->pt.y);
        node = node->next;
    }
    printf("NULL\n");
}

int main(void){
    int T;
    int move_x[8] = {1, 1,-1,-1, 2,-2,-2, 2};
    int move_y[8] = {2,-2,-2, 2, 1, 1,-1,-1};

    scanf("%d", &T);

    while(T--){
        Queue_t *q = createQueue();
        int N, M, K, S, I, J;
        scanf("%d %d %d %d %d %d", &N, &M, &K, &S, &I, &J);
        int visited_map[N+1][M+1];

        for(int i=0;i<=N; i++) for(int j=0; j<=M; j++) visited_map[i][j] = -1;

        for(int i=0; i<K; i++){
            int x,y;
            scanf("%d %d", &x, &y);
            push(q, (Point_t) {x,y});
            visited_map[x][y] = 0;
        }

        while(!isEmpty(q)){
            Point_t temp;
		    temp = getFront(q);
            pop(q);

            for(int i=0; i<8; i++){
                int x_new = temp.x + move_x[i];
                int y_new = temp.y + move_y[i];		

                if( x_new<1 || x_new>N || y_new<1 || y_new>M||(visited_map[x_new][y_new] != -1)) continue;

                visited_map[x_new][y_new] = visited_map[temp.x][temp.y]+1;
                push(q, (Point_t) {x_new, y_new});
            }
        }

        if(visited_map[I][J]<=S) printf("TRUE\n");
        else printf("FALSE\n");
        free(q);
    }

    return 0;
}