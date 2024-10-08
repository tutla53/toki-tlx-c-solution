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
    Queue_t *q = createQueue();
    int N, M, x=0,y=0,lowest_cost=MAX;
    int move_x[4]={1,0,-1,0};
    int move_y[4]={0,1,0,-1};

    scanf("%d %d", &N, &M);

    int map[N][M],cost[N][M];

    for (int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&map[i][j]);
			cost[i][j]=MAX;
		}
	}

    scanf("%d %d", &x, &y);

    cost[x-1][y-1] = 1;
    push(q, (Point_t) {x-1, y-1});

    /*BFS*/
    while(!isEmpty(q)){
        Point_t temp;
		temp = getFront(q);
		pop(q);
		for(int i=0;i<4;i++){
			int x_new = temp.x + move_x[i];
			int y_new = temp.y + move_y[i];			

			if( x_new<0 || x_new>=N || y_new<0 || y_new>=M||(map[x_new][y_new]==-1))continue;			

			int new_cost = cost[temp.x][temp.y]+1;

			if(new_cost<cost[x_new][y_new]){
                cost[x_new][y_new]=new_cost;
                push(q, (Point_t){x_new , y_new});
            }
		}
    }

	for (int i=0;i<N;i++){
		lowest_cost = min(lowest_cost, cost[i][0]);
		lowest_cost = min(lowest_cost, cost[i][M-1]);
	}

	for (int i=0;i<M;i++){
		lowest_cost = min(lowest_cost, cost[0][i]);
		lowest_cost = min(lowest_cost, cost[N-1][i]);
	}

    printf("%d\n",lowest_cost);

    return 0;
}