#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main (){
    ll tot = 0LL;
    ll n, w, k;

    cin >> k >> n >> w;

    tot = ((k + w * k) * w) / 2LL;

    cout << max(0LL, tot - n) << '\n';

    return 0;
}