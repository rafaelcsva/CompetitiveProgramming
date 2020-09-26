#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = 998244353LL;

const int N = int(6e5 + 10);
ll fat[N];
int l[N], r[N];
int add[2 * N], ret[2 * N];

ll fast_expo(ll x, ll e){
    ll r = 1LL;
    ll b = x;

    while(e){
        if(e & 1LL){
            r = (r * b) % mod;
        }

        e >>= 1LL;
        b = (b * b) % mod;
    }

    return r;
}

ll comb(ll n, ll k){
    if(k > n){
        return 0LL;
    }
    
    ll inv = fast_expo((fat[k] * fat[n - k]) % mod, mod - 2LL);

    return (fat[n] * inv) % mod;
}

int main(){
    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = (fat[i - 1] * i) % mod;
    }

    int n, k;

    scanf("%d %d", &n, &k);

    vector< int > v;

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &l[i], &r[i]);

        v.push_back(l[i]);
        v.push_back(r[i]);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i++){
        l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
        r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();

        add[l[i]]++;
        ret[r[i]]++;
    }

    ll tot = 0LL;
    ll cur = 0LL;

    for(int i = 0 ; i < v.size() ; i++){
        ll ad = add[i];

        tot += comb(cur + ad, k);

        if(tot >= mod){
            tot -= mod;
        }

        tot -= comb(cur, k);

        if(tot < 0LL){
            tot += mod;
        }

        cur += ad;
        cur -= ret[i];
    }

    printf("%lld\n", tot);

    return 0;
}