//07, 10, 2018, 09:36:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll x, y, d;
const ll mod = 1e9 + 7;
const int M = 1010;
ll fat[M];

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1LL; y = 0LL; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


ll MOD(ll x){
    return ((x % mod) + mod) % mod;   
}

ll inverso(ll k){
    extendedEuclid(k, mod);

    return MOD(x);
}

ll comb(ll n, ll k){
    if(n < k){
        return 0LL;
    }

    if(k == 0LL || n == k){
        return 1LL;
    }

    if(k == 1LL){
        return n;
    }

    ll p = 1LL;

    for(ll i = n ; i > (n - k) ; i--){
        p *= i;
        p %= mod;
    }

    p *= inverso(fat[k]);
    p %= mod;

    return p;
}

ll fast_pow(ll x, ll p){
    if(p == 0LL){
        return 1LL;
    }

    if(p == 1LL){
        return x;
    }

    ll a = fast_pow(x, p / 2LL);
    
    a *= a;
    a %= mod;

    if(p & 1LL){
        a *= x;
        a %= mod;
    }

    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    fat[0] = fat[1] = 1LL;

    for(ll i = 1LL ; i < M ; i++){
        fat[i] = i * fat[i - 1];
        fat[i] %= mod;
    }
    
    scanf("%d", &t);
    // printf("aqui\n");

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll tot = 0LL;

        for(ll i = 1LL ; i <= k ; i++){
            tot += (((comb(k - 1LL, i - 1LL) * comb(n - k + 1LL, i)) % mod) * fast_pow(2LL, i)) % mod;
            // printf("%lld +%lld\n", i, comb(n - k + 1LL, i));
            // printf("%lld +%lld\n", k - 1LL, (((comb(k - 1LL, i - 1LL) * comb(n - k - i + 2LL, i)) % mod) * fast_pow(2LL, i)) % mod);
            tot %= mod;
        }

        printf("%lld\n", tot);
    }

    return 0;
}