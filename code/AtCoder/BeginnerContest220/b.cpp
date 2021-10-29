#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll k, a, b;

    cin >> k >> a >> b;

    ll p = 1LL;

    ll na = 0LL, nb = 0LL;

    while(a || b){
        // cout << "+ " << (a % k) * p <<"\n";

        na += (a % 10) * p;
        nb += (b % 10) * p;

        a /= 10;
        b /= 10;

        p *= k;
    }

    cout << na * nb << "\n";

    return 0;
}