#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int t = 10;
    printf("%d\n", t);

    while(t--){
        int n = rand() % 10 + 1, p = rand() % 500 + 1;

        printf("%d %d\n", n, p);

        for(int i = 0 ; i < n ; i++){
            printf("%d ", rand() % 500);
        }
        printf("\n");
    }

    return 0;
}