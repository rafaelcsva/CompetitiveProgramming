#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    cin >> t;

    while(t--){
        ll b, d;

        cin >> b >> d;

        ll mm = b * d / __gcd(b, d);

        ll div = mm / b;
        ll ans = b / div;
        // cout << b << " " << div << endl;
        if(b % div == 0LL){
            ans--;
        }
        cout << ans << endl;
    }

    return 0;
}