//03, 06, 2018, 09:25:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(3e5 + 10);
const ll mod = 998244353LL;
ll x, y;
ll fat[N];
ll d;

void gen(){
    fat[0] = 1LL;

    for(ll i = 1 ; i < N ; i++){
        fat[i] = fat[i - 1] * i;
        fat[i] %= mod;
    }
}

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

ll MOD(ll n){
    return ((n % mod) + mod) % mod;
}

ll inverso(ll n){
    extendedEuclid(n, mod);

    return MOD(x);
}

ll c(ll n, ll k){
    ll a = inverso(fat[n - k]);
    ll b = inverso(fat[k]);

    return MOD(a * MOD(b * fat[n]));
}

int main(){
    gen();
    ll n, a, b, k;

    cin >> n >> a >> b >> k;

    ll sum = 0LL;

    for(ll ca = 0LL ; ca <= n ; ca++){
        ll cb = k - ca * a;

        if(cb >= 0LL && cb % b == 0LL){
            cb = cb / b;

            if(cb > n || ca > n){
                continue;
            }

            sum += c(n, cb) * c(n, ca);
            sum %= mod;
        }
    }

    cout << sum << endl;

    return 0;
}