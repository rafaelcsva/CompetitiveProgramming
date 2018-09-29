//20, 07, 2018, 11:56:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(5e5 + 10);
ll pref[N];

ld mean(ll value, int t){
    int sz = t + 2;

    return ld(value + pref[t]) / ld(sz);
}

const ld EPS = 0.0000000001L;

ld find_best(ll value, int size){
    if(size == 0){
        return 0.0L;
    }

    int st = 0, en = size - 1;

    ld best = 1e10;

    while(en - st > 4){
        int mid1 = (st + en) / 2;
        int mid2 = (st + en) / 2 + 1;
        ld a = mean(value, mid1);
        ld b = mean(value, mid2);
        
        if(a - b > EPS){
            st = mid1;
        }else{
            en = mid2;
        }
    }

    for(int i = st ; i <= en ; i++){
        best = min(best, mean(value, i));
    }
    
    return value - best;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;

    cin >> q;

    int sz = 0;
    ll last = 0;

    while(q--){
        int t;

        cin >> t;

        if(t == 1){
            ll x;

            cin >> x;
            last = x;
            
            pref[sz] = x;

            if(sz){
                pref[sz] += pref[sz - 1];
            }

            sz++;
        }else{
            cout << fixed << setprecision(10) << find_best(last, sz - 1) << endl;
        }
    }

    return 0;
}