//13, 04, 2019, 11:08:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;

    cin >> n >> t;

    int take = 1e9;
    int resi = -1;

    for(ll i = 1 ; i <= n ; i++){
        ll di, si;

        cin >> di >> si;

        if(di >= t){
            if(take > di){
                resi = i;
                take = di;
            }
        }else{
            ll dif = t - di;
            ll q = (dif + si - 1) / si;

            ll tim = di + q * si;

            if(tim < take){
                resi = i;
                take = tim;
            }
        }
    }

    cout << resi << endl;
    
    return 0;
}