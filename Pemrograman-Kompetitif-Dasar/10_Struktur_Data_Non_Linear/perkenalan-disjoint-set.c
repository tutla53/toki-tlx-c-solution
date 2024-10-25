#include<stdio.h>
#include<stdlib.h>

int find_parent(int a, int parent[]){
    if (parent[a] == a) return a;
    else return (parent[a] = find_parent(parent[a], parent));
}

void join(int a, int b, int parent[]){
    int pr_a = find_parent(a, parent);
    int pr_b = find_parent(b, parent);
    parent[pr_a] = pr_b;
}

int main(void){
    int N, Q, *parent;
    scanf("%d %d", &N, &Q);
    
    parent = malloc((N+5)*sizeof(parent));
    for(int i=0; i<(N+5); i++) parent[i] = i;

    while(Q--){
        int x, a, b;
        scanf("%d %d %d", &x, &a, &b);
        if(x==1) join(a,b, parent);
        else (find_parent(a, parent) == find_parent(b, parent)) ? printf("Y\n"): printf("T\n");
    }

    return 0;
}