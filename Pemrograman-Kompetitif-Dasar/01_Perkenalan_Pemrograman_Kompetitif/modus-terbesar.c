#include<stdio.h>
#include<string.h>

#define MAX_VAL 1010

int main() {
	int arr[MAX_VAL], N, max=0, modes = 0, idx;
	memset(arr, 0, MAX_VAL*sizeof(int));
	scanf("%d", &N);
    
	while(N--){
		int data;
		scanf("%d", &data);
		arr[data]++;
		max = (data>max ? data: max);
	}

	for(int i=0; i<=max; i++){
		if(arr[i] >= modes){
			modes = arr[i];
			idx = i;
		}
	}

	printf("%d\n", idx);

	return 0;
}