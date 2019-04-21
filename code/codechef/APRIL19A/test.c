#include <stdio.h>

int a[200010];

int main(){
    int t = 1;

    printf("%d\n", t);

    while(t--){
        int n = 2e5, q = 1e6;

        printf("%d %d\n", n, q);

        for(int i = 1 ; i <= n ; i++){
            printf("%d ", 111);
        }

        printf("\n");

        for(int i = 1 ; i < n ; i++){
            printf("%d %d\n", i, i + 1);
        }

        while(q--){
            printf("%d %d\n", 1, 1212);
        }
    }

    return 0;
}