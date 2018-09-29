//20, 09, 2018, 21:53:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

string a, l, r;

const int N = int(1e6 + 100);
ll Bit[N];
const ll mod = 998244353LL;

int LSOne(int x){
    return x & (-x);
}

void update(int x, ll val){
    while(x < N){
        Bit[x] += val;
        Bit[x] %= mod;
        x += LSOne(x);
    }

}

ll query(int x){
    ll sum = 0LL;

    while(x > 0){
        sum += Bit[x];
        sum %= mod;
        x -= LSOne(x);
    }
}

ll MOD(ll x){
    return (x % mod + mod) % mod;
}

ll rsq(int l, int r){
    return MOD(query(r) - query(l - 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> l >> r;

    for(int i = int(a.length() - 1) ; i )

    return 0;
}