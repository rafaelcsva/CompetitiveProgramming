#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n = 5000;
    int t;

    printf("1\n");

    printf("%d\n", n);

    for(int i = 1 ; i <= n ; i++){
        printf("%d ", 5000 - i + 1);
    }

    printf("\n");
}