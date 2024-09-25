#include<stdio.h>
#include<string.h>

int reverse(int x) {
  int temp = x;
  int ret = 0;

  while (temp > 0) {
    ret = (ret * 10) + (temp % 10);
    temp = temp / 10;
  }

  return ret;
}

int main() {
    int a,b, A, B;

    scanf("%d %d", &A, &B); 
    a = reverse(A);
    b = reverse(B); 

    printf("%d\n", reverse(a+b));
    
	return 0;
}