//14, 05, 2018, 19:52:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
const ld PI = 3.141592653589793L;

int main(){
    ll n, m;

    ld h = sqrt(0.75L);
    ld p = 0.25L;
    
    while(cin >> n >> m){
        ll y = sqrt(n);
        pii cn = {y, n - y * y};
        
        y = sqrt(m);

        pii cm = {y, m - y * y};

        if(cn.first > cm.first){
            swap(cn, cm);
        }

        ld d1, d2;

        if(cn.second % 2LL){
            d1 = h - p;
        }else{
            d1 = p;
        }

        if(cm.second % 2LL){
            d2 = p;
        }else{
            d2 = h - p;
        }

        ll difl = cm.first - cn.first;
        
        ld dc = (abs(cn.second + difl - cm.second)) * 0.50L;
        ld dl = (cm.first - cn.first - 1) * 1.0L;
        ld height = dl;
        
        cout << sqrt(height * height + dc * dc) << endl;
    }

    return 0;
}