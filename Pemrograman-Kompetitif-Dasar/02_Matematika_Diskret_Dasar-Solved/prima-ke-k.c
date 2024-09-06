#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 1000000

int main(void) {
	bool is_prime[N];
	memset(is_prime, true, sizeof(is_prime));
	int prime[N] , x = 0, y = 0, idx = 1;
	is_prime[0] = 0;
	is_prime[1] = 0;

	for(int p = 2; p*p<N;p++){
		if(is_prime[p]){
			for (int i = p*p;i<N;i+=p){
				is_prime[i]=0;
			}	
		}
	}
	for(int i=0; i<N; i++){
		if(is_prime[i]){
			prime[idx]=i;
			idx++;
		}
	}
	scanf("%d",&x);
	for(int i = 0;i<x;i++){
		scanf("%d",&y);
		printf("%d\n",prime[y]);
	}		
	return 0;
}