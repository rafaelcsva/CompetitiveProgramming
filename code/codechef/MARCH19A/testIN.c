#include <stdio.h>

int main(){
    int t = 10;

    printf("%d\n", t);
    
    while(t--){
        int n = 1e5, k = 1e5;
        printf("%d\n", n);

        const int number = 1e5;

        for(int i = 1 ; i <= n ; i++){
            printf("%d ", rand() % 2 + 1);
        }
        printf("\n");
    }

    return 0;
}