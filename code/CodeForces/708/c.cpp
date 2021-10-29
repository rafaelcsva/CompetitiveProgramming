#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        if(n & 1){
            printf("%d %d %d\n", 1, n / 2, n / 2);
        }else{
            printf("%d %d %d\n", 2, (n - 1) / 2, (n - 1) / 2);
        }
    }

    return 0;
}