//10, 06, 2018, 07:06:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    ll n, m, a, b;

    cin >> n >> m >> a >> b;

    ll r = n % m;
    ll n1 = m - r;

    cout << min (a * n1, b * r) << endl;
    
    return 0;
}