#include <stdio.h>

int fibo(int n, int a, int b){
    if(n == 1){
        return a;
    }
    if(n == 2){
        return b;
    }else{
        return fibo(n-1, a, b) + fibo(n-2, a, b);
    }
}

int main(){
    int n, a, b;
    int i, j;
    scanf("%d %d %d", &n, &a, &b);

    int result = fibo(n, a, b);
    printf("%d\n", result);

    return 0;
}