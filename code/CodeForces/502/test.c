#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    
    int n = 12, m = 1e5, q = 1e5;

    printf("%d %d %d\n", n, m, q);

    for(int i = 0 ; i < n ; i++){
        printf("%d ", rand() % 101);
    }

    printf("\n");

    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            printf("%d", rand() % 2);
        }
        printf("\n");
    }

    for(int i = 0 ; i < q ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d", rand() % 2);
        }
        printf(" %d\n", rand() % 101);
    }

    return 0;
}