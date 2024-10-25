#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 10
#define max(a,b) ((a>b) ? a:b)

typedef int (*Compare)(const char *, const char *);

typedef struct node{
    char value[MAXLEN];           
    struct node *p_left;
    struct node *p_right;
}StrTreeNode_t;

typedef struct{
    char str[MAXLEN];
    int cost;
} Data_t;

typedef struct Node {
    Data_t data;
    struct Node* next;
    struct Node* prev;
} QueueNode_t;

typedef struct queue{
    QueueNode_t* head;
    QueueNode_t* tail;
} Queue_t;

QueueNode_t* createQueueNode(char data[MAXLEN], int cost){
    QueueNode_t* new_node = malloc(sizeof(QueueNode_t));
    strcpy(new_node->data.str, data);
    new_node->data.cost = cost;
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

void enqueue(Queue_t** q, Data_t data){
    QueueNode_t* new_node = createQueueNode(data.str, data.cost);
    
    if((*q)->tail == NULL){
        (*q)->head = new_node;
        (*q)->tail = new_node;
    }
    else{
        (*q)->tail->next = new_node;
        new_node->prev = (*q)->tail;
        (*q)->tail = new_node;
    }
}

Data_t dequeue(Queue_t** q) {
    Data_t new_data;
    new_data.str[0] = '\0';
    new_data.cost = -1;

    if ((*q)->head == NULL) return new_data;

    QueueNode_t* temp = (*q)->head;

    strcpy(new_data.str, temp->data.str);
    new_data.cost = temp->data.cost;

    (*q)->head = (*q)->head->next;

    if ((*q)->head != NULL) (*q)->head->prev = NULL;
    else (*q)->tail = NULL;
    free(temp);

    return new_data;
}

int isQueueEmpty(Queue_t* q){
    QueueNode_t* node = q->head;

    if (node == NULL) return 1;
    return 0;
}

char *reverse(char str[MAXLEN], int start, int end){
    int len = strlen(str);
    static char temp[MAXLEN];

    strcpy(temp, str);

    for(int i=start, j=end; i<j; i++, j--){
            temp[i] = str[j]; 
            temp[j] = str[i];
    }
    
    return temp;
}

void insert(char key[MAXLEN], StrTreeNode_t** leaf, Compare cmp){
    int res;
    if((*leaf)== NULL){
        (*leaf) = malloc(sizeof(StrTreeNode_t));    
        strcpy ((*leaf)->value, key);                   
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
    } 
    else{
        res = cmp(key,(*leaf)->value);
        if(res < 0)
            insert(key, &(*leaf)->p_left, cmp);
        else if(res > 0)
            insert(key, &(*leaf)->p_right, cmp);
        else   
            return;
    }
    return;
}

int CmpStr(const char *a, const char *b){
    return (strcmp (a, b));   
}

int search(char key[MAXLEN], StrTreeNode_t* leaf, Compare cmp){
    int res;
    
    if(leaf != NULL) {
        res = cmp(key, leaf->value);
        if(res < 0)
            return search(key, leaf->p_left, cmp);
        else if(res > 0)
            return search(key, leaf->p_right, cmp);
        else
            return 1;
    }
    
    return 0;
}

int BFS(char str[MAXLEN], char target[MAXLEN], int len, int K){
    int cost = 0, count = 0;
    Queue_t* q=createQueue();
    StrTreeNode_t *p_root = NULL;
    Data_t temp_data;
    
    strcpy(temp_data.str, str);
    temp_data.cost = cost;
    
    enqueue(&q, temp_data);
    insert(str, &p_root, (Compare)CmpStr);

    while((!isQueueEmpty(q))){
        Data_t new_node = dequeue(&q);
        char temp[MAXLEN];

        strcpy(temp, new_node.str);
        cost = new_node.cost;

        if(strcmp(temp, target)==0) return cost;

        for(int i=0; i<=(len-K); i++){
            char new[MAXLEN];
            strcpy(new, reverse(temp, i, i+K-1));

            if(search(new, p_root,(Compare)CmpStr)==0){
                strcpy(temp_data.str, new);
                temp_data.cost = cost+1;

                enqueue(&q, temp_data);
                insert(temp_data.str, &p_root, (Compare)CmpStr);
            }
        }
        count++;
    }
    return -1;
}

int main(void){
    int N, K;
    char str_input[MAXLEN], target[MAXLEN];

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        str_input[i] = '0'+x;
        target[i] = '1'+i;
    }
    str_input[N]='\0';
    target[N]='\0';

    scanf("%d", &K);

    printf("%d\n", BFS(str_input, target, N, K));

    return 0;
}
