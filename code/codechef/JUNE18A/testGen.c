#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5, m = 5;
    int N = n * m;
    srand(time(NULL));

    printf("%d %d\n", n, m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ", i % 2);
        }
        printf("\n");
    }

    return 0;
}