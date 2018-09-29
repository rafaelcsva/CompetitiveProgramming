//26, 07, 2018, 17:55:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
set<ll>r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    ll d = 0LL;

    for(int i = 0 ; i < n ; i++){
        ll x;

        cin >> x;

        d = __gcd(d, x % k);
    }
    
    for(ll x = 0 ; x < k ; x++){
        r.insert((x * d) % k);
    }

    cout << r.size() << endl;

    for(set<ll>::iterator it = r.begin() ; it != r.end() ; it++){
        cout << *it << ' ';
    }

    cout << endl;

    return 0;
}