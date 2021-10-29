#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
const int K = int(450);
ll a[N];
ll dp[N][K];
const ll inf = ll(1e18);
ll pre[N];

ll rsq(int l, int r){
    if(l == 0){
        return pre[r];
    }

    return pre[r] - pre[l - 1];
}

int main(){
    memset(dp, -1, sizeof dp);

    int t;

    scanf("%d", &t);

    while(t--){

        int n;

        scanf("%d", &n);

        dp[n][0] = inf;

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
            pre[i] = a[i];

            if(i){
                pre[i] += pre[i - 1];
            }
    
            dp[i][0] = inf;
        }

        for(int d = 1 ; d < K ; d++){
            bool frag = false;

            for(int i = n ; i >= 0 ; i--){
                if(i + d > n){
                    dp[i][d] = -1;
                    continue;
                }

                dp[i][d] = dp[i + 1][d];    

                if(dp[i + d][d - 1] > rsq(i, i + d - 1)){
                    dp[i][d] = max(dp[i][d], rsq(i, i + d - 1));
                }

                if(dp[i][d] != -1){
                    frag = true;
                }
            }

            if(!frag){
                printf("%d\n", d - 1);
                break;
            }
        }
    }

    return 0;
}