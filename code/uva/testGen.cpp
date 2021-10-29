#include <bits/stdc++.h>

const int N = 300000;
const int u = int(1e9);
const int m = int(5e4);

int main (){
    printf("%d %d %d\n", N, m, u);

    for(int i = 0 ; i < N ; i++){
        printf("%d\n", rand() % u + 1);
    }

    for(int i = 0 ; i < m ; i++){
        printf("%d %d %d %d\n", 1 + 1, N - 1, rand() % u + 1, rand() % N + 1);
    }

    return 0;
}