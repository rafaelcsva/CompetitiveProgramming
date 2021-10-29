#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        ll ni;

        cin >> ni;

        ll ans = 0LL;

        for(ll d = 0LL ; d <= 40LL ; d++){
            ll e = 1LL << d;

            if(ni & e){
                ans = e - 1LL;
            }
        }

        cout << ans << endl;
    }
}