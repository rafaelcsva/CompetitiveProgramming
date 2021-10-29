#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, c;

        scanf("%d %d", &n, &c);

        printf("Case #%d: ", test);

        if(c < n - 1){
            printf("IMPOSSIBLE\n");
            continue;
        }

        vector< int > v;

        for(int i = 1 ; i <= n ; i++){
            v.push_back(i);
        }

        c -= (n - 1);

        for(int i = n - 1 ; i >= 0 ; i--) {
            int r = min(n - i - 1, c);

            reverse(v.begin() + i, v.begin() + i + r + 1);

            // for(auto u: v){
            //     printf("%d ", u);
            // }
            // printf("|%d, %d|\n", c, r);

            c -= r;
        }

        if(c){
            printf("IMPOSSIBLE\n");
        }else{
            for(auto u: v){
                printf("%d ", u);
            }
            printf("\n");
        }
    }

    return 0;
}