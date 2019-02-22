//24, 11, 2018, 05:47:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;

    cin >> q;
    
    while(q--){
        ll l, r;

        cin >> l >> r;

        ll e = (r - l + 1LL);

        if(e == 1LL){
            if(l & 1LL){
                cout << - l << endl;
            }else{
                cout << l << endl;
            }
            continue;
        }

        ll f1n = ((e + 1LL) / 2LL);
        ll f2n = e / 2LL;
        ll a1n, a2n;
        ll sum1, sum2;

        if(l & 1LL){
            if(e & 1LL){
                a1n = -r;
                a2n = r - 1LL;
            }else{
                a1n = -(r - 1LL);
                a2n = r;
            }

            sum1 = ((-l + a1n) * f1n) / 2LL;
            sum2 = ((l + 1LL + a2n) * f2n) / 2LL;
        }else{
            if(e & 1LL){
                a2n = r;
                a1n = -(r - 1LL);
            }else{
                a2n = r - 1LL;
                a1n = -r;
            }

            sum2 = ((l + a2n) * f1n) / 2LL;
            sum1 = ((-(l + 1LL) + a1n) * f2n) / 2LL;
        }

        cout << sum2 + sum1 << endl;
        // cout << sum1 << " " << sum2 << " " << a1n << endl;
    }
    return 0;
}