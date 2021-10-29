#include <bits/stdc++.h>

using namespace std;

const int16_t inf = 520;
const int N = 510;
int16_t dp[N][N][N];
int16_t used[N][N][N];
int a[N];
int n, x;
int test = 1;

int16_t solve(int16_t i, int16_t greater, int16_t x){
    if(i == n){
        return 0;
    }

    if(a[i] < greater){
        return inf;
    }

    // printf("%d, %d, %d\n", i, greater, x);

    int16_t &us = used[i][greater][x];
    int16_t &ans = dp[i][greater][x];

    if(us == test){
        return ans;
    }

    us = test;
    ans = inf;

    if(x >= greater && x < a[i]){
        ans = solve(i + 1, x, a[i]) + 1;
    }

    ans = min(ans, solve(i + 1, a[i], x));

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        int x;

        scanf("%d %d", &n, &x);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        auto ans = solve(0, 0, x);
        printf("%d\n", ans >= inf ? -1 : ans);
    }

    return 0;
}