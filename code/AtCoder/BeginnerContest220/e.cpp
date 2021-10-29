#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = 998244353LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, d;

    cin >> n >> d;

    ll depth = n - 1;
    ll init = 1LL;
    ll ep = 1LL;
    d--;

    for(int i = 0 ; i < d ; i++){
        ep = (ep << 1LL);
        ep %= mod;
    }

    ll ans = 0LL;

    while(depth > 0){
        ll de = min(depth, d);
        ll add = (ep * init) % mod;
        add = add * min(de, 2LL * de - d + 1);
        cout << add << "\n";
        add %= mod;

        ans += add;
        if(ans >= mod){
            ans -= mod;
        }

        init <<= 1LL;
        init %= mod;
        depth--;
    }

    cout << ans << "\n";

    return 0;
}