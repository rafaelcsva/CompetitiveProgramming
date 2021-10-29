#include <bits/stdc++.h>

using namespace std;

const int D = 512;
const int N = int(1e5) + 10;

int dp[2][D];
int a[N];

int mmin(int a, int b){
    if(a == -1){
        return b;
    }

    return min(a, b);
}

int main(){
    memset(dp, -1, sizeof dp);

    int n;

    scanf("%d", &n);

    dp[1][0] = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        for(int j = 0 ; j < D ; j++){
            dp[i & 1][j] = dp[!(i & 1)][j];

            if(dp[!(i & 1)][j ^ a[i]] == -1){
                continue;
            }

            if(dp[!(i & 1)][j ^ a[i]] < a[i]){
                dp[i & 1][j] = mmin(dp[!(i & 1)][j], a[i]);
            }
        }
    }

    vector< int > ans;

    for(int j = 0 ; j < D ; j++){
        if(dp[(n - 1) & 1][j] != -1){
            ans.push_back(j);
        }
    }

    printf("%lu\n", ans.size());

    for(auto u: ans){
        printf("%d ", u);
    }

    printf("\n");

    return 0;
}