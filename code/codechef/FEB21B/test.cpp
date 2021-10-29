#include <bits/stdc++.h>

using namespace std;

const int N = int(1 << 30);

int main(){
    int n = int(2e5);
    int m = int(2e5);

    printf("%d\n", n);

    for(int i = 0 ; i < n ; i++){
        printf("%d ", rand() % N + 1);
    }

    printf("%d\n", m);

    while(m--){
        printf("%d\n", rand() % n + 1);
    }

    printf("\n");
}