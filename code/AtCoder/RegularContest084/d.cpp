//24, 10, 2018, 08:30:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 80, M = int(1e5 + 2), D = 10;
int dp[N][M][2];
bool used[N][M][2];
int k;
const int inf = 1e9;

int solve(int digt, int sum, bool flag){
    if(sum == 0 && flag){
        return 0;
    }

    if(digt < 0){
        return inf;
    }

    bool &us = used[digt][sum][flag];
    int &ans = dp[digt][sum][flag];

    if(us){
        return ans;
    }

    us = true;
    ans = inf;

    for(int d = 0 ; d < D ; d++){
        ans = min(ans, d + solve(digt - 1, (sum * 10 + d) % k, flag | (d != 0)));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d", &k);

    printf("%d\n", solve(N - 1, 0, false));

    return 0;
}