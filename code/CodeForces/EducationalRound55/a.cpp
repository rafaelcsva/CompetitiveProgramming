//28, 11, 2018, 12:36:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        ll n, x, y, d;

        cin >> n >> x >> y >> d;

        ll diff = abs(x - y);

        if(diff % d == 0LL){
            cout << diff / d << endl;
        }else{
            ll diff1 = abs(n - y);
            ll diff2 = abs(y - 1LL);
            ll add1 = (abs(x - n) + d - 1LL) / d;
            ll add2 = (abs(x - 1LL) + d - 1LL) / d;

            if(diff1 % d != 0LL){
                if(diff2 % d == 0LL){
                    cout << add2 + diff2 / d << endl;
                }else{
                    cout << -1 << endl;
                }
            }else if(diff2 % d != 0LL){
                if(diff1 % d == 0LL){
                    cout << add1 + diff1 / d << endl;
                }else{
                    cout << -1 << endl;
                }
            }else{
                cout << min(add1 + diff1 / d, add2 + diff2 / d) << endl;
            }
        }
    }

    return 0;
}