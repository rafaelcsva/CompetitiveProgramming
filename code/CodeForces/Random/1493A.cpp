#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        int num = n - k;

        vector< int > cho;

        for(int d = k - 1, e = 1 ; d >= e ; d--, e++){
            cho.push_back(d);
        }

        for(int d = k + 1 ; d <= n ; d++){
            cho.push_back(d);
        }

        printf("%lu\n", cho.size());

        for(auto u: cho){
            printf("%d ", u);
        }
        printf("\n");
    }

    return 0;
}