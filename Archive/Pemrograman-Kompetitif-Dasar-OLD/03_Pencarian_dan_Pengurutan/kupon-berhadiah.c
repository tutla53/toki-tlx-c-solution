#include<stdio.h>
#include<stdlib.h>

int main(){
    int N, x, min_value, dist;
    min_value = 1000000;
    dist = 1000000;

    scanf("%d %d", &N, &x);
    while(N--){
        int new_dist, ticket;
        
        scanf("%d", &ticket);
        new_dist = abs(x-ticket);
        if(new_dist<dist){
            dist = new_dist;
            min_value = ticket;
        }
        else if (new_dist == dist){
            if(ticket<min_value){
                min_value = ticket;
            }
        }
    }

    printf("%d\n", min_value);

    return 0;
}