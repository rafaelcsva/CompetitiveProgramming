//07, 09, 2018, 11:55:47 Rafaelcs cpp
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
        ll n, m, k;

        cin >> n >> m >> k;

        ll mn = min(n, m) + abs(n - m);
        
        if(mn > k){
            cout << -1 << endl;
            continue;
        }

        if(mn == k){
            cout << mn - (abs(n - m) & 1LL) << endl;
            continue;
        }else{
            ll r = abs(n - m) % 2LL;
            ll diag = 0LL;

            if(r){
                diag = mn - 1LL;
                diag += (k - mn);           
            }else{
                diag = mn - 1LL;
                k -= (mn - 1LL);

                ll r = k / 2LL;
                // cout << "k = " << k << endl;
                if(k % 2LL == 0LL){
                    r--;
                }

                diag += r * 2LL + (k % 2LL);
            }

            cout << diag << endl;
        }
    }
    return 0;
}