#include<stdio.h>
#include<stdlib.h>

#define MAX  1000000000
#define min(A,B) (A<B? A:B)

int visited[510][510];
char map[510][510];

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

int BFS(Point_t start, int N, int M, char key_to_avoid){
    Queue_t *q = createQueue();
    int move_x[4]={1,0,-1,0};
    int move_y[4]={0,1,0,-1};
    int cost=1;

    push(q, start);
    visited[start.x][start.y]=1;

    while(!isEmpty(q)){
        Point_t temp;
        temp = getFront(q);
		pop(q);
        
        for(int i=0;i<4;i++){
			int x_new = temp.x + move_x[i];
			int y_new = temp.y + move_y[i];			

			if(x_new<0 || x_new>=N || y_new<0 || y_new>=M||(visited[x_new][y_new]==1)||(map[x_new][y_new]=='#')) continue;
            
            if (map[x_new][y_new]==key_to_avoid) return -1;

            visited[x_new][y_new]=1;
            cost++;			
            push(q, (Point_t){x_new , y_new});
		}
    }
    return cost;
}

int main(void){
    int N, M, k_result, b_result;
    Point_t K, B;

    scanf("%d %d", &N, &M);
    
    for(int i=0; i<M; i++){
        char str[N+1];
        scanf("%s", str);
        for(int j=0; j<N; j++){
            map[i][j] = str[j];
            visited[i][j]=0;

            if(map[i][j]=='K') K = (Point_t) {i,j};
            else if(map[i][j]=='B') B = (Point_t) {i,j}; 
        }
    }
    
    k_result = BFS(K, M, N, 'B');
    if(k_result == -1) {
        printf("SERI\n");
    }
    else{
        b_result = BFS(B, M, N, 'K');
        if(k_result>b_result) printf("K %d\n", k_result - b_result);
        else if (k_result<b_result) printf("B %d\n", k_result - b_result);
        else printf("SERI\n");
    }

    return 0;
}