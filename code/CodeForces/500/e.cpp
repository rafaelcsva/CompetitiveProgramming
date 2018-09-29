//30, 07, 2018, 09:42:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 5100;
ll h[N];
bool used[N][N / 2][3];
ll dp[N][N / 2][3];
int n;
const ll INF = 1e18;

ll solve(int i, int k, int c){
    // cout << i << ' ' << k << endl;
    if(!k){
        // cout << i << ' ' << k << ' ' << c << endl;
        return 0LL;
    }

    if(i > n){
        return INF;
    }
    
    ll &ans = dp[i][k][c];

    if(used[i][k][c]){
        return ans;
    }

    used[i][k][c] = true;
    
    ll cost = 0LL;
    ll lf = h[i - 1];
    ll rg = h[i + 1];
    
    if(c){
        lf = min(lf, h[i - 2] - 1LL);
    }

    lf = max(0LL, lf - (h[i] - 1));
    rg = max(0LL, rg - (h[i] - 1));
    
    cost = lf + rg;

    ans = min(solve(i + 1, k, 0), solve(i + 2, k - 1, 1) + cost);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> h[i];
    }

    h[0] = -INF;
    h[n + 1] = -INF;

    for(int k = 1 ; k <= (n + 1) / 2 ; k++){
        cout << solve(1, k, 0) << ' ';
    }
    cout << endl;
    
    return 0;
}