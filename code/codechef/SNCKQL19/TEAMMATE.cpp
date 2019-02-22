//12, 10, 2018, 19:07:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef unsigned long long ull;

const int N = 1e6 + 100;
ll cnt[N];
ll a[N];
const ll mod = 1e9 + 7;
priority_queue< pii > pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            ll x;

            cin >> x;

            a[i] = x;
            cnt[x]++;
        }

        for(int i = 0 ; i < n ; i++){
            if(cnt[a[i]] == 0)
                continue;

            pq.push({a[i], cnt[a[i]]});
            cnt[a[i]] = 0LL;
        }

        ll tot = 1LL;

        while(!pq.empty()){
            pii u = pq.top();
            pq.pop();
            
            if(u.second > 1){
                tot *= (u.second * (u.second - 1LL)) / 2LL;
                tot %= mod;
                u.second = u.second & 1LL;
            }

            while(u.second){
                pii v = pq.top();
                pq.pop();

                tot *= u.second * v.second;
                tot %= mod;

                if(v.second >= u.second){
                    v.second -= u.second;
                    u.second = 0LL;
                }else{
                    u.second -= v.second;
                    v.second = 0LL;
                }

                if(v.second){
                    pq.push(v);
                }
            }
        }

        cout << tot << endl;

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}