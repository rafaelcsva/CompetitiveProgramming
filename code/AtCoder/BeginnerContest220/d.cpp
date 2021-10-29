#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int D = 10;
vector< int > dp[D][N];
bool marked[D][N];
int n;
int a[N];
const int mod = 998244353LL;

vector< int > sum(vector< int > a, vector< int > b){
    vector< int > res;

    for(int i = 0 ; i < D ; i++){
        int ansi = a[i] + b[i];

        if(ansi >= mod){
            ansi -= mod;
        }

        res.push_back(ansi);
    }

    return res;
}

vector< int > solve(int d, int i){
    auto &ans = dp[d][i];
    bool &us = marked[d][i];

    if(us){
        return ans;
    }

    us = true;

    if(i >= n){
        ans = vector< int >(D, 0);
        ans[d] = 1;

        return ans;
    }

    ans = sum(solve((d * a[i]) % 10, i + 1), solve((d + a[i]) % 10, i + 1));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        a[i] %= D;
    }

    auto ans = sum(solve((a[0] * a[1]) % 10, 2), solve((a[0] + a[1]) % 10, 2));

    for(auto u: ans){
        cout << u << "\n";
    }

    return 0;
}
