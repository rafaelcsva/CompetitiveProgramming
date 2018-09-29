//18, 08, 2018, 11:44:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, q;

    cin >> n >> q;

    ll st1 = 0, st2 = (n * n + 1LL) / 2LL ;
    
    for(int i = 0 ; i < q ; i++){
        int x, y;

        cin >> x >> y;

        ll lin = x - 1;
        ll m1 = (n + 1) / 2;
        ll m2 = n / 2LL;

        if((x + y) % 2 == 0){
            ll p1 = (lin + 1) / 2LL;
            ll p2 = lin / 2LL;

            // cout << p1 << ' ' << p2 << endl;
            ll add = p1 * m1 + p2 * m2;

            add += (y - 1LL) / 2LL + 1;

            cout << add + st1 << endl;
        }else{
            ll p1 = lin / 2LL;
            ll p2 = (lin + 1LL) / 2LL;

            ll add = p1 * m1 + p2 * m2;

            add += (y - 1LL) / 2LL + 1LL;

            cout << add + st2 << endl;
        }
    }
    return 0;
}