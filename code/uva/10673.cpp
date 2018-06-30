//25, 06, 2018, 13:49:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll x, y, d;

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) {
        x = 1; y = 0; d = a; 
        return; 
    }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    ll x_, k;

    cin >> t;

    while(t--){
        cin >> x_ >> k;

        extendedEuclid(x_ / k, (x_ + k - 1LL) / k);

        cout << x * (x_ / d) << ' ' << y * (x_ / d) << endl;
    }

    return 0;
}