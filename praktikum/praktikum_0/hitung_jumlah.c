#include <stdio.h>

int main(){
    int n, k, a_i, i;
    int result = 0;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++){
        scanf("%d", &a_i);
        if(a_i % k != 0){
            result += a_i;
        }
    }    
    printf("%d\n", result);

    return 0;
}