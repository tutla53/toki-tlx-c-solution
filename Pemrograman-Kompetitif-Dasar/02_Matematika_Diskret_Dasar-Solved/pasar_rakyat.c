#include<stdio.h>

long long gcd(long long a, long long b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

/*LCM of array*/
long long lcm(int arr[], int n){
    long long result=arr[0];

    for (int i = 0; i<n; i++){
        result = (arr[i]*result)/gcd(arr[i],result);
    }

    return result;
}

int main(void){
    long long result = 0;
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    result = lcm(arr,n);
    printf("%lld\n", result);

    return 0;
}