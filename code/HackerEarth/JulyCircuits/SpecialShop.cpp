//20, 07, 2018, 13:13:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll f(ll mid, ll n, ll a, ll b){
    ll need = n - mid;

    return mid * mid * a + need * need * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(int i = 0 ; i < t ; i++){
        ll n, a, b;

        cin >> n >> a >> b;   

        ll st = 0, en = n - 1;

        while(en - st > 4){
            ll mid1 = (en + st) / 2;
            ll mid2 = mid1 + 1;
            
            if(f(mid1, n, a, b) > f(mid2, n, a, b)){
                st = mid1;
            }else{
                en = mid2;
            }
        }

        ll best = 1e14;

        for(int i = st ; i <= en ; i++){
            best = min(best, f(i, n, a, b));
        }

        cout << best << endl;
    }

    return 0;
}