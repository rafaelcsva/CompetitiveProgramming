//28, 11, 2018, 08:44:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll digit(ll x){
    ll d = 0;

    while(x){
        d++;
        x /= 10LL;
    }

    return d;
}

ll get_last(ll digits){
    ll start = 9LL;

    for(ll i = 1LL ; i < digits ; i++){
        start = start * 10LL + 9LL;
    }

    return start;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        ll n, x;

        cin >> n >> x;

        bool ok = true;
        ll pages = 0LL;

        while(true){
            ll digits = digit(x);
            ll last = get_last(digits);
            ll have = (last - x + 1LL) * digits;

            if(have >= n){
                if(n % digits == 0LL){
                    pages += n / digits;
                    break;
                }else{
                    ok = false;
                    break;
                }
            }else{
                pages += have / digits;
                n -= have;
                x = last + 1LL;
            }
        }

        if(ok){
            cout << pages << endl;
        }else{
            cout << -1 << endl;
        }
    }
    
    return 0;
}