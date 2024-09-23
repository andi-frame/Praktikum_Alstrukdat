#include <stdio.h>

int main(){
    int a, b, result;

    scanf("%d %d", &a, &b);
    result = a;


    while (result <= b)
    {
        printf("%d", result);
        if(result%2 == 0){
            result *= 2;
        } else{
            result += 1;
        }

        if(result <= b){
            printf(" ");
        }
    }
    printf("\n");
    

    return 0;
}