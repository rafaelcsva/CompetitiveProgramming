#include <stdio.h>

int main(){
    int t = 1;

    printf("%d\n", t);

    while(t--){
        int n = 100;

        printf("%d %d\n", n, 2);

        for(int i = 1 ; i < n ; i++){
            printf("%d %d\n", i, i + 1);
        }
    }

    return 0;
}