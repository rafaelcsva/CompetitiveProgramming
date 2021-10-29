#include <bits/stdc++.h>

using namespace std;

const int N = 301;
int x, y;
int dp[N][N][N];
int n;
int A[N], B[N];
const int inf = int(1e9);

int solve(int i, int a, int b){
    if(a >= x && b >= y){
        return 0;
    }

    if(i >= n){
        return inf;
    }

    int &ans = dp[i][a][b];

    if(ans != -1){
        return ans;
    }

    ans = min(solve(i + 1, a, b), 1 + solve(i + 1, min(a + A[i], x), min(b + B[i], y)));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    scanf("%d %d", &x, &y);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &A[i], &B[i]);
    }

    int ans = solve(0, 0, 0);

    printf("%d\n", ans >= inf ? -1 : ans);

    return 0;
}