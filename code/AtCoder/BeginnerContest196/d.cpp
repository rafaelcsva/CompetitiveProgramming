#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
int h, w;

ll dp[1 << 16][16][16];
int tot;

bool check(int mask, int i, int j){
    if(j >= w || i >= h){
        return false;
    }

    int d = 1 << (i * w + j);

    return (mask & d) == 0;
}

int pos(int i, int j){
    return 1 << (i * w + j);
}

ll solve(int mask, int a, int b, int i, int j){
    if(mask == tot){
        return 1LL;
    }

    if(i >= h){
        return 0LL;
    }

    if(j == w){
        return solve(mask, a, b, i + 1, 0);
    }

    if(!check(mask, i, j)){
        return solve(mask, a, b, i, j + 1);
    }

    ll &ans = dp[mask][a][b];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    if(a){
        if(check(mask, i, j + 1)){
            ans += solve(mask | pos(i, j + 1) | pos(i, j), a - 1, b, i, j + 2);
        }

        if(check(mask, i + 1, j)){
            ans += solve(mask | pos(i, j) | pos(i + 1, j), a - 1, b, i, j + 1);
        }
    }

    if(b){
        ans += solve(mask | pos(i, j), a, b - 1, i, j + 1);
    }

    return ans;
}

int main(){
    memset(dp, -1LL, sizeof dp);
    int a, b;

    scanf("%d %d %d %d", &h, &w, &a, &b);

    tot = (1 << (h * w)) - 1;

    printf("%lld\n", solve(0LL, a, b, 0, 0));

    return 0;
}