//30, 12, 2018, 14:42:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 10);
ll x, y, d;
const ll mod = 998244353LL;
ll fat[N];

ll MOD(ll x){
    return ((x % mod) + mod) % mod;
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

ll inverso(ll val){
    extendedEuclid(val, mod);

    return MOD(x);
}

ll c(int n, int k){
    return MOD((MOD(fat[n] * inverso(fat[k]))) * inverso(fat[n - k]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    fat[0] = 1LL;

    for(ll i = 1 ; i < N ;i++){
        fat[i] = i * fat[i - 1];
        fat[i] %= mod;
    }

    int n;

    cin >> n;

    ll resp = fat[n];
    // cout << resp << endl;

    for(int l = 1 ; l < n ; l++){
        ll add = (fat[l] - 1LL) * (fat[n - l]);
        add = MOD(add);

        // cout << add << endl;
        add *= c(n, l);
        add = MOD(add);
        // cout << add << " -- " << c(n, l) << " " << n << " " << l << endl;

        // cout << "add = " << add << endl;
        resp += add;
        resp = MOD(resp); 
    }

    cout << resp << endl;

    return 0;
}