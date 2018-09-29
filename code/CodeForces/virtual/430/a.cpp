//19, 07, 2018, 13:22:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll l, r, x, y, k;

    cin >> l >> r >> x >> y >> k;

    ll w = 1;
    ll d = k;

    while(d <= r){
        if(d >= l && w >= x && w <= y){
            cout << "YES" << endl;
            return 0;
        }

        d += k;
        w++;
    }

    cout << "NO" << endl;

    return 0;
}