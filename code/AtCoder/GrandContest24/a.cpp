//20, 05, 2018, 09:03:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

ll INF = ll(1e18);
ll MX = ll(1e8);

int digits(ll n){
    int d = 0;

    while(n){
        d += n % 10LL;
        n /= 10LL;
    }

    return d;
}

map<pair<int, pii>, ll > mp;

int main(){
    ll a, b, c, k;

    cin >> a >> b >> c >> k;
    
    if(k % 2LL == 0LL){
        cout << a - b << endl;
    }else{
        cout << b - a << endl;
    }

    return 0;
}