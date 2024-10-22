#include <stdio.h>

int emas(int x){
	int x1, x2, x3, sum=0;
	x1 = x/2;
	x2 = x/3;
	x3 = x/4;
	sum  = x1+x2+x3;
	if(x >= sum) return x;
	else{
		return emas(x1)+emas(x2)+emas(x3); 
	}
}

int main(void) {
	int N;
	scanf("%d",&N);
	printf("%d\n",emas(N));
	return 0;
}