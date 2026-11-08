#include <stdio.h>
#include <stdlib.h>

int sum_of_divisors(int k){
    int sum = 0;
    for(int i=1; i<=k/2; i++){
        if(k%i==0) sum = sum + i;
    }
    return sum;
}

int main(){
    int n;
    printf("Enter N:\n");
    scanf("%d",&n);

    int *arr = malloc((n+1) * sizeof(int));
    for(int i=0; i<=n; i++) arr[i] = 0;

    for(int i=1; i<=n; i++){
        arr[i] = sum_of_divisors(i);
    }
    int count = 0;
    printf("Amicable pairs up to %d:\n",n);
    for(int a=1; a<=n; a++){
    int b = arr[a];
    if(b > a && b <= n && arr[b] == a){
        printf("(%d, %d)\n", a, b);
        count++;
        }
    }
    printf("Total pairs: %d",count);

    free(arr);
    return 0;
}