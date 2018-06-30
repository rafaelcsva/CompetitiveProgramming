//23, 06, 2018, 20:15:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll fast_pow(ll b, ll p, ll mod){
    if(p == 0)
        return 1LL;
    
    if(p == 1LL)
        return b;

    ll a = fast_pow(b, p / 2LL, mod);

    a *= a;

    a %= mod;

    if(p & 1LL)
        a *= b;
    
    return a % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll b, p, m;

    while(cin >> b >> p >> m){
        cout << fast_pow(b, p, m) << endl;
    }
    
    return 0;
}