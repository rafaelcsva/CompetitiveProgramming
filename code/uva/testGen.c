#include <stdio.h>

const int N = 5000;

int main (){
    printf("%d", N);

    for(int i = 1 ; i <= N ; i++){
        printf("%d", N - 1 );

        for(int j = 1 ; j <= N ; j++){
            if(j == i){
                continue;
            }
            printf(" %d", j);
        }
        printf("\n");
    }

    return 0;
}