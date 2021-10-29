#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, d;

        scanf("%d %d", &n, &d);

        int sq = sqrt(d);

        int mn = int(1e9) + 10;

        for(int i = -1 ; i <= 1 ; i++){
            int x = sq + i;

            mn = min(mn, x + (d + x) / (x + 1));
        }

        if(mn <= n){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}