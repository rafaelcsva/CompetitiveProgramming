//13, 10, 2018, 09:07:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;

    cin >> n >> m;

    string s, t;

    cin >> s >> t;

    bool ok = true;

    for(ll x = 0LL ; x < n ; x++){
        ll num = x * m;

        if(num % n == 0){
            ll y = num / n;

            if(y < m && s[x] != t[y]){
                ok = false;
                break;
            }
        }
    }

    if(ok){
        ll L = lcm(n, m);
        cout << L << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}