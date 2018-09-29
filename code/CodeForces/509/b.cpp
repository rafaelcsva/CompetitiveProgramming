//16, 09, 2018, 07:40:02 Rafaelcs cpp
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

    ll mn = min(a / x, b / y);
    
    cout << mn << endl;
    
    return 0;
}