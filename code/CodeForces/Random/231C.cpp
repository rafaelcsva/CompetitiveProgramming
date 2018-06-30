//26, 06, 2018, 21:01:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll pref[N];
int n;
ll k;
ll x[N];

int binary_search(int st, int en){
    int i = en;
    int r = i;

    while(st <= en){
        int mid = (st + en) / 2;
        ll el = i - mid + 1;

        ll ret = 0LL;

        if(mid){
            ret = pref[mid - 1];
        }

        if(el * x[i] - (pref[i] - ret) <= k){
            en = mid - 1;
            r = mid;
        }else{
            st = mid + 1;
        }
    }

    return i - r + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> x[i];
    }

    sort(x, x + n);

    for(int i = 0 ; i < n ; i++){
        pref[i] = x[i];

        if(i)
            pref[i] += pref[i - 1];
    }

    int best = -1;
    ll number = 0LL;

    for(int i = n - 1; i >= 0 ; i--){
        int resp = binary_search(0, i);
        if(resp >= best){
            best = resp;
            number = x[i];
        }
    }

    cout << best << ' ' << number << endl;

    return 0;
}