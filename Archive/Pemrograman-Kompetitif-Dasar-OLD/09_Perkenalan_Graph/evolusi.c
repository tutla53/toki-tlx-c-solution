#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char name[25];
    struct Node* prev;
} Node_t;

typedef struct List{
    Node_t *node;
}List_t;

int compare(const void* a, const void* b){ 
    
    const char* idA = ((Node_t*)a)->name; 
    const char* idB = ((Node_t*)b)->name; 
  
    return strcmp(idA,idB); 
}

Node_t createNode(char name[25]){
    Node_t node;
    strcpy(node.name, name);
    node.prev = NULL;

    return node;
}

void printancestor(Node_t* Nd){
    Node_t* temp = Nd;
    while(temp != NULL){
        printf("%s->", temp->name);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(void){
    int N, M, idx=0;
    char dummy_name[25] = "ZZZZZZZZZZZZZZZZZZZZ";
    scanf("%d %d", &N, &M);
    Node_t *P_in_list, *C_in_list;
    Node_t species_list[N];

    for(int i=0;i<N;i++) species_list[i] = createNode(dummy_name);

    for(int i=0; i<M; i++){
        char P[25], C[25];
        scanf("%s %s", P, C);
        Node_t P_temp = createNode(P);
        Node_t C_temp = createNode(C);

        qsort(species_list, N, sizeof(Node_t), compare);
        P_in_list = bsearch(&P, species_list, N, sizeof(Node_t), compare);
    
        if(P_in_list == NULL){
            species_list[idx] = P_temp;
            idx++;
            C_temp.prev = &P_temp;    
        }
        else{
            C_temp.prev = P_in_list;
        }
        species_list[idx] = C_temp;
        idx++;
        for(int j=0; j<N; j++){
            printf("%s\n", species_list[j].name);
        }
    }

    for(int j=0; j<N; j++){
        if(species_list[j].prev != NULL)
            printf("%s %s\n", species_list[j].name, species_list[j].prev->name);
    }

    
    return 0;
}