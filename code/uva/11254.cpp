//28, 04, 2018, 16:51:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    ll n;

    while(cin >> n){
        if(n <= -1LL)
            break;
            
        for(ll i = ceil(sqrt(n)) * 2 ; i >= 1LL ; i--){
            ll up = 2LL * n - i * i + i;
            ll down = 2LL * i;

            if(up > 0LL && down > 0LL && up % down == 0LL){
                ll a = up / down;
                cout << n << " = " << a << " + ... + " << a + i - 1LL << endl;
                break;
            }
        }
    }

    return 0;
}