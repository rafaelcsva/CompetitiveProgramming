//12, 01, 2019, 10:42:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;

const int N = int(1e5 + 100);
ll a[N];
ll pref[N], pref_i[N], pref_p[N];
int n, q;
ll resp[N];
pii qu[N];

int m_lower_bound(ll val){
    int r = 1;
    int lo = 1, hi = n;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(a[mid] > val){
            hi = mid - 1;
        }else{
            lo = mid + 1;
            r = mid;
        }
    }

    return r;
}

int m_upper_bound(ll val){
    int r = n;
    int lo = 1, hi = n;
    // cout << "searching for " << val << endl;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(a[mid] < val){
            lo = mid + 1;
        }else{
            r = mid;
            hi = mid - 1;
        }
    }

    return r;
}

bool can(int lo, int hi, ll val){
    int loo = 1;
    int hii = lo;
    int l_taked = n - hi;
    int r = lo + 1;
    ll mdif = abs(a[hi] - val);

    while(loo <= hii){
        int mid = (loo + hii) >> 1;

        ll diff = abs(a[mid] - val);

        if(diff <= mdif){
            r = mid;
            hii = mid - 1;
        }else{
            loo = mid + 1;
        }
    }

    int have = lo - r + 1 + hi - lo;

    return have < l_taked;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        pref[i] = pref[i - 1] + a[i];
        pref_i[i] = pref_i[i - 1];
        pref_p[i] = pref_p[i - 1];

        if(i & 1){
            pref_i[i] += a[i];
        }else{
            pref_p[i] += a[i];
        }
    }

    for(int i = 0 ; i < q ; i++){
        cin >> qu[i].first;
        qu[i].second = i;
    }

    sort(qu, qu + q);

    int hi = n;
    // cout << "aqui!" << endl;
    for(int i = q - 1 ; i >= 0 ; i--){
        ll xi;

        xi = qu[i].first;
        // cout << "processando " << xi << endl;
        if(xi <= a[1]){
            resp[qu[i].second] = pref[n] - pref[n / 2];

            continue;
        }else if(xi >= a[n]){
            if(n & 1){
                resp[qu[i].second] = pref[n] - pref_p[n];
            }else{
                resp[qu[i].second] = pref[n] - pref_i[n];
            }

            continue;
        }

        int lo = m_lower_bound(xi);
        // cout << "Lo = " << lo << endl;
        while(lo < hi && !can(lo, hi, xi)){
            // cout << "hi= " << hi << endl;
            hi--;
        }
        
        int have = n - hi;
        ll sum = 0LL;

        sum = pref[hi] - pref[hi - have];

        int idx = hi - have;

        if(idx & 1){
            sum += pref_p[idx];
        }else{
            sum += pref_i[idx];
        }

        resp[qu[i].second] = pref[n] - sum;
    }

    for(int i = 0 ; i < q; i++){
        cout << resp[i] << endl;
    }

    return 0;
}