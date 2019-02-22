//30, 11, 2018, 15:04:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, x, y;

    cin >> a >> b >> x >> y;

    ll g = __gcd(x, y);

    x /= g;
    y /= g;

    cout << min(a / x, b / y) << endl;

    return 0;
}