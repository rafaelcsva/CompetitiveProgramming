//25, 06, 2018, 08:26:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll mod = ll(1e9);

ll retire(ll n){
    while(n % 10LL == 0LL && n){
        n /= 10LL;
    }

    return n % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    
    while(cin >> n >> m){
        ll d = 1LL;

        for(int i = 0 ; i < m ; i++){
            d = retire(d * n);
            n--;
        }

        cout << d % 10LL << endl;
    }

    return 0;
}