#include <stdio.h>

int main() {
	int n=0;
	int identik = 1, vertikal = 1, horizontal =1, kanan = 1, kiri =1;
	
	scanf("%d %d",&n, &n);
	int x[n][n], y[n][n]; 

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&x[i][j]);
		}
	}
	
	scanf("%d %d",&n, &n);
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&y[i][j]);
		}
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			identik 	&= (x[i][j]==y[i][j]);
			vertikal	&= (x[i][j]==y[i][n-j-1]);
			horizontal	&= (x[i][j]==y[n-i-1][j]);
			kanan		&= (x[i][j]==y[j][i]);
			kiri		&= (x[i][j]==y[n-j-1][n-i-1]);
		}
	}
	
	if(identik) 		printf("identik\n");
	else if(vertikal)	printf("vertikal\n");
	else if(horizontal)	printf("horisontal\n");
	else if(kanan)		printf("diagonal kanan bawah\n");
	else if(kiri)		printf("diagonal kiri bawah\n");
	else 				printf("tidak identik\n");
	
	return 0;
}
