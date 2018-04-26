//11, 04, 2018, 08:39:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = int(1e7 + 10);
ll dp[N];
const ll mod = ll(1e9 + 7);

int main(){
    ll n, k, a, b;

    ios::sync_with_stdio(false);
    cin >> n >> k >> a >> b;

    dp[1] = k;

    for(int i = 2 ; i <= n ; i++){
        ll sum = 0LL;

        for(int j = 1 ; j <= i - 1 ; j++){
            sum += dp[i - j] * dp[j];
            sum %= mod;
        }    

        dp[i] = a * dp[i - 1] + sum * b;
        dp[i] %= mod;
    }

    cout << dp[n] % mod << endl;

    return 0;
}