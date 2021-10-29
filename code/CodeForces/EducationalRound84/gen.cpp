#include <bits/stdc++.h>

using namespace std;

int main(){
    printf("1\n");
    int n = int(1e5);

    printf("%d\n", n);

    for(int i = 1 ; i <= n ; i++){
        printf("%d ", n - i + 1);
    }
    printf("\n");

    for(int i = 1 ; i <= n ; i++){
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}