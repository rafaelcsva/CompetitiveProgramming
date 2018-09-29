//08, 09, 2018, 09:33:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll x;

    cin >> n >> x;
    ll g = 0;

    for(int i = 0 ; i < n ; i++){
        ll a;

        cin >> a;

        g = __gcd(g, abs(x - a));
    }

    cout << g << endl;
    
    return 0;
}