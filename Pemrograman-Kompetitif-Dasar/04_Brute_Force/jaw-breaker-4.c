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

void print_array(int arr[30][30], int N, int M){
    printf("\n");
    for(int k=0; k<N; k++){
        for(int l=0; l<M-1; l++){
            arr[k][l] == 0 ? printf(". ") : printf("%d ", arr[k][l]);
        }
        arr[k][M-1] == 0 ? printf(".\n") : printf("%d\n", arr[k][M-1]);
    }
}

int DFS_cost(Point_t start_point, int map[30][30], int visited[30][30], int N, int M, int color){
    int cost = 0, move_x[4]={1,0,-1,0}, move_y[4]={0,1,0,-1};
    Stack_t *st = NULL;

    push(&st, start_point);
    visited[start_point.x][start_point.y] = 1;
    map[start_point.x][start_point.y] = 0;

    while(st != NULL){
        Point_t temp;
        temp = st->pt;
        cost++;
        pop(&st);

		for(int i=0;i<4;i++){
			int x_new = temp.x + move_x[i];
			int y_new = temp.y + move_y[i];			

			if(x_new<0 || x_new>=N || y_new<0 || y_new>=M||map[x_new][y_new]!=color||visited[x_new][y_new]==1) continue;
            
            push(&st, (Point_t){x_new , y_new});
            visited[x_new][y_new]=1;
            map[x_new][y_new]=0;    
		}
    }

    return cost;
}

void runtuh(int map[30][30], int N, int M){
    int bottom = N-1;

    for(int j=0; j<M; j++){
        for(int i=bottom-1; i>=0; i--){
            if(map[i][j]!=0){
                int idx=i;
                while(map[idx+1][j]==0 && idx<bottom){
                    map[idx+1][j] = map[idx][j];
                    map[idx][j] = 0;
                    idx++;
                }
            }
        }
    }
}

void copy_array(int arr[30][30], int map[30][30], int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = arr[i][j];
        }
    }

}

int find_max(int arr[30][30], int visited[30][30], int N, int M){
    int cost = 0, map[30][30];
    
    copy_array(arr, map, N,M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!=0){
                int new_cost;
                new_cost  = DFS_cost((Point_t) {i, j}, arr, visited, N, M, map[i][j]);
                if(new_cost>cost)cost = new_cost;
            }
        }
    }

    return cost;
}

int two_click(int arr[30][30], int N, int M){
    int result = 0, costA=0, costB=0, map[30][30], new_map[30][30], visited[30][30]={0};

    copy_array(arr, map, N,M);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int color = map[i][j];
            if((visited[i][j]==0)){
                int local_visited[30][30]={0};
                copy_array(arr, map, N,M);
                
                costA = DFS_cost((Point_t){i,j}, map, visited, N, M, color);
                if(costA == 1) continue;
                
                copy_array(map, new_map, N, M);
                runtuh(new_map, N, M);

                costB = find_max(new_map, local_visited, N,M);

                costA *= costA-1;
                costB *= costB-1;

                result = max(result, costA+costB);
            }
        }
    }
    
    return result;
}

int main(void){
    Point_t pt={0,0};

    int N, M, arr[30][30], cost=0, visited[30][30]={0}, test=0;

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    cost = two_click(arr, N, M);
    printf("%d\n", cost);
    
    return 0;
}