//16, 03, 2019, 09:15:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 100);
ll dp[N];
ll carry[N];
ll match[N];
ll rr[N];
const ll mod = ll(1e9) + 7;
vector< ll > c;

ll MOD(ll x){
    if(x >= mod){
        return x - mod;
    }

    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    ll last = -1LL;

    cin >> n;

    int idx = 1;

    for(int i = 1 ; i <= n ; i++){
        ll ci;

        cin >> ci;

        if(ci == last){
            continue;
        }

        last = ci;
        match[idx] = rr[ci];
        // cout << idx << " -> " << rr[ci] << endl; 
        rr[ci] = idx;

        c.push_back(ci);
        idx++;
    }

    dp[1] = 1LL;

    // cout << c.size() << endl;
    for(int i = 2LL ; i <= c.size() ; i++){
        dp[i] = MOD(dp[match[i]] + dp[i - 1]);
    }

    cout << dp[c.size()] << endl;

    return 0;
}