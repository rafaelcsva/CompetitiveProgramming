#include <stdio.h>

const int N = 1e5;

int t = 10;

int main (){
    printf("%d\n", t);

    while(t--){
        printf("%d\n", N);

        for(int i = 0 ; i < N ; i++){
            printf("%d ", N);
        }    
        printf("\n");
        for(int i = 0 ; i < N ; i++){
            printf("%d ", 100);
        }
        printf("\n");
    }
    return 0;
}