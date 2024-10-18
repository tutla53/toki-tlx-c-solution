#include<stdio.h>
#include<stdlib.h>

#define MAX_VAL  1000000000
#define min(A,B) (A<B? A:B)
#define max(A,B) (A>B? A:B)

typedef struct{
    int x;
    int y;
} Point_t;

typedef struct{
    void *next;
    Point_t pt;
} Stack_t;

Stack_t* createNode(Point_t pt){
    Stack_t* new_node = malloc(sizeof(Stack_t));
    new_node->pt.x = pt.x;
    new_node->pt.y = pt.y;
    return new_node;
}

void push(Stack_t** st, Point_t pt){
    Stack_t* new_node = createNode(pt);

    new_node->next = (*st);
    *st = new_node;   
}

void pop(Stack_t** st) {
    if ((*st) == NULL) return;

    Stack_t* temp = *st;
    *st = (*st)->next;
    free(temp);
}

int DFS_cost(Point_t start_point, int map[30][30], int N, int M, int color){
    int cost = 0, move_x[4]={1,0,-1,0}, move_y[4]={0,1,0,-1};
    Stack_t *st = NULL;

    push(&st, start_point);
    map[start_point.x][start_point.y] = 0;

    while(st != NULL){
        Point_t temp;
        temp = st->pt;
        cost++;
        pop(&st);

		for(int i=0;i<4;i++){
			int x_new = temp.x + move_x[i];
			int y_new = temp.y + move_y[i];			

			if(x_new<0 || x_new>=N || y_new<0 || y_new>=M||map[x_new][y_new]!=color) continue;
            
            push(&st, (Point_t){x_new , y_new});
            map[x_new][y_new]=0;    
		}
    }

    return cost;
}

int main(void){
    Point_t pt;

    int N, M, arr[30][30], cost=0, color=0;

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]!=0){
                int new_cost;
                new_cost  = DFS_cost((Point_t) {i, j}, arr, N, M, arr[i][j]);
                cost = max(new_cost, cost);
            }
        }
    }

    printf("%d\n", cost*(cost-1));

    return 0;
}