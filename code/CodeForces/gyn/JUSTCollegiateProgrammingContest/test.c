#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int t = 100;

    printf("%d\n", t);

    while(t--){
        int n;

        n = rand() % 4 + 1;

        printf("%d\n", n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                printf("%d ", rand() % 9 + 1);
            }
            printf("\n");
        }
    }

    return 0;
}